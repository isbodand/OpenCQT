# Testing -> Boost.Test
message(STATUS "[LibStarch] Checking for Boost.Test for testing")
find_package(Boost QUIET COMPONENTS unit_test_framework)
if (Boost_FOUND)
    message(STATUS "[LibStarch] Found Boost.Test, enabling testing")
    enable_testing()
    add_definitions(-DBOOST_TEST_DYN_LINK)

    set(Test_HEADERS
            Test_Testing.hpp
            Test_ValSubtree.hpp
            Test_CExpression.hpp
            Test_Utils.hpp
            )

    foreach (case ${Test_HEADERS})
        set(Test_TEST_CASES "${Test_TEST_CASES}
#include \"${case}\"")
    endforeach ()

    configure_file(
            "${PROJECT_SOURCE_DIR}/test/testmain.cpp.in"
            "${PROJECT_SOURCE_DIR}/test/testmain.cpp"
    )

    foreach (file ${LibStarch_HEADERS})
        set(LibStarch_FILES "../${file}")
    endforeach ()

    add_executable(sch_test ${Test_HEADERS} testmain.cpp ${LibStarch_FILES})
    target_link_libraries(sch_test sch)
    set_target_properties(sch_test PROPERTIES LINKER_LANGUAGE CXX)
else ()
    message(STATUS "[LibStarch] Could not find Boost.Test, disabling testing")
endif ()
