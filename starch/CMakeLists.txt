cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
project(LibStarch)


set(LibStarch_VERSION_MAJOR 0)
set(LibStarch_VERSION_MINOR 1)
set(LibStarch_VERSION_NOTE β)
set(LibStarch_VERSION "${OpenCQT_VERSION_MAJOR}.${OpenCQT_VERSION_MINOR}-${LibStarch_VERSION_NOTE}")

string(TIMESTAMP LibStarch_VERSION_BUILD_DATE "%Y-%m-%d at %H:%M:%S (%s)" UTC)

include(utils/load_libs.cmake)

configure_file(
        "${PROJECT_SOURCE_DIR}/src/Utils.cpp.in"
        "${PROJECT_SOURCE_DIR}/src/Utils.cpp"
)

configure_file(
        "${PROJECT_SOURCE_DIR}/src/versioning.hpp.in"
        "${PROJECT_SOURCE_DIR}/src/versioning.hpp"
)

set(LibStarch_HEADERS
        src/versioning.hpp
        src/Utils.hpp
        src/Visitor.hpp
        src/Visitable.hpp
        src/AstNode.hpp
        src/AstRoot.hpp
        src/AstCode.hpp
        src/AstInnerCode.hpp
        src/CondNode.hpp
        # Classes for the Val* subtrees
        src/val_subtrees/ValNode.hpp
        src/val_subtrees/ValId.hpp
        src/val_subtrees/ValText.hpp
        src/val_subtrees/ValNumber.hpp
        src/val_subtrees/ValExpr.hpp
        # Classes for parts of (inner)?code
        src/codepart/AstCodePart.hpp
        src/codepart/AstOperation.hpp
        src/codepart/loop/AstLoop.hpp
        src/codepart/loop/AstForLoop.hpp
        src/codepart/loop/AstWhileLoop.hpp
        src/codepart/loop/AstDoLoop.hpp
        src/codepart/AstExtendedCodePart.hpp
        src/codepart/def/AstDefinition.hpp
        src/codepart/def/AstSubDefinition.hpp
        src/codepart/def/AstMacroDefinition.hpp
        # C expressions & Impl
        src/cexpr/CExpression.hpp
        src/cexpr/AdditionExpression.hpp
        src/cexpr/DivisionExpression.hpp
        src/cexpr/EqualityExpression.hpp
        src/cexpr/Makeable.hpp
        src/cexpr/GreaterOrEqualExpression.hpp
        src/cexpr/GreaterThanExpression.hpp
        src/cexpr/InequalityExpression.hpp
        src/cexpr/LessOrEqualExpression.hpp
        src/cexpr/ModuloExpression.hpp
        src/cexpr/MultiplicationExpression.hpp
        src/cexpr/NegateExpression.hpp
        src/cexpr/TernaryExpression.hpp
        src/cexpr/SubtractionExpression.hpp
        src/cexpr/ValueExpression.hpp
        src/cexpr/LessThanExpression.hpp
        src/cexpr/impl/CExpressionImpl.hpp
        src/cexpr/impl/AdditionExpressionImpl.hpp
        src/cexpr/impl/SubtractionExpressionImpl.hpp
        src/cexpr/impl/MultiplicationExpressionImpl.hpp
        src/cexpr/impl/DivisionExpressionImpl.hpp
        src/cexpr/impl/ModuloExpressionImpl.hpp
        src/cexpr/impl/EqualityExpressionImpl.hpp
        src/cexpr/impl/LessOrEqualExpressionImpl.cpp
        src/cexpr/impl/InequalityExpressionImpl.hpp
        src/cexpr/impl/GreaterThanExpressionImpl.hpp
        src/cexpr/impl/LessThanExpressionImpl.hpp
        src/cexpr/impl/GreaterOrEqualExpressionImpl.hpp
        src/cexpr/impl/LessOrEqualExpressionImpl.hpp
        src/cexpr/impl/ValueExpressionImpl.hpp
        src/cexpr/impl/NegateExpressionImpl.hpp
        src/cexpr/impl/TernaryExpressionImpl.hpp
        # Algorithm implementations used by the
        # compiler on the AST
        src/algorithm/XmlPrinter.hpp
        src/algorithm/LitEval.hpp
        )

set(LibStarch_SOURCES
        src/Utils.cpp
        src/Visitor.cpp
        src/Visitable.cpp
        src/AstNode.cpp
        src/AstRoot.cpp
        src/AstCode.cpp
        src/AstInnerCode.cpp
        src/CondNode.cpp
        # Classes for the Val* subtrees
        src/val_subtrees/ValNode.cpp
        src/val_subtrees/ValId.cpp
        src/val_subtrees/ValText.cpp
        src/val_subtrees/ValNumber.cpp
        src/val_subtrees/ValExpr.cpp
        # Classes for parts of (inner)?code
        src/codepart/AstCodePart.cpp
        src/codepart/AstOperation.cpp
        src/codepart/loop/AstLoop.cpp
        src/codepart/loop/AstForLoop.cpp
        src/codepart/loop/AstWhileLoop.cpp
        src/codepart/loop/AstDoLoop.cpp
        src/codepart/AstExtendedCodePart.cpp
        src/codepart/def/AstDefinition.cpp
        src/codepart/def/AstSubDefinition.cpp
        src/codepart/def/AstMacroDefinition.cpp
        # C expressions & Impl
        src/cexpr/CExpression.cpp
        src/cexpr/AdditionExpression.cpp
        src/cexpr/DivisionExpression.cpp
        src/cexpr/EqualityExpression.cpp
        src/cexpr/Makeable.cpp
        src/cexpr/GreaterOrEqualExpression.cpp
        src/cexpr/GreaterThanExpression.cpp
        src/cexpr/InequalityExpression.cpp
        src/cexpr/LessOrEqualExpression.cpp
        src/cexpr/ModuloExpression.cpp
        src/cexpr/MultiplicationExpression.cpp
        src/cexpr/NegateExpression.cpp
        src/cexpr/SubtractionExpression.cpp
        src/cexpr/TernaryExpression.cpp
        src/cexpr/ValueExpression.cpp
        src/cexpr/LessThanExpression.cpp
        src/cexpr/impl/CExpressionImpl.cpp
        src/cexpr/impl/AdditionExpressionImpl.cpp
        src/cexpr/impl/SubtractionExpressionImpl.cpp
        src/cexpr/impl/MultiplicationExpressionImpl.cpp
        src/cexpr/impl/DivisionExpressionImpl.cpp
        src/cexpr/impl/ModuloExpressionImpl.cpp
        src/cexpr/impl/EqualityExpressionImpl.cpp
        src/cexpr/impl/InequalityExpressionImpl.cpp
        src/cexpr/impl/GreaterThanExpressionImpl.cpp
        src/cexpr/impl/LessThanExpressionImpl.cpp
        src/cexpr/impl/GreaterOrEqualExpressionImpl.cpp
        src/cexpr/impl/ValueExpressionImpl.cpp
        src/cexpr/impl/NegateExpressionImpl.cpp
        src/cexpr/impl/TernaryExpressionImpl.cpp
        # Algorithm implementations used by the
        # compiler on the AST
        src/algorithm/XmlPrinter.cpp
        src/algorithm/LitEval.cpp
        )

#set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -fpermissive) # enable funky-mode

add_library(sch STATIC ${LibStarch_HEADERS} ${LibStarch_SOURCES})
add_library(starch SHARED ${LibStarch_HEADERS} ${LibStarch_SOURCES})
target_link_libraries(sch tinyxml2)
target_link_libraries(starch tinyxml2)
set_target_properties(sch PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(starch PROPERTIES LINKER_LANGUAGE CXX)


add_executable(manual_test src/main.cpp ${LibStarch_FILES})
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
        set_target_properties(starch PROPERTIES PUBLIC_HEADER "${header}")
    else ()
        set_target_properties(starch PROPERTIES PUBLIC_HEADER "${header};${pub}")
    endif ()
    # Static library headers
    get_target_property(pub cqt PUBLIC_HEADER)
    if ("${pub}" STREQUAL "pub-NOTFOUND")
        set_target_properties(sch PROPERTIES PUBLIC_HEADER "${header}")
    else ()
        set_target_properties(sch PROPERTIES PUBLIC_HEADER "${header};${pub}")
    endif ()
endforeach ()

install(TARGETS starch EXPORT LibStarchConfig
        RUNTIME DESTINATION ${INSTALL_BIN_DIR}
        LIBRARY DESTINATION ${INSTALL_LIB_DIR}
        PUBLIC_HEADER DESTINATION ${INSTALL_INCLUDE_DIR}/starch
        )
install(TARGETS sch EXPORT LibSchConfig
        RUNTIME DESTINATION ${INSTALL_BIN_DIR}
        ARCHIVE DESTINATION ${INSTALL_LIB_DIR}/static
        PUBLIC_HEADER DESTINATION ${INSTALL_INCLUDE_DIR}/starch
        )
install(EXPORT LibStarchConfig DESTINATION ${INSTALL_CMAKE_DIR})
install(EXPORT LibSchConfig DESTINATION ${INSTALL_CMAKE_DIR})
