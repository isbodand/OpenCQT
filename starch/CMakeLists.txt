cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 20)
project(LibStarch)


set(LibStarch_VERSION_MAJOR 0)
set(LibStarch_VERSION_MINOR 1)
set(LibStarch_VERSION_NOTE β)
set(LibStarch_VERSION "${OpenCQT_VERSION_MAJOR}.${OpenCQT_VERSION_MINOR}-${LibStarch_VERSION_NOTE}")

find_package(Boost COMPONENTS math_tr1)

if (Boost_FOUND)
    set(CQT_BOOST_MATH_FOUND 1)
else ()
    set(CQT_BOOST_MATH_FOUND 0)
endif ()
configure_file(
        "${PROJECT_SOURCE_DIR}/Utils.cpp.in"
        "${PROJECT_SOURCE_DIR}/Utils.cpp"
)

configure_file(
        "${PROJECT_SOURCE_DIR}/versioning.hpp.in"
        "${PROJECT_SOURCE_DIR}/versioning.hpp"
)

set(LibStarch_HEADERS versioning.hpp
        Utils.hpp
        Visitor.hpp
        Visitable.hpp
        CondNode.hpp
        AstNode.hpp
        AstRoot.hpp
        AstCode.hpp
        AstInnerCode.hpp
        cexpr/impl/CExpressionImpl.hpp
        cexpr/impl/AdditionExpressionImpl.hpp
        cexpr/SubtractionExpression.hpp
        cexpr/MultiplicationExpression.hpp
        cexpr/DivisionExpression.hpp
        cexpr/ModuloExpression.hpp
        cexpr/EqualityExpression.hpp
        cexpr/LessOrEqualExpression.cpp
        cexpr/InequalityExpression.hpp
        cexpr/GreaterThanExpression.hpp
        cexpr/LessThanExpression.hpp
        cexpr/GreaterOrEqualExpression.hpp
        cexpr/LessOrEqualExpression.hpp
        cexpr/ValueExpression.hpp
        cexpr/NegateExpression.hpp
        cexpr/TernaryExpression.hpp
        cexpr/help/Leftable.hpp
        cexpr/help/Rightable.hpp
        cexpr/help/Conditionable.hpp
        val_subtrees/ValNode.hpp
        val_subtrees/ValId.hpp
        val_subtrees/ValText.hpp
        val_subtrees/ValNumber.hpp
        val_subtrees/ValExpr.hpp
        codepart/AstCodePart.hpp
        codepart/AstOperation.hpp
        codepart/loop/AstLoop.hpp
        codepart/loop/AstForLoop.hpp
        codepart/loop/AstWhileLoop.hpp
        codepart/loop/AstDoLoop.hpp
        codepart/AstExtendedCodePart.hpp
        algorithm/XmlPrinter.hpp
        cexpr/CExpression.hpp
        cexpr/AdditionExpression.hpp
        )

set(LibStarch_SOURCES
        Utils.cpp
        Visitor.cpp
        Visitable.cpp
        CondNode.cpp
        AstNode.cpp
        AstRoot.cpp
        AstCode.cpp
        AstInnerCode.cpp
        cexpr/impl/CExpressionImpl.cpp
        cexpr/impl/AdditionExpressionImpl.cpp
        cexpr/SubtractionExpression.cpp
        cexpr/MultiplicationExpression.cpp
        cexpr/DivisionExpression.cpp
        cexpr/ModuloExpression.cpp
        cexpr/EqualityExpression.cpp
        cexpr/InequalityExpression.cpp
        cexpr/GreaterThanExpression.cpp
        cexpr/LessThanExpression.cpp
        cexpr/GreaterOrEqualExpression.cpp
        cexpr/ValueExpression.cpp
        cexpr/NegateExpression.cpp
        cexpr/TernaryExpression.cpp
        cexpr/CExpression.cpp
        cexpr/AdditionExpression.cpp
        cexpr/help/Leftable.cpp
        cexpr/help/Rightable.cpp
        cexpr/help/Conditionable.cpp
        val_subtrees/ValNode.cpp
        val_subtrees/ValId.cpp
        val_subtrees/ValText.cpp
        val_subtrees/ValNumber.cpp
        val_subtrees/ValExpr.cpp
        codepart/AstCodePart.cpp
        codepart/AstOperation.cpp
        codepart/loop/AstLoop.cpp
        codepart/loop/AstForLoop.cpp
        codepart/loop/AstWhileLoop.cpp
        codepart/loop/AstDoLoop.cpp
        codepart/AstExtendedCodePart.cpp
        algorithm/XmlPrinter.cpp
        )

#set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -fpermissive) # enable funky-mode

add_library(sch STATIC ${LibStarch_HEADERS} ${LibStarch_SOURCES})
add_library(starch SHARED ${LibStarch_HEADERS} ${LibStarch_SOURCES})
set_target_properties(sch PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(starch PROPERTIES LINKER_LANGUAGE CXX)


add_executable(manual_test main.cpp ${LibStarch_FILES})
target_link_libraries(manual_test sch)
set_target_properties(manual_test PROPERTIES LINKER_LANGUAGE CXX)


add_subdirectory(test)

set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")
if (WIN32 AND NOT CYGWIN)
    set(DEF_INSTALL_CMAKE_DIR CMake)
else ()
    set(DEF_INSTALL_CMAKE_DIR lib/CMake/LibStarch)
endif ()
set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation directory for CMake files")

foreach (header ${LibStarch_HEADERS})
    # Dynamic library headers
    get_target_property(pub croquette PUBLIC_HEADER)
    if ("${pub}" STREQUAL "pub-NOTFOUND")
        set_target_properties(croquette PROPERTIES PUBLIC_HEADER "${header}")
    else ()
        set_target_properties(croquette PROPERTIES PUBLIC_HEADER "${header};${pub}")
    endif ()
    # Static library headers
    get_target_property(pub cqt PUBLIC_HEADER)
    if ("${pub}" STREQUAL "pub-NOTFOUND")
        set_target_properties(cqt PROPERTIES PUBLIC_HEADER "${header}")
    else ()
        set_target_properties(cqt PROPERTIES PUBLIC_HEADER "${header};${pub}")
    endif ()
endforeach ()

install(TARGETS croquette EXPORT LibStarchConfig
        RUNTIME DESTINATION ${INSTALL_BIN_DIR}
        LIBRARY DESTINATION ${INSTALL_LIB_DIR}
        PUBLIC_HEADER DESTINATION ${INSTALL_INCLUDE_DIR}
        )
install(TARGETS cqt EXPORT LibStarchConfig
        RUNTIME DESTINATION ${INSTALL_BIN_DIR}
        ARCHIVE DESTINATION ${INSTALL_LIB_DIR}/static
        )
install(EXPORT LibStarchConfig DESTINATION ${INSTALL_CMAKE_DIR})
