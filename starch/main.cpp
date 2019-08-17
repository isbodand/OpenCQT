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
#include "val_subtrees/ValExpr.hpp"
#include "cexpr/impl/AdditionExpressionImpl.hpp"
#include "cexpr/impl/TernaryExpressionImpl.hpp"
#include "cexpr/impl/EqualityExpressionImpl.hpp"
#include "cexpr/impl/GreaterOrEqualExpressionImpl.hpp"
#include "cexpr/impl/MultiplicationExpressionImpl.hpp"
#include "cexpr/impl/DivisionExpressionImpl.hpp"
#include "codepart/AstOperation.hpp"

int main() {
    using namespace LibStarch;
    using namespace Utils;

    ASTRoot root(ASTCode({
                                 // >#{[((1/3)=="42")]?"1":(((6*7)>="45")+"4")}
                                 std::static_pointer_cast<ASTExtendedCodePart>(mkPtr<ASTOperation>(
                                         Impl::instStepForward,
                                         mkPtr<ValExpr>(
                                                 TernaryExpression::make(
                                                         ValText("1"),
                                                         ValExpr(
                                                                 AdditionExpression::make(
                                                                         ValExpr(
                                                                                 GreaterOrEqualExpression::make(
                                                                                         ValExpr(
                                                                                                 MultiplicationExpression::make(
                                                                                                         ValNumber(6),
                                                                                                         ValNumber(7)
                                                                                                 )
                                                                                         ),
                                                                                         ValText("45")
                                                                                 )
                                                                         ),
                                                                         ValText("4")
                                                                 )),
                                                         std::optional<CondNode>(
                                                                 EqualityExpression::make(
                                                                         ValExpr(
                                                                                 DivisionExpression::make(
                                                                                         ValNumber(1),
                                                                                         ValNumber(3)
                                                                                 )
                                                                         ),
                                                                         ValText("42")
                                                                 )
                                                         )
                                                 )
                                         )
                                 )),
                                 // +#{"0"+2}
                                 std::static_pointer_cast<ASTExtendedCodePart>(mkPtr<ASTOperation>(
                                         Impl::instPlus,
                                         mkPtr<ValExpr>(
                                                 AdditionExpression::make(
                                                         ValText("0"),
                                                         ValNumber(2)
                                                 )
                                         )
                                 ))
                         }));

    Algorithm::XMLPrinter xmlPrinter;
    try {
        xmlPrinter.visit(root);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    if (xmlPrinter)
        std::cout << xmlPrinter.getXml() << std::endl;

    return 0;
}
