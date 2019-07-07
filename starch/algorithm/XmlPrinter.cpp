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
#include "../Utils.hpp"

void insert(std::string& toInsert);

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTRoot& root) {
    std::string rootXml("<cqt:program></cqt:program>");
    insert(rootXml, std::string("<cqt:program>").length());
    root.getCode().accept(*this);
    insertPos += std::string("</cqt:program>").length();
}

const std::string& LibStarch::Algorithm::XMLPrinter::getXml() const {
    return Xml;
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTCode& code) {
    std::string codeXml("<cqt:code></cqt:code>");
    insert(codeXml, std::string("<cqt:code>").length());
    for (auto&& part : code.getParts()) {
        part->accept(*this);
    }
    insertPos += std::string("</cqt:code>").length();
}

void LibStarch::Algorithm::XMLPrinter::insert(std::string& toInsert, std::size_t followUpInserPos) {
    auto remPos = std::distance(Xml.begin(), insertPos);
    Xml.insert(insertPos, toInsert.begin(), toInsert.end());
    insertPos = (Xml.begin() + remPos) + followUpInserPos;
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTInnerCode& icode) {
    std::string codeXml("<cqt:inner-code></cqt:inner-code>");
    insert(codeXml, std::string("<cqt:inner-code>").length());
    for (auto&& part : icode.getParts()) {
        part->accept(*this);
    }
    insertPos += std::string("</cqt:inner-code>").length();
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ASTOperation& op) {
    std::stringstream opStartXml;
    opStartXml << "<cqt:operation type=\"" << std::to_string(op.getInstr()) << "\">";
    std::string ops = opStartXml.str();
    std::string opXml(ops + "</cqt:operation>");
    insert(opXml, ops.length());
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
            Xml.insert(insertPos, nullval.begin(), nullval.end());
            insertPos += nullval.length();
        }
        insertPos += ender.length();
    }
}

void LibStarch::Algorithm::XMLPrinter::visit(LibStarch::ValExpr& expr) {
    valInserter("Expression", expr);
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
    exprXml << "<cqt:value type=\"" + type + "\">";
    val.asString(exprXml);
    exprXml << "</cqt:value>";
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

