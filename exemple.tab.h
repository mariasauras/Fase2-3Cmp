/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_EXEMPLE_TAB_H_INCLUDED
# define YY_YY_EXEMPLE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 28 "exemple.y"

  /* Les definicions que s'utilitzen al %union han d'estar aqui */
  #include "symtab.h"
  #include "exemple_dades.h"
  #include "exemple_funcions.h"
  

#line 56 "exemple.tab.h"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ASSIGN = 258,
    ENDLINE = 259,
    INTEGER = 260,
    ID = 261,
    FLOAT = 262,
    STRING = 263,
    BOOLEAN = 264,
    SUMA = 265,
    RESTA = 266,
    MUL = 267,
    DIV = 268,
    MOD = 269,
    POW = 270,
    OP = 271,
    CP = 272,
    OC = 273,
    CC = 274,
    PC = 275,
    SPACE = 276,
    COMMA = 277,
    OR = 278,
    AND = 279,
    NOT = 280,
    END = 281,
    DDP = 282,
    RETURN = 283,
    FUNC = 284,
    GREATERTHAN = 285,
    LESSTHAN = 286,
    GREATEREQ = 287,
    LESSEQ = 288,
    EQ = 289,
    DIF = 290,
    FOR = 291,
    IF = 292,
    ELSE = 293,
    ELSEIF = 294,
    IN = 295,
    WHILE = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "exemple.y"

  cond_list cl;

#line 113 "exemple.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EXEMPLE_TAB_H_INCLUDED  */
