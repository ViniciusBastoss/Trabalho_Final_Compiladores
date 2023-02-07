%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lexico.c"
#include "utils.c"
int contaVar, contaVarLocal = 0;  //conta numero de variaveis
int contParam = 0;
int rotulo = 0; //marca lugares no codigo
int tipo, escopo = GLOBAL;
char charNome[10], charAux[20];
%}

%token T_PROGRAMA
%token T_INICIO
%token T_FIM
%token T_LEIA
%token T_ESCREVA
%token T_SE
%token T_ENTAO
%token T_SENAO
%token T_FIMSE
%token T_ENQTO
%token T_FACA
%token T_FIMENQTO
%token T_INTEIRO
%token T_LOGICO
%token T_MAIS
%token T_MENOS
%token T_VEZES
%token T_DIV
%token T_ATRIBUI
%token T_MAIOR
%token T_MENOR
%token T_IGUAL
%token T_E
%token T_OU
%token T_NAO
%token T_ABRE
%token T_FECHA
%token T_V            
%token T_F
%token T_IDENTIF
%token T_NUMERO
%token T_FUNC
%token T_FIMFUNC
%token T_RETORNE



%start programa
%expect 1

%left T_E T_OU
%left T_IGUAL
%left T_MAIOR T_MENOR
%left T_MAIS T_MENOS
%left T_VEZES T_DIV

%%

programa 
    : cabecalho 
        {contaVar = 0;}
      variaveis 
        { 
            mostraTabela();
            empilha(contaVar);
            if(contaVar){
               fprintf(yyout,"\tAMEM\t%d\n", contaVar); 
            }
        }
       rotinas
      T_INICIO lista_comandos T_FIM
        { 
            int conta = desempilha();
            if (conta)
               fprintf(yyout,"\tDMEM\t%d\n", conta); 
            fprintf(yyout, "\tFIMP\n");    
        }
    ;

rotinas
    :
    | 
    {
        //desvio sempre para inicio programa
        fprintf(yyout,"\tDSVS\tL%d\n", rotulo);
        empilha(rotulo);
    } 
    
    lista_rotinas

    {
        //marca inicio do programa (main)
        int rot = desempilha();
        fprintf(yyout,"L%d\tNADA\n", rot); 
    }
    ;

lista_rotinas
     : lista_rotinas rotina
     |rotina

     ;

rotina
     :{
        //marca a funcao e guarda seu rotulo
        fprintf(yyout,"L%d\tENSP\n", ++rotulo);
        strcpy(elemTab.rot,"L");
        sprintf(charAux, "%d", rotulo);
        strcat(elemTab.rot, charAux); 
      }
     funcao
 /*    
funcoes
    :funcoes funcao*/

funcao
     : T_FUNC tipo T_IDENTIF 
     {
           strcpy(elemTab.id, atomo);
           strcpy(charNome, atomo);
           contParam++;
           elemTab.tip = tipo;
           elemTab.esc = escopo;
           elemTab.cat = FUN;
           insereSimbolo(elemTab);
           escopo = LOCAL;
           strcpy(elemTab.rot,"");
     }
      T_ABRE lista_parametros T_FECHA
      variaveis 
        {
            //printf("\n%d %d\n", contParam, contaVar);
           indicesLocais(contParam, contaVar);
           mostraTabela(); 
           //empilha(contaVarLocal);
           if(contaVarLocal){
               fprintf(yyout,"\tAMEM\t%d\n", contaVarLocal); 
            }
        }
      T_INICIO lista_comandos T_FIMFUNC 
        { 
            escopo = GLOBAL;
            removeLocais();
            mostraTabela();
            contaVar += contParam - 1;
            contaVarLocal = 0;
            contParam = 0;
        }

lista_parametros
       :
       | parametro lista_parametros
       ;

parametro
       : tipo T_IDENTIF
         { 
           strcpy(elemTab.id, atomo);
           contParam++;
           elemTab.tip = tipo;
           elemTab.esc = escopo;
           elemTab.cat = PAR;
           insereSimbolo(elemTab);
         }

cabecalho
    : T_PROGRAMA T_IDENTIF
        {fprintf(yyout,"\tINPP\n"); }
    ;

variaveis
    : /* vazio */
    | declaracao_variaveis
    ;

declaracao_variaveis
    : tipo lista_variaveis declaracao_variaveis
    | tipo lista_variaveis
    ;

tipo
   : T_LOGICO
     { tipo = LOG; }
   | T_INTEIRO
    { tipo = INT;}
   ;

lista_variaveis
    : lista_variaveis T_IDENTIF 
         { 
           strcpy(elemTab.id, atomo);
           elemTab.tip = tipo;
           elemTab.esc = escopo;
           elemTab.cat = VAR;
           if(escopo == LOCAL){
               contaVarLocal++;
           }
           else{
               elemTab.end = contaVar;
               contaVar++;         
           }
           insereSimbolo(elemTab);  
         }
    | T_IDENTIF
        { 
           strcpy(elemTab.id, atomo);
           elemTab.tip = tipo;
           elemTab.esc = escopo;
           elemTab.cat = VAR;
           if(escopo == LOCAL){
               elemTab.end = contaVarLocal;
               contaVarLocal++;
           }
           else{
               elemTab.end = contaVar;
               contaVar++;         
           }
           insereSimbolo(elemTab);   
        }
    ;

lista_comandos
    : /* vazia */
    | comando lista_comandos
    ;

comando
    : entrada_saida
    | repeticao
    | selecao
    | atribuicao
    | retorne

retorne 
     :T_RETORNE expressao
    {
       if(escopo == LOCAL){
           fprintf(yyout,"\tARZL\t%d\n", indFunc);
       }
          
       else
           yyerror("Erro lexico!");
        desempilha();

        if (contaVarLocal)
           fprintf(yyout,"\tDMEM\t%d\n", contaVarLocal);
        if(contParam - 1)    
           fprintf(yyout,"\tRTSP\t%d\n", contParam - 1);
    }
    ;

entrada_saida
    : leitura
    | escrita
    ;

escrita 
     : T_ESCREVA  expressao
       {
        desempilha();
        fprintf(yyout, "\tESCR\n");
       }
 
    ;

leitura
    : T_LEIA T_IDENTIF
        { 
            int pos = buscaSimbolo(atomo);
            if(tabSimb[pos].esc == GLOBAL)
              fprintf(yyout,"\tLEIA\n\tARZG\t%d\n", tabSimb[pos].end); 
            else
              fprintf(yyout,"\tLEIA\n\tARZL\t%d\n", tabSimb[pos].end); 
        }
    ;


repeticao
    : T_ENQTO 
        { 
            fprintf(yyout,"L%d\tNADA\n", ++rotulo); 
            empilha(rotulo);
        }
      expressao T_FACA 
        {
             int tip = desempilha();
             if(tip != LOG)
                 yyerror("Incompatilidade de tipo");
             fprintf(yyout,"\tDSVF\tL%d\n", ++rotulo);
             empilha(rotulo);
        }
      lista_comandos 
      T_FIMENQTO
         { 
            int rot1 = desempilha();
            int rot2 = desempilha();
            fprintf(yyout,"\tDSVS\tL%d\n",rot2);
            fprintf(yyout,"L%d\tNADA\n",rot1);
         }
    ;

selecao
    : T_SE expressao T_ENTAO 
        {
             int tip = desempilha();
             if(tip != LOG)
                 yyerror("Imcompatilidade de tipo");
             fprintf(yyout,"\tDSVF\tL%d\n", ++rotulo);
             empilha(rotulo);
        }
      lista_comandos T_SENAO 
        { 
            int rot = desempilha();
            fprintf(yyout,"\tDSVS\tL%d\n", ++rotulo);
            fprintf(yyout,"L%d\tNADA\n", rot);
            empilha(rotulo);
        }
      lista_comandos T_FIMSE
        { 
            int rot = desempilha();
            fprintf(yyout,"L%d\tNADA\n", rot); 
        }
    ;

atribuicao
    : T_IDENTIF 
        {
            int pos = buscaSimbolo(atomo);
            empilha(pos);
        }   
      T_ATRIBUI expressao
        {
            int tip = desempilha();
            int pos = desempilha();
            if (tabSimb[pos].tip != tip)
               yyerror("Incompatibilidade de tipo!");
            if(tabSimb[pos].esc == GLOBAL)
              fprintf(yyout,"\tARZG\t%d\n", tabSimb[pos].end); 
            else
              fprintf(yyout,"\tARZL\t%d\n", tabSimb[pos].end); 

        }
    ;

expressao
    : expressao T_VEZES expressao
        {
            testaTipo(INT,INT, INT);
            fprintf(yyout,"\tMULT\n"); 
        }
    | expressao T_DIV expressao
        {
            testaTipo(INT,INT, INT);
            fprintf(yyout,"\tDIVI\n"); 
        }
    | expressao T_MAIS expressao
        {
            testaTipo(INT,INT, INT);
            fprintf(yyout,"\tSOMA\n"); 
        }
    | expressao T_MENOS expressao
        {
            testaTipo(INT,INT, INT);
            fprintf(yyout,"\tSUBT\n");
        }
    | expressao T_MAIOR expressao
        {
            testaTipo(INT,INT, LOG);
            fprintf(yyout,"\tCMMA\n"); 
        }
    | expressao T_MENOR expressao
        {
            testaTipo(INT,INT, LOG);
            fprintf(yyout,"\tCMME\n");
        }
    | expressao T_IGUAL expressao
        {
            testaTipo(INT,INT, LOG);
            fprintf(yyout,"\tCMIG\n"); 
        }
    | expressao T_E expressao 
        {
            testaTipo(LOG, LOG, LOG);
            fprintf(yyout,"\tCONJ\n"); 
        }
    | expressao T_OU expressao
        {
            testaTipo(LOG, LOG, LOG);
            fprintf(yyout,"\tDISJ\n"); 
        }
    | termo

   /* | chamada_func{
        int tip = buscaSimbolo(charNome);
        tip = tabSimb[tip].tip;
        empilha(tip);
        }  */  
    ;



identificador
   : T_IDENTIF
   {
    int pos = buscaSimbolo(atomo);
    empilha(pos);
   }
   ;

chamada:
    | T_ABRE {
        aux = desempilha();
        empilha(LIXO);
        fprintf(yyout,"\tAMEM\t1\n");
    }
        
     lista_argumentos T_FECHA
     {
        confereParametros(aux);
        empilha(aux);
     }
;

lista_argumentos
     : argumento lista_argumentos
     |
     ;

argumento
     :expressao
     ;

termo
    : identificador chamada{
        int pos = desempilha();
        if(tabSimb[pos].cat != FUN){
            if(tabSimb[pos].esc == GLOBAL)
              fprintf(yyout,"\tCRVG\t%d\n", tabSimb[pos].end); 
            else
               fprintf(yyout,"\tCRVL\t%d\n", tabSimb[pos].end);
            empilha(tabSimb[pos].tip);            
        }
        else{
            if(tabSimb[pos].cat == FUN){
                  fprintf(yyout,"\tSVCP\n");
                  fprintf(yyout,"\tDSVS\t%s\n",tabSimb[aux].rot);
                  empilha(tabSimb[pos].tip);
            }

        }
    }
    | T_NUMERO
        {
        fprintf(yyout,"\tCRCT\t%s\n", atomo);
        empilha(INT);
        }
    | T_V
        {
        fprintf(yyout,"\tCRCT\t1\n"); 
        empilha(LOG);
        }
    | T_F
        {
        fprintf(yyout,"\tCRCT\t0\n"); 
        empilha(LOG);
        }
    | T_NAO termo
        {
        int t = desempilha();
        if (t != LOG) yyerror ("Incompatibilidade de tipo!");
        fprintf(yyout,"\tNEGA\n"); 
        empilha(LOG);
        }
    | T_ABRE expressao T_FECHA
    ;
%%



int main(int argc, char *argv[]){
    char *p, nameIn[100], nameOut[100];
    argv++;
    if(argc < 2){
        puts("\nCompilador Simples\n");
        puts("\n\tUso: ./simples <NOME>[.simples]/n/n");
        exit(10);
    }
    p = strstr(argv[0], ".simples");
    if(p) *p = 0;
    strcpy(nameIn, argv[0]);
    strcat(nameIn, ".simples");
    strcpy(nameOut, argv[0]);
    strcat(nameOut, ".mvs");
    yyin = fopen(nameIn, "rt");
    if(!yyin){
        puts("Programa fonte não encontrado!");
        exit(20);
    }
    yyout = fopen(nameOut,"wt");
    yyparse(); /*LR melhorado*/
    puts("Programa ok!");
}