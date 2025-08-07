%option noyywrap

%{
#include <stdio.h>  /* C-style comment — OK in Flex */
%}

digit           [0-9]
number          [+\-]?{digit}+(\.{digit}+)?([Ee][+-]?{digit}+)? 
keyword         "if"|"else"|"switch"|"case"|"while"|"for"|"int"|"float"|"double"|"break"|"default"|"void" 
ID              [A-Za-z_][A-Za-z_0-9]*
BOP             ">>"|"<<"|"|"|"^"|"&"
AOP             ">>="|"<<="|"="|"&="|"^="|"|="
PARENTHESIS     "("|")"
CURLY           "{"|"}"
SP              ","|";"|":"
CM1             "//"
CM2             {CM1}[A-Za-z0-9_ *]+
CM3             "/*"
CM4             "*/"
CM5             {CM3}([^*]|\*+[^*/])*\**{CM4}
COMMENT         {CM2}|{CM5}
LIT1            \"
LIT2            \"
LITERAL         {LIT1}([^\\\"\n]|\\.)*{LIT2} 

%%

{number}        {printf("<Number,%s>\n", yytext);}
{keyword}       {printf("<Keyword,%s>\n", yytext);}
{ID}\(          {printf("<Function,\"%.*s\">\n",yyleng-1, yytext);} 
{ID}            {printf("<Identifier,%s>\n", yytext);}
{BOP}           {printf("<Bitwise Operator,%s>\n", yytext);}
{AOP}           {printf("<Assignment Operator,%s>\n", yytext);}
{PARENTHESIS}   {printf("<Parenthesis,%s>\n", yytext);}
{CURLY}         {printf("<Curly Braces,%s>\n", yytext);}
{SP}            {printf("<Separator,%s>\n", yytext);}
{COMMENT}       {printf("<Comment,%s>\n", yytext);}
{LITERAL}       {printf("<Literals,%s>\n", yytext);} 

%%

int main() {
    yylex();
    return 0;
}
