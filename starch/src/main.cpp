//
// Created by bodand on 2019-07-01.
//

#include <iostream>

#include "AstRoot.hpp"
#include "AstCode.hpp"
#include "AstInnerCode.hpp"
#include "algorithm/XmlPrinter.hpp"

#include "val_subtrees/ValNumber.hpp"
#include "val_subtrees/ValText.hpp"
#include "val_subtrees/ValId.hpp"
#include "val_subtrees/ValExpr.hpp"

#include "cexpr/impl/AdditionExpressionImpl.hpp"
#include "cexpr/impl/TernaryExpressionImpl.hpp"
#include "cexpr/impl/LessThanExpressionImpl.hpp"
#include "cexpr/impl/EqualityExpressionImpl.hpp"
#include "cexpr/impl/GreaterOrEqualExpressionImpl.hpp"
#include "cexpr/impl/MultiplicationExpressionImpl.hpp"
#include "cexpr/impl/DivisionExpressionImpl.hpp"

#include "codepart/AstOperation.hpp"
#include "codepart/loop/AstForLoop.hpp"
#include "codepart/def/AstMacroDefinition.hpp"

int main() {
    using namespace LibStarch;
    using namespace Utils;
    using namespace std::literals;

    ASTRoot root(ASTCode{
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
         )),
         // !{{[$! < 6]} +.{$|{32}}#{$!}}
         std::static_pointer_cast<ASTExtendedCodePart>(mkPtr<ASTForLoop>(
              CondNode(
                   LessThanExpression::make(
                        ValID("$!"s),
                        ValNumber(6)
                   )
              ),
              ASTInnerCode{
                   std::static_pointer_cast<ASTCodePart>(mkPtr<ASTOperation>(
                        Impl::instPlus
                   )),
                   std::static_pointer_cast<ASTCodePart>(mkPtr<ASTOperation>(
                        Impl::instPrint,
                        mkPtr<ValID>("$!"s),
                        TypeCtor(Impl::typeCharScalar,
                                 new ValNumber(32))
                   ))
              }
         )),
         // !{{[$! < 6]} +%{say}#{$!}}
         std::static_pointer_cast<ASTExtendedCodePart>(mkPtr<ASTForLoop>(
              CondNode(
                   LessThanExpression::make(
                        ValID("$!"s),
                        ValNumber(6)
                   )
              ),
              ASTInnerCode{
                   std::static_pointer_cast<ASTCodePart>(mkPtr<ASTOperation>(
                        Impl::instPlus
                   )),
                   std::static_pointer_cast<ASTCodePart>(mkPtr<ASTOperation>(
                        ValID("say"s),
                        std::vector<std::string>()
                   ))
              }
         )),
         std::static_pointer_cast<ASTExtendedCodePart>(mkPtr<ASTMacroDefinition>(
              ValID("say"),
              ".{$|{32}}"s,
              std::vector<std::string>()
         ))
    });

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
