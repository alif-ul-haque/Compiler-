%option noyywrap

%{
#include<stdio.h>  /// header file
int line_no = 1; 
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
SLC             {CM1}.*
CM3             "/*"
CM4             "*/"
MLC             {CM3}([^*]|\*+[^*/])*\**{CM4}
LIT1            \"
LIT2            \"
LITERAL         {LIT1}([^\\\"\n]|\\.)*{LIT2} 
STAB            [ \t]


%%


{digit}[A-Za-z]+	{}
\n              {line_no++;}
{SLC}           {line_no++;}
{MLC}           {
                    for(int i=0;yytext[i];i++)
					      if(yytext[i]=='\n')
						       line_no++;
	            }
{number}        {fprintf(yyout,"<Number,%s,%d>\n", yytext,line_no);}
{keyword}       {fprintf(yyout,"<Keyword,%s,%d>\n", yytext,line_no);}
{ID}\(          {fprintf(yyout,"<Function,\"%.*s\",%d>\n",yyleng-1, yytext,line_no);} 
{ID}            {fprintf(yyout,"<Identifier,%s,%d>\n", yytext,line_no);}
{BOP}           {fprintf(yyout,"<Bitwise Operator,%s,%d>\n", yytext,line_no);}
{AOP}           {fprintf(yyout,"<Assignment Operator,%s,%d>\n", yytext,line_no);}
{PARENTHESIS}   {fprintf(yyout,"<Parenthesis,%s,%d>\n", yytext,line_no);}
{CURLY}         {fprintf(yyout,"<Curly Braces,%s,%d>\n", yytext,line_no);}
{SP}            {fprintf(yyout,"<Separator,%s,%d>\n", yytext,line_no);}
{LITERAL}       {fprintf(yyout,"<Literals,%s,%d>\n", yytext,line_no);}
{STAB}          {}

%%

int main(){


yyin=fopen("sample_input.txt","r"); 
if(!yyin)
	{
		perror("Could not open the file");
		return 1;
	}
	
	yyout = fopen("output.txt" , "w");
	if(!yyout)
	{
		perror("could not open the file");
		fclose(yyin);
		return 1;
	}
yylex();
fclose(yyin); 
fclose(yyout); 
return 0;
}