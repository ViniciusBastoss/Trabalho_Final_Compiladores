%%
#[a-z0-9A-Z]+   printf("pamonha");
.           ;
\n          ;
%%
int yywrap (){ return 1;}
int main (){
    yylex();
}
