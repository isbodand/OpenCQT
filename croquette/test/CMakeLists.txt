# Testing -> Boost.Test
message(STATUS "[Croquette] Checking for Boost.Test for testing")
find_package(Boost QUIET COMPONENTS unit_test_framework)
if (Boost_FOUND)
    message(STATUS "[Croquette] Found Boost.Test, enabling testing")
    enable_testing()
    add_definitions(-DBOOST_TEST_DYN_LINK)

    set(Test_HEADERS
            Test_Testing.hpp
            Test_Version.hpp
            Test_Casts.hpp
            Test_AnyArchetype.hpp
            Test_ArrayArchetype.hpp
            Test_ScalarArchetype.hpp
            Test_HashArchetype.hpp
            Test_ArchetypeUtils.hpp
            )

    foreach (case ${Test_HEADERS})
        set(Test_TEST_CASES "${Test_TEST_CASES}
#include \"${case}\"")
    endforeach ()

    configure_file(
            "${PROJECT_SOURCE_DIR}/test/testmain.cpp.in"
            "${PROJECT_SOURCE_DIR}/test/testmain.cpp"
    )

    foreach (file ${libCroquette_HEADERS})
        set(Croquette_FILES "../${file}")
    endforeach ()

    add_executable(cqt_test ${Test_HEADERS} testmain.cpp ${Croquette_FILES})
    target_link_libraries(cqt_test cqt)
    set_target_properties(cqt_test PROPERTIES LINKER_LANGUAGE CXX)
else ()
    message(STATUS "[Croquette] Could not find Boost.Test, disabling testing")
endif ()
