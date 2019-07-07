//
// Created by bodand on 2019-07-01.
//

#include <iostream>

#include "AstRoot.hpp"
#include "AstCode.hpp"
#include "algorithm/XmlPrinter.hpp"
#include "Utils.hpp"
#include "val_subtrees/ValNumber.hpp"
#include "val_subtrees/ValText.hpp"
#include "cexpr/impl/AdditionExpressionImpl.hpp"
#include "cexpr/TernaryExpression.hpp"
#include "cexpr/EqualityExpression.hpp"
#include "cexpr/GreaterOrEqualExpression.hpp"
#include "cexpr/MultiplicationExpression.hpp"
#include "cexpr/DivisionExpression.hpp"
#include "codepart/AstOperation.hpp"

int main() {
    using namespace LibStarch;
    using namespace Utils;

    ASTRoot root(ASTCode({
//                                 std::static_pointer_cast<ASTExtendedCodePart>(mkPtr<ASTOperation>(
//                                         Impl::instStepForward,
//                                         ValExpr(TernaryExpression(
//                                                 ValText("1"),
//                                                 ValExpr(AdditionExpressionImpl(
//                                                         ValExpr(GreaterOrEqualExpression(
//                                                                 ValExpr(MultiplicationExpression(
//                                                                         ValNumber(6),
//                                                                         ValNumber(7)
//                                                                         ),
//                                                                         nullptr
//                                                                 ),
//                                                                 ValText("45")
//                                                         ), nullptr),
//                                                         ValText("4")
//                                                 ), nullptr),
//                                                 CondNode(
//                                                         EqualityExpression(
//                                                                 ValExpr(DivisionExpression(
//                                                                         ValNumber(1),
//                                                                         ValNumber(3)
//                                                                 ), nullptr),
//                                                                 ValText("42")
//                                                         )
//                                                 )), nullptr),
//                                         std::nullopt)),
                                 std::static_pointer_cast<ASTExtendedCodePart>(
                                         mkPtr<ASTOperation>(
                                                 Impl::instPlus,
                                                 mkPtr<ValExpr>(
                                                         std::move(
                                                                 AdditionExpressionImpl(
                                                                         ValText("0"),
                                                                         ValNumber(2)
                                                                 )
                                                         ),
                                                         nullptr
                                                 ),
                                                 std::nullopt
                                         )
                                 )
                         }));

    Algorithm::XMLPrinter xmlPrinter;
    xmlPrinter.visit(root);
    std::cout << xmlPrinter.getXml() << std::endl;

    return 0;
}
