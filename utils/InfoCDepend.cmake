if (WIN32)
    set(EXECUTION_PREFIX cmd /c CACHE INTERNAL "__")
else ()
    set(EXECUTION_PREFIX "" CACHE INTERNAL "__")
endif ()

set(Info_Silent No)

function(NumberToHex number output)
    set(chars "0123456789abcdef")
    set(hex "")

    foreach (i RANGE 7)
        math(EXPR nibble "${number} & 15")
        string(SUBSTRING "${chars}" "${nibble}" 1 nibble_hex)
        string(APPEND hex "${nibble_hex}")

        math(EXPR number "${number} >> 4")
    endforeach ()

    string(REGEX REPLACE "(.)(.)" "\\2\\1" hex "${hex}")
    set("${output}" "${hex}" PARENT_SCOPE)
endfunction()

function(StringToCharList str list)
    string(REGEX MATCHALL "(.)" LIST_OUT "${str}")
    set("${list}" "${LIST_OUT}" PARENT_SCOPE)
endfunction()

function(ord chr num)
    if (WIN32)
        execute_process(
                COMMAND ${EXECUTION_PREFIX} "@echo off\
setlocal EnableDelayedExpansion\
set code=0\
if [%1] EQU [] goto END\
set input=%1\
set target=%input:~0,1%\
    for /L %%i in (32, 1, 126) do (\
        cmd /c exit /b %%i\
        set Chr=^!=ExitCodeAscii!\
        if [^!Chr!] EQU [^!target!] set code=%%i & goto END\
    )\
goto :EOF\
:END\
    echo !code!\
endlocal & set errorlevel=%code%" ${chr}
                OUTPUT_VARIABLE RetVal
        )
    else ()
        execute_process(
                COMMAND "LC_CTYPE=C printf '%d' \"'${chr}\"" ${chr}
                OUTPUT_VARIABLE RetVal
        )
    endif ()
    set("${num}" "${RetVal}" PARENT_SCOPE)
endfunction()

function(ASCIIToHex str hex)
    StringToCharList("${str}" chars)
    set(RetVal "")

    foreach (char IN LISTS chars)
        ord(${char} num)
        NumberToHex(${num} out)
        list(APPEND RetVal ${out})
    endforeach ()
    list(TRANSFORM RetVal REPLACE "0+$" "")

    set("${hex}" "${RetVal}" PARENT_SCOPE)
endfunction()

function(GetCompressionMagicNumbers comp mnums)
    if ("${comp}" STREQUAL "gz")                                            # GZ
        set("${mnums}" 1f;8b PARENT_SCOPE)

    elseif ("${comp}" STREQUAL "xz")                                        # XZ
        ASCIIToHex(7zXZ ${comp}_magic)
        set("${mnums}" fd;${${comp}_magic};00 PARENT_SCOPE)

    elseif ("${comp}" STREQUAL "zip")                                      # ZIP
        set("${mnums}" 50;4b;03;04 PARENT_SCOPE)

    elseif ("${comp}" STREQUAL "bz2")                                      # BZ2
        ASCIIToHex(BZh "${comp}_magic")
        set("${mnums}" "${${comp}_magic}" PARENT_SCOPE)

    elseif ("${comp}" STREQUAL "Z")                                          # Z
        set("${mnums}" 1f;9d PARENT_SCOPE)

    elseif ("${comp}" STREQUAL "7z")                                        # 7z
        ASCIIToHex(7z "${comp}_magic")
        set("${mnums}" ${${comp}_magic};bc;af;27;1c PARENT_SCOPE)

    else ()                                                            # fuck-up
        set("${mnums}" No PARENT_SCOPE)
    endif ()
endfunction()

function(GetCompressionPrettyName in_ext out_name)
    if ("${in_ext}" STREQUAL "gz")
        set("${out_name}" "gzip" PARENT_SCOPE)

    elseif ("${in_ext}" STREQUAL "xz")
        set("${out_name}" "xz" PARENT_SCOPE)

    elseif ("${in_ext}" STREQUAL "zip")
        set("${out_name}" "zip" PARENT_SCOPE)

    elseif ("${in_ext}" STREQUAL "7z")
        set("${out_name}" "7zip" PARENT_SCOPE)

    elseif ("${in_ext}" STREQUAL "bz2")
        set("${out_name}" "bzip2" PARENT_SCOPE)

    elseif ("${in_ext}" STREQUAL "Z")
        set("${out_name}" "UNIX compress" PARENT_SCOPE)

    else ()
        set("${out_name}" No PARENT_SCOPE)
    endif ()
endfunction()

function(GetCompressionOfFile in_file out_type out_pretty)
    ## Trying file extension
    string(REGEX MATCH "\\." FILE_HAS_DOT "${in_file}")
    if (${FILE_HAS_DOT})
        string(REGEX REPLACE ".+\\.(\\S*)" "\\1" FILE_EXT)
        if (NOT "${FILE_EXT}" STREQUAL "")
            GetCompressionPrettyName(${FILE_EXT} FILE_C_TYPE)
            if (FILE_C_TYPE) # Found -> Set & Return
                set("${out_type}" "${FILE_EXT}" PARENT_SCOPE)
                set("${out_pretty}" "${FILE_C_TYPE}" PARENT_SCOPE)
                return()
            endif ()
        else ()
            set("${out_type}" No PARENT_SCOPE)
        endif ()
    endif ()

    ## Trying file's magic number
    foreach (comp IN ITEMS gz;xz;zip;7z;bz2;Z)
        unset(_MAGIC)
        GetCompressionMagicNumbers("${comp}" _MAGIC)
        if (_MAGIC)
            list(LENGTH _MAGIC MAGIC_LENGTH)
            string(REPLACE ";" "" MAGIC_NUM ${_MAGIC})
            file(READ "${in_file}" BYTES
                    LIMIT ${MAGIC_LENGTH} HEX)
            if ("${MAGIC_NUM}" STREQUAL "${BYTES}")
                GetCompressionPrettyName(${comp} FILE_C_TYPE)
                set("${out_type}" "${comp}" PARENT_SCOPE)
                set("${out_pretty}" "${FILE_C_TYPE}" PARENT_SCOPE)
                return()
            endif ()
        endif ()
    endforeach ()
endfunction()

function(CompressionType2DecompressCall in_ext out_call)
    if ("${in_ext}" STREQUAL "gz")
        set("${out_call}" "${CMAKE_COMMAND} -E tar xzf $FILE$" PARENT_SCOPE)

    elseif ("${in_ext}" STREQUAL "xz")
        set("${out_call}" "${CMAKE_COMMAND} -E tar xJf $FILE$" PARENT_SCOPE)

    elseif ("${in_ext}" STREQUAL "zip")
        set("${out_call}" "${CMAKE_COMMAND} -E tar xf $FILE$ --format=zip" PARENT_SCOPE)

    elseif ("${in_ext}" STREQUAL "7z")
        set("${out_call}" "${CMAKE_COMMAND} -E tar xf $FILE$ --format=7zip" PARENT_SCOPE)

    elseif ("${in_ext}" STREQUAL "bz2")
        set("${out_call}" "${CMAKE_COMMAND} -E tar xjf $FILE$" PARENT_SCOPE)

    elseif ("${in_ext}" STREQUAL "Z")
        if (WIN32)
            message(FATAL ".Z files are not supported on Windows until further notice")
        endif ()
        set("${out_call}" "tar xZf $FILE$" PARENT_SCOPE)

    else ()
        set("${out_name}" No PARENT_SCOPE)
    endif ()
endfunction()

function(EscapeRegexSequence in_Str out_Regex)
    string(REGEX REPLACE "(.)" "\\\\\\1" out_Str "${in_Str}")
    # Fuck you, this works perfectly fine,
    # as the regex specs say "\<char>" matches any one <char>
    set(${out_Regex} "${out_Str}" PARENT_SCOPE)
endfunction()

function(min in_l in_r out_min)
    if ("${${in_l}}" LESS "${${in_r}}")
        set("${out_min}" "${${in_l}}" PARENT_SCOPE)
    else ()
        set("${out_min}" "${${in_r}}" PARENT_SCOPE)
    endif ()
endfunction()

function(GetLongestMatch in_LHS in_RHS out_Match)
    if ("${in_RHS}" STREQUAL "")
        set("${out_Match}" "${in_LHS}" PARENT_SCOPE)
        return()
    endif ()
    StringToCharList("${in_LHS}" left)
    list(LENGTH left left_l)
    StringToCharList("${in_RHS}" right)
    list(LENGTH right right_l)
    min(left_l right_l shorter)
    math(EXPR indices "${shorter} - 1")

    foreach (i RANGE "${indices}")
        list(GET left ${i} L)
        list(GET right ${i} R)
        if (${L} STREQUAL ${R})
            set(match "${match}${L}")
        else ()
            break()
        endif ()
    endforeach ()
    set("${out_Match}" "${match}" PARENT_SCOPE)
endfunction()

function(Chop io_str in_num)
    string(SUBSTRING ${${io_str}} ${in_num} -1 chopped)
    set("${io_str}" ${chopped} PARENT_SCOPE)
endfunction()

function(StripCommonStart in_Paths out_stripped)
    ## Get longest leading common path
    foreach (path IN LISTS ${in_Paths})
        GetLongestMatch("${path}" "${STRIPPED}" STRIPPED)
    endforeach ()

    ## Remove it
    if (STRIPPED)
        foreach (path IN LISTS ${in_Paths})
            string(LENGTH ${STRIPPED} len)
            Chop(path ${len})
            set(out_paths ${out_paths};${path})
        endforeach ()
    endif ()

    if (out_paths)
        set("${out_stripped}" "${STRIPPED}" PARENT_SCOPE)
        set("${in_Paths}" "${out_paths}" PARENT_SCOPE)
    endif ()
endfunction()

function(DissectPath in_full out_path out_basename)
    if (NOT "${in_full}" MATCHES "/")
        set("${out_path}" "" PARENT_SCOPE)
        set("${out_basename}" "${in_full}" PARENT_SCOPE)
        return()
    endif ()
    string(REGEX REPLACE "/[^/]+$" "/" path ${in_full})
    string(REGEX REPLACE ".*/([^/]+)$" "\\1" base ${in_full})
    set("${out_path}" "${path}" PARENT_SCOPE)
    set("${out_basename}" "${base}" PARENT_SCOPE)
endfunction()

macro(LOG)
    if (${ARGC} EQUAL 2)
        if ("${ARGV0}" STREQUAL "ERROR")
            message(FATAL "${LOG_Error} ${ARGV1}")
        else ()
            message(${ARGV0} "${LOG_Runtime} ${ARGV1}")
        endif ()
    else ()
        message(${ARGV0} "${LOG_${ARGV1}} ${ARGV2}")
    endif ()
endmacro()

function(RegisterLibrary in_name)
    set(DEPENDENCY_NAME "${in_name}")
    string(TOLOWER "${DEPENDENCY_NAME}" DEPENDENCY_DIR)
    set(DEPENDENCY_PATH "${CMAKE_SOURCE_DIR}/libs/${DEPENDENCY_DIR}")
    set(DEPENDENCY_INC "${CMAKE_SOURCE_DIR}/libs/include/${DEPENDENCY_DIR}")

    LOG(STATUS "Registering Library '${DEPENDENCY_NAME}'")
    add_subdirectory("${DEPENDENCY_PATH}" "${CMAKE_BINARY_DIR}/${DEPENDENCY_DIR}")

    LOG(STATUS "Generating required directories")
    if (NOT EXISTS "${DEPENDENCY_PATH}/../include")
        file(MAKE_DIRECTORY "${DEPENDENCY_PATH}/../include")
    endif ()

    if (NOT EXISTS "${DEPENDENCY_INC}")
        file(MAKE_DIRECTORY "${DEPENDENCY_INC}")
    endif ()
    LOG(STATUS "Generating required directories - Done")

    LOG(STATUS "Collecting headers")
    unset(${DEPENDENCY_NAME}_HEADERS_FOUND)
    file(GLOB_RECURSE "${DEPENDENCY_NAME}_HEADERS_FOUND"
            RELATIVE "${DEPENDENCY_PATH}"
            "*.h" "*.hpp" "*.h++" "*.hxx" "*.hh")

    foreach (header IN LISTS "${DEPENDENCY_NAME}_HEADERS_FOUND")
        string(REGEX MATCH "/[Tt]est" Test_Header ${header})
        string(REGEX MATCH "^\\.\\./" Directory_Backstep ${header})
        if (Test_Header OR Directory_Backstep)
            list(REMOVE_ITEM ${DEPENDENCY_NAME}_HEADERS_FOUND ${header})
        endif ()
    endforeach ()

    StripCommonStart(${DEPENDENCY_NAME}_HEADERS_FOUND stripped)
    LOG(STATUS "Collecting headers - Done")

    LOG(STATUS "Copying headers")
    foreach (header IN LISTS "${DEPENDENCY_NAME}_HEADERS_FOUND")
        DissectPath(${header} path file)
        file(COPY "${DEPENDENCY_PATH}/${stripped}${path}${file}"
                DESTINATION "${DEPENDENCY_INC}/${path}")
    endforeach ()
    LOG(STATUS "Copying headers - Done")

    LOG(STATUS "Registering Library '${DEPENDENCY_NAME}' - Done")
endfunction()

function(GetDependency in_name in_link)
    # Pre-Init #################################################################
    ## Log variables
    set(LOG_NAME "[Get-Dependency]")
    set(LOG_PreInit "${LOG_NAME}<Pre-Init>")
    set(LOG_Init "${LOG_NAME}<Init>")
    set(LOG_PostInit "${LOG_NAME}<Post-Init>")
    set(LOG_Runtime "${LOG_NAME}<Runtime>")
    set(LOG_ClearUp "${LOG_NAME}<Clearup>")
    set(LOG_Error "${LOG_NAME}<Error!>")

    # Init #####################################################################
    ## Setting variables for the dependency
    set(DEPENDENCY_NAME "${in_name}")
    string(TOLOWER "${DEPENDENCY_NAME}" DEPENDENCY_DIR)
    file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/libs")
    set(DEPENDENCY_PATH "${CMAKE_SOURCE_DIR}/libs/${DEPENDENCY_DIR}")
    set(DEP_CACHE_FILE "${DEPENDENCY_PATH}/../libs")

    ## Checking cached libs
    if (EXISTS "${DEP_CACHE_FILE}")
        file(READ "${DEP_CACHE_FILE}" CACHED_DEPENDENCIES)
    endif ()

    foreach (DEP IN LISTS CACHED_DEPENDENCIES)
        if ("${DEP}" STREQUAL "${DEPENDENCY_NAME}")
            LOG(STATUS "Library '${DEPENDENCY_NAME}' Already Installed")
            RegisterLibrary("${DEP}")
            return()
        endif ()
    endforeach ()


    ## Git exists
    LOG(STATUS Init "Searching for Git")
    find_package(Git)
    if (NOT GIT_FOUND)
        LOG(STATUS Init "Searching for Git - Failure")
        LOG(ERROR "Usage requires a git installation findable by CMake until further notice")
    endif ()
    LOG(STATUS Init "Searching for Git - Success")

    # Post-Init ################################################################
    ## Checking for git repo
    LOG(STATUS PostInit "Checking for git repository")
    execute_process(
            COMMAND ${EXECUTION_PREFIX} "${GIT_EXECUTABLE}" ls-remote "${in_link}"
            OUTPUT_SILENT ERROR_SILENT
            RESULT_VARIABLE Remote_Legal
    )
    if ("${Remote_Legal}" EQUAL 0)
        set(DEPENDENCY_GIT_REPO Yes)
        LOG(STATUS PostInit "Checking for git repository - Success")
    else ()
        set(DEPENDENCY_GIT_REPO No)
        LOG(STATUS PostInit "Checking for git repository - Failure")
    endif ()

    # Runtime ##################################################################
    ## Downloading Sources
    LOG(STATUS "Downloading dependency '${DEPENDENCY_NAME}'")
    if (${DEPENDENCY_GIT_REPO})
        LOG(STATUS "Cloning git repository")
        if (NOT EXISTS "${DEPENDENCY_PATH}")
            execute_process(
                    COMMAND ${EXECUTION_PREFIX} "${GIT_EXECUTABLE}" clone "${in_link}" "${DEPENDENCY_PATH}"
            )
            LOG(STATUS "Cloning git repository - Done")
        else ()
            LOG(STATUS "Cloning git repository - Cached")
        endif ()
    else ()
        LOG(STATUS "Downloading file")

        if (EXISTS "${DEPENDENCY_PATH}")
            LOG(STATUS "Creating directory")
            file(MAKE_DIRECTORY "${DEPENDENCY_PATH}")
            LOG(STATUS "Creating directory - Done")
        endif ()

        string(REGEX REPLACE ".+/([^/]+)/?" "\\1" DEP_FILE "${in_link}")
        if (NOT EXISTS "${DEPENDENCY_PATH}/${DEP_FILE}")
            file(DOWNLOAD "${in_link}" "${DEPENDENCY_PATH}/${DEP_FILE}")
            LOG(STATUS "Downloading file - Done")
        else ()
            LOG(STATUS "Downloading file - Cached")
        endif ()

        LOG(STATUS "Extracting archive")
        LOG(STATUS "Figuring out compression type")
        GetCompressionOfFile("${DEPENDENCY_PATH}/${DEP_FILE}" DEP_COMP_TYPE DEP_COMP_TYPE_NAME)
        LOG(STATUS "Figuring out compression type - Done")

        CompressionType2DecompressCall(${DEP_COMP_TYPE} _DECOMPRESS_CALL)
        string(REPLACE "$FILE$" "${DEP_FILE}" DECOMPRESS_CALL ${_DECOMPRESS_CALL})

        execute_process(
                COMMAND ${EXECUTION_PREFIX} ${DECOMPRESS_CALL}
                WORKING_DIRECTORY "${DEPENDENCY_PATH}"
        )

        LOG(STATUS "Extracting archive - Done")
    endif ()
    LOG(STATUS "Downloading dependency '${DEPENDENCY_NAME}' - Done")

    RegisterLibrary(${DEPENDENCY_NAME})

    file(APPEND "${DEPENDENCY_PATH}/../libs" ";${DEPENDENCY_NAME}")

    # Multiple calls to this won't hurt, right?
    include_directories("${PROJECT_SOURCE_DIR}/libs/include")
endfunction()
