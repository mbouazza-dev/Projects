%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "traduc.h"
#include "parser.h"
int lineno = 1;
int c = 1;
char linebuf[500];
%}

%option noinput nounput noyywrap
%x COMMENT

%%
<COMMENT>"*/" BEGIN INITIAL;
"/*" { BEGIN COMMENT; }
"//".* ;
<COMMENT>
. ;
<COMMENT>
\n ; 						{ lineno++; c = 0; }

\n 							{ lineno++; c = 0; strncpy(linebuf, "\n", sizeof(linebuf)); }

int|char 					{ strcpy(yylval.type, yytext); c += yyleng; strcat(linebuf, yytext); return TYPE; }
void 						{ c += yyleng; strcat(linebuf, yytext); return VOID; }

while 						{ c += yyleng; strcat(linebuf, yytext); return WHILE; }
if 							{ c += yyleng; strcat(linebuf, yytext); return IF; }
else 						{ c += yyleng; strcat(linebuf, yytext); return ELSE; }
print 						{ c += yyleng; strcat(linebuf, yytext); return PRINT; }
return 						{ c += yyleng; strcat(linebuf, yytext); return RETURN; }

readc 						{ c += yyleng; strcat(linebuf, yytext); return READC; }
reade 						{ c += yyleng; strcat(linebuf, yytext); return READE; }

[a-zA-Z][a-zA-Z0-9_]* 		{ strcpy(yylval.id, yytext); c += yyleng; strcat(linebuf, yytext); return IDENT; }
[0-9]+ 						{ yylval.num = atoi(yytext); c += yyleng; strcat(linebuf, yytext); return NUM; }

[ \t\r]+ 					{ c += yyleng; strcat(linebuf, yytext); }


==|!=						{ strcpy(yylval.comp, yytext); c += yyleng; strcat(linebuf, yytext); return EQ; }
"<"|"<="|">"|">="			{ strcpy(yylval.comp, yytext); c += yyleng; strcat(linebuf, yytext); return ORDER; }

\|\| 						{ c += yyleng; strcat(linebuf, yytext); return OR; }
&&							{ c += yyleng; strcat(linebuf, yytext); return AND; }

\+|-						{ yylval.addsub = yytext[0]; c += yyleng; strcat(linebuf, yytext); return ADDSUB; }


\*|\/|\% 					{ c += yyleng; strcat(linebuf, yytext); return yytext[0]; }
, 							{ c += yyleng; strcat(linebuf, yytext); return yytext[0]; }
; 							{ c += yyleng; strcat(linebuf, yytext); return yytext[0]; }
\( 							{ c += yyleng; strcat(linebuf, yytext); return yytext[0]; }
\) 							{ c += yyleng; strcat(linebuf, yytext); return yytext[0]; }
\{ 							{ c += yyleng; strcat(linebuf, yytext); return yytext[0]; }
\} 							{ c += yyleng; strcat(linebuf, yytext); return yytext[0]; }
= 							{ c += yyleng; strcat(linebuf, yytext); return yytext[0]; }
! 							{ c += yyleng; strcat(linebuf, yytext); return yytext[0]; }
& 							{ c += yyleng; strcat(linebuf, yytext); return yytext[0]; }

\'.\'						{ yylval.caractere = yytext[1]; c += yyleng; strcat(linebuf, yytext); return CHARACTER; }
.							{ c += yyleng; strcat(linebuf, yytext); return yytext[0]; }

%%
