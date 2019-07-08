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
        AstNode.hpp
        AstRoot.hpp
        AstCode.hpp
        AstInnerCode.hpp
        cexpr/impl/CExpressionImpl.hpp
        cexpr/impl/AdditionExpressionImpl.hpp
        cexpr/impl/SubtractionExpressionImpl.hpp
        cexpr/impl/MultiplicationExpressionImpl.hpp
        cexpr/impl/DivisionExpressionImpl.hpp
        cexpr/impl/ModuloExpressionImpl.hpp
        cexpr/impl/EqualityExpressionImpl.hpp
        cexpr/impl/LessOrEqualExpressionImpl.cpp
        cexpr/impl/InequalityExpressionImpl.hpp
        cexpr/impl/GreaterThanExpressionImpl.hpp
        cexpr/impl/LessThanExpressionImpl.hpp
        cexpr/impl/GreaterOrEqualExpressionImpl.hpp
        cexpr/impl/LessOrEqualExpressionImpl.hpp
        cexpr/impl/ValueExpressionImpl.hpp
        cexpr/impl/NegateExpressionImpl.hpp
        cexpr/impl/TernaryExpressionImpl.hpp
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
        cexpr/DivisionExpression.cpp cexpr/DivisionExpression.hpp cexpr/EqualityExpression.cpp cexpr/EqualityExpression.hpp cexpr/Makeable.cpp cexpr/Makeable.hpp cexpr/GreaterOrEqualExpression.cpp cexpr/GreaterOrEqualExpression.hpp cexpr/GreaterThanExpression.cpp cexpr/GreaterThanExpression.hpp cexpr/InequalityExpression.cpp cexpr/InequalityExpression.hpp cexpr/LessOrEqualExpression.cpp cexpr/LessOrEqualExpression.hpp cexpr/ModuloExpression.cpp cexpr/ModuloExpression.hpp cexpr/MultiplicationExpression.cpp cexpr/MultiplicationExpression.hpp cexpr/NegateExpression.cpp cexpr/NegateExpression.hpp cexpr/SubtractionExpression.cpp cexpr/SubtractionExpression.hpp cexpr/TernaryExpression.cpp cexpr/TernaryExpression.hpp cexpr/ValueExpression.cpp cexpr/ValueExpression.hpp CondNode.cpp CondNode.hpp)

set(LibStarch_SOURCES
        Utils.cpp
        Visitor.cpp
        Visitable.cpp
        AstNode.cpp
        AstRoot.cpp
        AstCode.cpp
        AstInnerCode.cpp
        cexpr/impl/CExpressionImpl.cpp
        cexpr/impl/AdditionExpressionImpl.cpp
        cexpr/impl/SubtractionExpressionImpl.cpp
        cexpr/impl/MultiplicationExpressionImpl.cpp
        cexpr/impl/DivisionExpressionImpl.cpp
        cexpr/impl/ModuloExpressionImpl.cpp
        cexpr/impl/EqualityExpressionImpl.cpp
        cexpr/impl/InequalityExpressionImpl.cpp
        cexpr/impl/GreaterThanExpressionImpl.cpp
        cexpr/impl/LessThanExpressionImpl.cpp
        cexpr/impl/GreaterOrEqualExpressionImpl.cpp
        cexpr/impl/ValueExpressionImpl.cpp
        cexpr/impl/NegateExpressionImpl.cpp
        cexpr/impl/TernaryExpressionImpl.cpp
        cexpr/CExpression.cpp
        cexpr/AdditionExpression.cpp
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

add_library(sch STATIC ${LibStarch_HEADERS} ${LibStarch_SOURCES} cexpr/LessThanExpression.cpp cexpr/LessThanExpression.hpp)
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
