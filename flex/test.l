%option noyywrap

%{
#include<stdio.h>  /// header file 
%}


digit[0-9]
number {digit}+(.{digit}+)?([Ee][+-]?{digit}+)?
ID[A-Za-z_][A-Za-z_0-9]*
BOP ">>"|"<<"|"|"|"^"|"&"
keyword int
OP =
SEMICOLON ;
AOP ">>="|"<<="|"="|"&="|"^="|"|="


%%

{number} {printf("\n<Number,%s>",yytext);}
{keyword} {printf("\n<Keyword,%s>",yytext);}
{ID} {printf("\n<Identifier,%s>",yytext);}
{OP} {printf("\n<Operator,%s>",yytext);}
{SEMICOLON} {printf("\n<Semicolon,%s>",yytext);}
{BOP} {printf("\n<Bitwise Operator,%s>",yytext);}
{AOP} {printf("\n<Assingment Operator,%s>",yytext);}

%%


int main(){


yylex();

}