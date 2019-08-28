//
// Created by bodand on 2019-07-01.
//

#include <sstream>
#include <optional>
#include "XmlPrinter.hpp"

// Codes
#include "../AstCode.hpp"
#include "../AstInnerCode.hpp"

// Code parts
#include "../codepart/AstOperation.hpp"
#include "../codepart/loop/AstDoLoop.hpp"
#include "../codepart/loop/AstForLoop.hpp"
#include "../codepart/loop/AstWhileLoop.hpp"
#include "../codepart/def/AstMacroDefinition.hpp"
#include "../codepart/def/AstSubDefinition.hpp"

// Val subtree
#include "../val_subtrees/ValText.hpp"
#include "../val_subtrees/ValNumber.hpp"
#include "../val_subtrees/ValExpr.hpp"
#include "../val_subtrees/ValId.hpp"

// C-Expressions
#include "../cexpr/AdditionExpression.hpp"
#include "../cexpr/SubtractionExpression.hpp"
#include "../cexpr/MultiplicationExpression.hpp"
#include "../cexpr/DivisionExpression.hpp"
#include "../cexpr/ModuloExpression.hpp"
#include "../cexpr/ValueExpression.hpp"
#include "../cexpr/NegateExpression.hpp"
#include "../cexpr/TernaryExpression.hpp"
#include "../cexpr/EqualityExpression.hpp"
#include "../cexpr/InequalityExpression.hpp"
#include "../cexpr/GreaterThanExpression.hpp"
#include "../cexpr/GreaterOrEqualExpression.hpp"
#include "../cexpr/LessThanExpression.hpp"
#include "../cexpr/LessOrEqualExpression.hpp"
#include "../codepart/def/AstMacroDefinition.hpp"
#include "../codepart/def/AstSubDefinition.hpp"

namespace xml = tinyxml2;

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTRoot& root) {
    lastElem = doc.NewElement("cqt:program");
    doc.InsertEndChild(lastElem);
    root.getCode().accept(*this);
    set = true;
}

std::string LibStarch::Algorithm::XMLPrinter::getXml() const {
    xml::XMLPrinter printer;
    doc.Print(&printer);
    return std::string(printer.CStr());
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTCode& code) {
    auto memory = lastElem;
    lastElem = lastElem->InsertEndChild(doc.NewElement("cqt:code"));
    for (auto&& part : code.getParts()) {
        part->accept(*this);
    }
    lastElem = memory;
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTInnerCode& icode) {
    auto mem = lastElem;
    lastElem = lastElem->InsertEndChild(doc.NewElement("cqt:inner-code"));
    for (auto&& part : icode.getParts()) {
        part->accept(*this);
    }
    lastElem = mem;
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTOperation& op) {
    // Invocation just requires id and args
    if (op.getInstr() == Utils::Impl::instInvocation) {
        auto* invoc = doc.NewElement("cqt:invocation");
        invoc->SetAttribute("identifier", op.getInvId()->getVal().c_str());

        auto* args = doc.NewElement("cqt:arguments");
        for (auto&& arg : op.getArgs()) {
            auto* nArg = doc.NewElement("cqt:argument");
            nArg->InsertEndChild(doc.NewText(arg.c_str()));

            args->InsertEndChild(nArg);
        }
        invoc->InsertEndChild(args);

        lastElem->InsertEndChild(invoc);
        return;
    }

    // Other operations
    auto* mem = lastElem;

    auto* oper = doc.NewElement("cqt:operation");
    oper->SetAttribute("type", std::to_string(op.getInstr()).c_str());
    lastElem = lastElem->InsertEndChild(oper);

    op.getRep().accept(*this);

    if (const auto& ctor = op.getCtor()) {
        auto* ctorNode = doc.NewElement("cqt:constructor");
        auto* ctorType = doc.NewElement("cqt:type");
        ctorType->InsertEndChild(
             doc.NewText(std::to_string(ctor->type).c_str())
        );
        ctorNode->InsertFirstChild(ctorType);
        oper->InsertEndChild(
             ctorNode
        );

        auto* mem = lastElem;
        lastElem = ctorNode;
        if (auto val = ctor->val) {
            val->accept(*this);
        } else {
            oper->InsertEndChild(doc.NewElement("cqt:value"));
        }
        lastElem = mem;
    }
    lastElem = mem;
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ValExpr& expr) {
    auto* mem = lastElem;
    auto* val = doc.NewElement("cqt:value");
    val->SetAttribute("type", "Expression");
    lastElem = lastElem->InsertEndChild(val);

    switch (expr.getTyp()) {
        case Utils::Impl::exprAddition:
            std::dynamic_pointer_cast<AdditionExpression>(expr.getExpr())->accept(*this);
            break;
        case Utils::Impl::exprSubtraction:
            std::dynamic_pointer_cast<SubtractionExpression>(expr.getExpr())->accept(*this);
            break;
        case Utils::Impl::exprMultiplication:
            std::dynamic_pointer_cast<MultiplicationExpression>(expr.getExpr())->accept(*this);
            break;
        case Utils::Impl::exprDivision:
            std::dynamic_pointer_cast<DivisionExpression>(expr.getExpr())->accept(*this);
            break;
        case Utils::Impl::exprModulo:
            std::dynamic_pointer_cast<ModuloExpression>(expr.getExpr())->accept(*this);
            break;
        case Utils::Impl::exprValue:
            std::dynamic_pointer_cast<ValueExpression>(expr.getExpr())->accept(*this);
            break;
        case Utils::Impl::exprNegate:
            std::dynamic_pointer_cast<NegateExpression>(expr.getExpr())->accept(*this);
            break;
        case Utils::Impl::exprTernary:
            std::dynamic_pointer_cast<TernaryExpression>(expr.getExpr())->accept(*this);
            break;
        case Utils::Impl::exprEquality:
            std::dynamic_pointer_cast<EqualityExpression>(expr.getExpr())->accept(*this);
            break;
        case Utils::Impl::exprInequality:
            std::dynamic_pointer_cast<InequalityExpression>(expr.getExpr())->accept(*this);
            break;
        case Utils::Impl::exprGreaterThan:
            std::dynamic_pointer_cast<GreaterThanExpression>(expr.getExpr())->accept(*this);
            break;
        case Utils::Impl::exprGreaterOrEqual:
            std::dynamic_pointer_cast<GreaterOrEqualExpression>(expr.getExpr())->accept(*this);
            break;
        case Utils::Impl::exprLessThan:
            std::dynamic_pointer_cast<LessThanExpression>(expr.getExpr())->accept(*this);
            break;
        case Utils::Impl::exprLessOrEqual:
            std::dynamic_pointer_cast<LessOrEqualExpression>(expr.getExpr())->accept(*this);
            break;
    }

    lastElem = mem;
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ValText& txt) {
    valInserter("Text", txt);
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ValNumber& num) {
    valInserter("Number", num);
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ValID& id) {
    valInserter("Identifier", id);
}

void LibStarch::Algorithm::XMLPrinter::valInserter(const std::string& type, const ValNode& val) {
    auto* valNode = doc.NewElement("cqt:value");
    valNode->SetAttribute("type", type.c_str());

    valNode->InsertEndChild(doc.NewText(val.getVal().c_str()));

    lastElem->InsertEndChild(valNode);
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTForLoop& for_) {
    auto* mem = lastElem;
    lastElem = lastElem->InsertEndChild(
         doc.NewElement("cqt:for-loop")
    );

    auto* mem2 = lastElem;
    lastElem = lastElem->InsertEndChild(
         doc.NewElement("cqt:condition")
    );

    for_.getCond().getVal()->accept(*this);
    lastElem = mem2;

    // Funky mode
    const_cast<LibStarch::ASTInnerCode&>(for_.getCode()).accept(*this);
    if (const auto& init = for_.getInit()) {
        auto* mem = lastElem;
        lastElem = lastElem->InsertEndChild(
             doc.NewElement("init-code")
        );
        const_cast<ASTInnerCode&>(*init).accept(*this);

        lastElem = mem;
    }
    if (const auto& step = for_.getInit()) {
        auto* mem = lastElem;
        lastElem = lastElem->InsertEndChild(
             doc.NewElement("step-code")
        );
        const_cast<ASTInnerCode&>(*step).accept(*this);

        lastElem = mem;
    }

    lastElem = mem;
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTWhileLoop& while_) {
    auto* mem = lastElem;
    lastElem = lastElem->InsertEndChild(
         doc.NewElement("cqt:while-loop")
    );

    auto* mem2 = lastElem;
    lastElem = lastElem->InsertEndChild(
         doc.NewElement("cqt:condition")
    );

    while_.getCond().getVal()->accept(*this);
    lastElem = mem2;
    // Note this is fine as XMLPrinter is pure
    const_cast<LibStarch::ASTInnerCode&>(while_.getCode()).accept(*this);

    lastElem = mem;
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTDoLoop& do_) {
    auto* mem = lastElem;
    lastElem = lastElem->InsertEndChild(
         doc.NewElement("cqt:do-loop")
    );

    auto* mem2 = lastElem;
    lastElem = lastElem->InsertEndChild(
         doc.NewElement("cqt:condition")
    );

    do_.getCond().getVal()->accept(*this);
    lastElem = mem2;
    // Note this is fine as XMLPrinter is pure
    const_cast<LibStarch::ASTInnerCode&>(do_.getCode()).accept(*this);

    lastElem = mem;
}

void LibStarch::Algorithm::XMLPrinter::exprInserter(const LibStarch::CExpression& expr,
                                                    const std::string& exprName) {
    auto* mem = lastElem;
    lastElem = lastElem->InsertEndChild(
         doc.NewElement(("cqt:" + exprName).c_str())
    );
    auto al = expr.getAnyLeft();
    auto ar = expr.getAnyRight();

    switch (al.type) {
        case LibStarch::Utils::Impl::valValExpr:
            ((LibStarch::ValExpr*) al.value)->accept(*this);
            break;
        case LibStarch::Utils::Impl::valValText:
            ((LibStarch::ValText*) al.value)->accept(*this);
            break;
        case LibStarch::Utils::Impl::valValNumber:
            ((LibStarch::ValNumber*) al.value)->accept(*this);
            break;
        case LibStarch::Utils::Impl::valValID:
            ((LibStarch::ValID*) al.value)->accept(*this);
            break;
    }
    switch (ar.type) {
        case LibStarch::Utils::Impl::valValExpr:
            ((LibStarch::ValExpr*) ar.value)->accept(*this);
            break;
        case LibStarch::Utils::Impl::valValText:
            ((LibStarch::ValText*) ar.value)->accept(*this);
            break;
        case LibStarch::Utils::Impl::valValNumber:
            ((LibStarch::ValNumber*) ar.value)->accept(*this);
            break;
        case LibStarch::Utils::Impl::valValID:
            ((LibStarch::ValID*) ar.value)->accept(*this);
            break;
    }
    if (const auto& cond = expr.getCond()) {
        auto* mem = lastElem;
        lastElem = lastElem->InsertFirstChild(doc.NewElement("cqt:condition"));

        cond->getVal()->accept(*this);

        lastElem = mem;
    }

    lastElem = mem;
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::AdditionExpression& expr) {
    exprInserter(expr, "addition");
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::SubtractionExpression& expr) {
    exprInserter(expr, "subtraction");
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::MultiplicationExpression& expr) {
    exprInserter(expr, "multiplication");
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::DivisionExpression& expr) {
    exprInserter(expr, "division");
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ModuloExpression& expr) {
    exprInserter(expr, "modulo");
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ValueExpression& expr) {
    exprInserter(expr, "value-expr");
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::NegateExpression& expr) {
    exprInserter(expr, "negation");
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::TernaryExpression& expr) {
    exprInserter(expr, "ternary");
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::EqualityExpression& expr) {
    exprInserter(expr, "equality");
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::InequalityExpression& expr) {
    exprInserter(expr, "inequality");
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::GreaterThanExpression& expr) {
    exprInserter(expr, "greater-than");
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::GreaterOrEqualExpression& expr) {
    exprInserter(expr, "greater-or-equal");
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::LessThanExpression& expr) {
    exprInserter(expr, "less-than");
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::LessOrEqualExpression& expr) {
    exprInserter(expr, "less-or-equal");
}

LibStarch::Algorithm::XMLPrinter::operator bool() {
    return set;
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTMacroDefinition macro) {
    auto* nMacro = doc.NewElement("cqt:macro");
    nMacro->SetAttribute("identifier", macro.getName().getVal().c_str());
    nMacro->InsertEndChild(
         doc.NewText(macro.getText().c_str())
    );
    lastElem->InsertEndChild(nMacro);
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTSubDefinition sub) {
    auto* mem = lastElem;

    auto* nSub = doc.NewElement("cqt:subroutine");
    nSub->SetAttribute("identifier", sub.getName().getVal().c_str());
    lastElem = lastElem->InsertEndChild(nSub);

    // Note this is fine as XMLPrinter is pure
    const_cast<ASTCode&>(sub.getCode()).accept(*this);

    lastElem = mem;
}

