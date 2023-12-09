%option noyywrap
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
%}
%%
"0" {return ZERO;}
"1" {return ONE;}
%%