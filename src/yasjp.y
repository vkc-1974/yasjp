/*
 * File		:yasjp.y
 * Author	:Victor Kovalevich
 * Created	:Thu Nov  8 17:20:02 2018
 */

/*
 * Prologue */
%{
#include "yasjp/impl/yasjp.h"
%}

%union
{
}

/*                      
 * Grammar rules */
%%
Object:         '{' KeyValuePairList '}'
        ;
KeyValuePairList:
                %empty                            { $$=newKeyValueList(); }
        |       KeyValuePair                      { $$=newKeyValueList(); $$.append($1); }
        |       KeyValuePairList ',' KeyValuePair { $$.append($1, $2); }
        ;

KeyValuePair:
                String ':' Value                  { $$=newKeyValuePair($1, $2); }
        ;

Value:
                String
        |       Number
        |       Object
        |       Array
        |       true
        |       false
        |       null { $$=$1; }
        ;
Array:
                '[' ValueList ']'
        ;

ValueList:
                %empty              { $$=newValueList(); }
        |       Value               { $$=newValueList(); $$.append($1); }
        |       ValueList ',' Value { $1.append($2); }
        ;
%%

/*
 * Epilogue */
