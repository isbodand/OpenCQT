//
// Created by bodand on 2019-06-12.
//

#pragma once

#include <algorithm>
#include <numeric>
#include <memory>
#include <iterator>

#define BOOST_SPIRIT_DEBUG
#include <boost/spirit/include/qi.hpp>

#include <boost/spirit/include/phoenix.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_container.hpp>
#include <boost/spirit/include/phoenix_statement.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>

#include "../../starch/starch.hpp"
#include "../../starch/src/Utils.hpp"

BOOST_FUSION_ADAPT_STRUCT(
     LibStarch::TypeCtor,
     (LibStarch::Utils::Type, type),
     (std::shared_ptr<LibStarch::ValNode>, val)
)



namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
namespace fsn = boost::fusion;
namespace sch = LibStarch;

namespace OpenCqt::Parse {
  template<class It>
  struct CroquetteGrammar
       : qi::grammar<It, sch::ASTRoot(), ascii::space_type> {

      struct instructions_t : qi::symbols<char, sch::Utils::Instruction> {
          instructions_t() {
              add
                   ("+", sch::Utils::Impl::instPlus)
                   ("-", sch::Utils::Impl::instMinus)
                   (">", sch::Utils::Impl::instStepForward)
                   ("<", sch::Utils::Impl::instStepBackward)
                   ("˘", sch::Utils::Impl::instStepInto)
                   ("^", sch::Utils::Impl::instStepOut)
                   (".", sch::Utils::Impl::instPrint)
                   (",", sch::Utils::Impl::instRead);
          }
      } instr_;

      struct type_t : qi::symbols<char, sch::Utils::Type> {
          type_t() {
              add
                   ("$$", sch::Utils::Impl::typeTrueScalar)
                   ("$|", sch::Utils::Impl::typeCharScalar)
                   ("@$", sch::Utils::Impl::typeFlatArray)
                   ("@@", sch::Utils::Impl::typeCompArray)
                   ("#$", sch::Utils::Impl::typeHashMap)
                   ("#@", sch::Utils::Impl::typeTreeMap)
                   ("&$", sch::Utils::Impl::typeReference)
                   ("%$", sch::Utils::Impl::typeFunction);
          }
      } type_;

      CroquetteGrammar()
           : CroquetteGrammar::base_type(program) {
          using ascii::char_;

          using qi::int_;
          using qi::double_;

          using qi::lexeme;
          using qi::lit;
          using qi::eps;

          using namespace qi::labels;

          namespace phx = boost::phoenix;

          auto value_f = [](const std::shared_ptr<sch::ValNode>& ptr,
                            value_ctx& ctx,
                            fsn::unused_type&) {
            switch (fsn::at_c<0>(ctx.locals)) {
                case 1:
                    fsn::at_c<0>(ctx.attributes) =
                         sch::ValNode::mkPtrID(fsn::at_c<1>(ctx.locals).getIdName());
                    return;
                case 2:
                    fsn::at_c<0>(ctx.attributes) =
                         sch::ValNode::mkPtrNumber(fsn::at_c<2>(ctx.locals).getValue());
                    return;
                case 3:
                    fsn::at_c<0>(ctx.attributes) =
                         sch::ValNode::mkPtrText(fsn::at_c<3>(ctx.locals).getValue());
                    return;
                case 4:
                    fsn::at_c<0>(ctx.attributes) =
                         sch::ValNode::mkPtrExpr(fsn::at_c<4>(ctx.locals).getExpr().get());
                    return;
            }
          };

          sch::ASTRestrictedCodePart* (std::__shared_ptr<sch::ASTRestrictedCodePart>::* func)() const;
          func = &std::shared_ptr<sch::ASTRestrictedCodePart>::get;

          //&!off
          program = code                                                        [_val = phx::construct<sch::ASTRoot>(_1)]
                  ;

          code = (*code_part)                                                   [_val = phx::construct<sch::ASTCode>(_1)]
               ;

          code_part = operation
                    // todo
                    //| loop
                    //| definition
                    ;

          operation = op_call
                    | op_inst
                    ;

          op_call = ("%{"
                     >> id
                     >> macro_call_params
                     >> "}"
                    )
                  ;

          op_inst = (instr_ >> param >> repeat)
                  ;

          macro_call_params = *('{' >> (+char_ - '}') >> '}');

          param = ('{' >> type_ >> -('{' >> value >> '}') >> '}');

          repeat = ("#{" >> value >> '}');

          id = qi::as_string[lexeme[
                !char_('\'') >> !char_("0-9")
                >> +char_("0-9a-zA-Z'")
               ]]
             ;

          num = double_;
          txt = qi::as_string[lexeme['"' >> *(char_ - '"') >> '"']];
          expr = cexpr                                                          [_val = phx::construct<sch::ValExpr>(_1)];

          value = ( id      [_a = 1, _b = _1]
                  | num     [_a = 2, _c = _1]
                  | txt     [_a = 3, _d = _1]
                  | expr    [_a = 4, _e = _1]
                  )                                                             [value_f]
                ;
          //&!on
      }

      /// The whole Program
      qi::rule<It, sch::ASTRoot(), ascii::space_type> program;
      /// Code which contains stuff to be executed
      qi::rule<It, sch::ASTCode()> code;
      /// One part of code
      qi::rule<It, std::shared_ptr<sch::ASTRestrictedCodePart>()> code_part;
      /// Operation type of parts of code
      qi::rule<It, std::shared_ptr<sch::ASTOperation>()> operation;
      qi::rule<It, std::shared_ptr<sch::ASTOperation>()> op_call;
      qi::rule<It, sch::ASTOperation()> op_inst;
      /// Macro call parameter lists
      qi::rule<It, std::vector<std::string>()> macro_call_params;
      /// Instruction type parameter
      qi::rule<It, sch::TypeCtor()> param;
      /// Repetition amount of an instruction
      qi::rule<It, std::shared_ptr<sch::ValNode>()> repeat;
      /// Loop type of parts of code
      qi::rule<It, sch::ASTLoop()> loop;
      /// Definition type of parts of code
      qi::rule<It, sch::ASTDefinition()> definition;

      qi::rule<It, sch::CExpression*()> cexpr;

      qi::rule<It, sch::ValID()> id;
      qi::rule<It, sch::ValNumber()> num;
      qi::rule<It, sch::ValText()> txt;
      qi::rule<It, sch::ValExpr()> expr;
      qi::rule<It, std::shared_ptr<sch::ValNode>(),
           qi::locals<
                unsigned,
                sch::ValID,
                sch::ValNumber,
                sch::ValText,
                sch::ValExpr
           >
      > value;
      using value_ctx = boost::spirit::context<
           fsn::cons<std::shared_ptr<sch::ValNode>, fsn::nil>,
           fsn::vector5<
                unsigned,
                sch::ValID,
                sch::ValNumber,
                sch::ValText,
                sch::ValExpr
           >
      >;

      std::string vectostr(std::vector<char> vec);
  };

  template<class It>
  std::string CroquetteGrammar<It>::vectostr(std::vector<char> vec) {
      return std::accumulate(vec.begin(), vec.end(), std::string());
  }

  /* Fuck My Life */
  /*
   * WIP
   * ...
   * Fuck My Life
   * Do it whenever
   * It's gonna be shit forever
   * ...
   */
}

namespace boost::spirit::traits {
  using val_vec_t = std::tuple<
       sch::ValID,
       std::vector<std::string>
  >;

  using inst_op_t = std::tuple<
       sch::Utils::Instruction,
       std::optional<sch::TypeCtor>,
       std::optional<std::shared_ptr<sch::ValNode>>
  >;

  template<>
  struct transform_attribute<std::shared_ptr<sch::ASTOperation>, val_vec_t, qi::domain> {
      typedef val_vec_t type;

      static type pre(std::shared_ptr<sch::ASTOperation>& val) {
          return type();
      }

      static void post(std::shared_ptr<sch::ASTOperation>& val, type attr) {
          val = std::make_shared<sch::ASTOperation>(std::get<0>(attr), std::get<1>(attr));
      }

      static void fail(std::shared_ptr<sch::ASTOperation>&) {}
  };

  template<>
  struct transform_attribute<std::shared_ptr<sch::ASTOperation>, sch::ValID, qi::domain> {
      typedef sch::ValID type;

      static type pre(std::shared_ptr<sch::ASTOperation>& val) {
          return type();
      }

      static void post(std::shared_ptr<sch::ASTOperation>& val, type attr) {
          val = std::make_shared<sch::ASTOperation>(attr, std::vector<std::string>());
      }

      static void fail(std::shared_ptr<sch::ASTOperation>&) {}
  };

  template<>
  struct transform_attribute<std::shared_ptr<sch::ASTOperation>, inst_op_t, qi::domain> {
      typedef inst_op_t type;

      static type pre(std::shared_ptr<sch::ASTOperation>& val) {
          return type();
      }

      static void post(std::shared_ptr<sch::ASTOperation>& val, type attr) {
          auto builder = sch::ASTOperation::getBuilder().asInstruction(std::get<0>(attr));
          if (std::get<1>(attr)) {
              builder.withConstructor(*std::get<1>(attr));
          }
          if (std::get<2>(attr)) {
              builder.withRepetition(*std::get<2>(attr));
          }
          val = builder.buildPtr();
      }

      static void fail(std::shared_ptr<sch::ASTOperation>&) {}
  };
}
