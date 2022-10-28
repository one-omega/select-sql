/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

#ifndef YY_YY_GRAM_TAB_H_INCLUDED
# define YY_YY_GRAM_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     CREATE = 259,
     DROP = 260,
     USE = 261,
     SELECT = 262,
     INSERT = 263,
     DELETE = 264,
     UPDATE = 265,
     FROM = 266,
     WHERE = 267,
     INTO = 268,
     VALUES = 269,
     SET = 270,
     NEWLINE = 271,
     DATABASE = 272,
     DATABASES = 273,
     TABLE = 274,
     null = 275,
     LIKE = 276,
     IN = 277,
     EXISTS = 278,
     TABLES = 279,
     SHOW = 280,
     EXIT = 281,
     BYE = 282,
     CHAR = 283,
     ID = 284,
     STRING = 285,
     INTNUMBER = 286,
     OR = 287,
     AND = 288,
     NOT = 289
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 12 "gram.y"

    /* ID和变量类型 */
	struct values* value;

	/* 建表语句使用类型 */
	struct coltype* coltype;
	struct col* col;
	struct createTablesql* createTablesql;

	/* 插入语句使用类型 */
	struct datanode* datanode;
	struct insertsql* insertsql;


	/* 查询语句使用类型 */
	struct tablecol* tablecol;
	struct tablecolconf* tablecolconf;
	struct condition* condition;
	int comp_op;
	struct comparator* comparator;
	struct selectsql* selectsql;

	/* 更新语句使用类型 */
	struct setconf* setconf;
	struct updatesql* updatesql;

	/* 删除语句使用类型 */
	struct deletesql* deletesql;



/* Line 2058 of yacc.c  */
#line 123 "gram.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_GRAM_TAB_H_INCLUDED  */
