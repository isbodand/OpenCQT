//
// Created by bodand on 2019-07-01.
//

#include <sstream>
#include "XmlPrinter.hpp"
#include "../AstInnerCode.hpp"
#include "../codepart/AstOperation.hpp"
#include "../val_subtrees/ValText.hpp"
#include "../val_subtrees/ValNumber.hpp"
#include "../val_subtrees/ValExpr.hpp"
#include "../val_subtrees/ValId.hpp"
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
#include "../Utils.hpp"

#define TAB "  "

void insert(std::string& toInsert);

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTRoot& root) {
    std::string rootXml("<cqt:program>\n\n</cqt:program>");
    insert(rootXml, std::string("<cqt:program>\n").length());
    tab++;
    root.getCode().accept(*this);
    tab--;
    insertPos += std::string("\n</cqt:program>").length();
}

const std::string& LibStarch::Algorithm::XMLPrinter::getXml() const {
    return Xml;
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTCode& code) {
    std::string start, fin;
    std::string codeXml(mkTags("<cqt:code>", start, fin));
    insert(codeXml, start.length());
    tab++;
    for (auto&& part : code.getParts()) {
        part->accept(*this);
    }
    tab--;
    insertPos += fin.length();
}

void LibStarch::Algorithm::XMLPrinter::insert(std::string& toInsert, std::size_t followUpInserPos) {
    insertPos = Xml.insert(insertPos, toInsert.begin(), toInsert.end());
    insertPos += followUpInserPos;
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTInnerCode& icode) {
    std::string start, fin;
    std::string codeXml = mkTags("<cqt:inner-code>", start, fin);
    insert(codeXml, start.length());
    tab++;
    for (auto&& part : icode.getParts()) {
        part->accept(*this);
    }
    tab--;
    insertPos += std::string("\n</cqt:inner-code>").length();
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTOperation& op) {
    std::stringstream opStartXml;
    opStartXml << "<cqt:operation type=\"" << std::to_string(op.getInstr()) << "\">";
    std::string ops = opStartXml.str();
    std::string start, fin;
    std::string opXml = mkTags(ops, "</cqt:operation>", start, fin);
    insert(opXml, start.length());
    tab++;
    op.getRep().accept(*this);
    if (auto ctor = op.getCtor()) {
        std::string typ = std::to_string(ctor->type);
        std::string beginer = "<cqt:constructor><cqt:type>" + typ + "</cqt:type>";
        std::string ender = "</cqt:constructor>";
        std::string typXml(beginer + ender);
        Xml.insert(insertPos, typXml.begin(), typXml.end());
        insertPos += beginer.length();
        if (auto val = ctor->val) {
            val->accept(*this);
        } else {
            std::string nullval("<cqt:value />");
            insertPos = Xml.insert(insertPos, nullval.begin(), nullval.end());
        }
        insertPos += ender.length();
    }
    tab--;
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ValExpr& expr) {
    std::string start, fin;
    std::string exprXml = mkTags("<cqt:value type=\"Expression\">", "</cqt:value>", start, fin);
    insert(exprXml, start.length());
    tab++;
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
    tab--;
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
    std::stringstream exprXml;
    std::string start, fin;
    mkTags("<cqt:value type=\"" + type + "\">", "</cqt:value>", start, fin);
    exprXml << start;
    tab++;
    val.asString(exprXml);
    tab--;
    exprXml << fin;
    std::string s = exprXml.str();
    Xml.insert(insertPos, s.begin(), s.end());
    insertPos += s.length();
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTForLoop& for_) {
    //todo
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTWhileLoop& while_) {
    //todo
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTDoLoop& do_) {
    //todo
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::AdditionExpression& expr) {
    std::string start, fin;
    std::string addXml = mkTags("<cqt:addition>", start, fin);
    insert(addXml, start.length());
    auto al = std::move(expr.getAnyLeft());
    auto ar = std::move(expr.getAnyLeft());
    tab++;
    tab--;
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::SubtractionExpression& expr) {

}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::MultiplicationExpression& expr) {

}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::DivisionExpression& expr) {

}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ModuloExpression& expr) {

}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ValueExpression& expr) {

}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::NegateExpression& expr) {

}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::TernaryExpression& expr) {

}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::EqualityExpression& expr) {

}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::InequalityExpression& expr) {

}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::GreaterThanExpression& expr) {

}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::GreaterOrEqualExpression& expr) {

}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::LessThanExpression& expr) {

}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::LessOrEqualExpression& expr) {

}

std::string LibStarch::Algorithm::XMLPrinter::mkTags(const std::string& tag, std::string& start, std::string& fin) {
    return mkTags(tag, tag[0] + std::string("/") + tag.substr(1), start, fin);
}

std::string LibStarch::Algorithm::XMLPrinter::mkTags(const std::string& tags,
                                                     const std::string& tagf,
                                                     std::string& start, std::string& fin) {
    std::stringstream sss, ssf;
    ssf << "\n";
    for (int i = 0; i < tab; ++i) {
        sss << TAB;
        ssf << TAB;
    }
    sss << tags + "\n";
    ssf << tagf;
    start = sss.str();
    fin = ssf.str();
    return start + fin;
}

LibStarch::Algorithm::XMLPrinter::operator bool() {
    return Xml != R"(<?xml version="1.0" encoding="UTF-8" ?>)" "\n";
}

