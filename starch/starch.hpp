//
// Created by bodand on 2019-08-29.
//

// Aggregate Header
#pragma once

// Root element
#include "src/AstRoot.hpp"

// Code elements
#include "src/AstCode.hpp"
#include "src/AstInnerCode.hpp"

// Code part elements of code elements {
// Operation
#include "src/codepart/AstOperation.hpp"
// Loops
#include "src/codepart/loop/AstForLoop.hpp"
#include "src/codepart/loop/AstWhileLoop.hpp"
#include "src/codepart/loop/AstDoLoop.hpp"
// Definitions
#include "src/codepart/def/AstMacroDefinition.hpp"
#include "src/codepart/def/AstSubDefinition.hpp"
//}

// Val Subtree elements
#include "src/val_subtrees/ValText.hpp"
#include "src/val_subtrees/ValNumber.hpp"
#include "src/val_subtrees/ValId.hpp"
#include "src/val_subtrees/ValExpr.hpp"

// C-Expressions
#include "src/cexpr/AdditionExpression.hpp"
#include "src/cexpr/SubtractionExpression.hpp"
#include "src/cexpr/DivisionExpression.hpp"
#include "src/cexpr/ModuloExpression.hpp"
#include "src/cexpr/MultiplicationExpression.hpp"

#include "src/cexpr/EqualityExpression.hpp"
#include "src/cexpr/InequalityExpression.hpp"
#include "src/cexpr/GreaterThanExpression.hpp"
#include "src/cexpr/GreaterOrEqualExpression.hpp"
#include "src/cexpr/LessThanExpression.hpp"
#include "src/cexpr/LessOrEqualExpression.hpp"

#include "src/cexpr/ValueExpression.hpp"
#include "src/cexpr/NegateExpression.hpp"

#include "src/cexpr/TernaryExpression.hpp"
