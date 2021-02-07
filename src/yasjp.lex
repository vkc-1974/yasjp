/*
 * File		:yasjp.lex
 * Author	:Victor Kovalevich
 * Created	:Tue Feb  2 22:05:57 2021
 */

%option noyywrap nounistd 8bit c++ pointer prefix="lex" yyclass="LexParser"

%top{
#include "yasjp/yasjp.h"
}

%x string_literal

%%

[ \t\r\n]+ {
    /* Space symbols are ignored */ }

<<EOF>> {
    /* Process EOF symbol */
    return yasjp::Token::EOF;
}

\{ {
    /* Process `{` symbol */
    return yasjp::Token::OpenBrace;
}

\} {
    /* Process `}` symbol */
    return yasjp::Token::CloseBrace;
}

\[ {
    /* Process `[` symbol */
    return yasjp::Token::OpenBracket;
}

\] {
    /* Process `[` symbol */
    return yasjp::Token::CloseBracket;
}

\: {
    /* Process `:` symbol */
    return yasjp::Token::Column;
}

\" {
    /* Start collecting symbols into a string literal */
    BEGIN(string_literal);
    newStringLiteral();
}

<string_literal>\\\" {
    /* Add " symbol to resulting literal */
    addStringChunk('\"');
}

<string_literal>\\\\ {
    /* Add " symbol to resulting literal */
    addStringChunk('\\');
}

<string_literal>\\\/ {
    /* Add / symbol to resulting literal */
    addStringChunk('\/');
}

<string_literal>\\b {
    /* Add \b symbol to resulting literal */
    addStringChunk('\b');
}

<string_literal>\\f {
    /* Add \f symbol to resulting literal */
    addStringChunk('\f');
}

<string_literal>\\n {
    /* Add \n symbol to resulting literal */
    addStringChunk('\n');
}

<string_literal>\\r {
    /* Add \r symbol to resulting literal */
    addStringChunk('\r');
}

<string_literal>\\t {
    /* Add \t symbol to resulting literal */
    addStringChunk('\t');
}

<string_literal>\\u[[:xdigit:]]{2} {
    /* Add \b symbol to resulting literal */
    addStringChunk('\b');
}

<string_literal>[[:alnum:] \!\#\$%\&\(\)\*\+\,\-\.:;<=>\?@\[\]\^_`{|}~]+ {
    /* Add another string chunk Finalize collecting symbols into a string literal */
    addStringChunk(yytext, yyleng);
}

<string_literal>\n  {
    /* Error - unterminated string literal,
       generate error message */
}

<string_literal>\" {
    /* Finalize collecting symbols into a string literal */
    BEGIN(INITIAL);
    completeStringLiteral();
}

%%
