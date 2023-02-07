// Estrutura da Tabela de Simbolos

#define TAM_TAB 100
enum
{
    INT,
    LOG,
    LIXO
};
enum
{
    GLOBAL,
    LOCAL
};
enum
{
    VAR,
    FUN,
    PAR
};
enum
{
    VAL,
    REF
};

int aux, indFunc;
// #include <string.h>

struct elemTabSimbolos
{
    char id[100]; // identificador
    int end;      // endereço
    int tip;      // tipo
    int esc;      // escopo global ou local
    char rot[10];      // rotulo função
    int cat;      // categoria: variavel, funcao, parametro
    int par[20];  // lista de parametros da rotina
} tabSimb[TAM_TAB], elemTab, elemTabaux;

void lixoParametros(){
    for(int i = 0; i < TAM_TAB; i++)
       for(int j = 0; j < 20; j++)
         tabSimb[i].par[j] = LIXO;
}
int posTab = 0;

int desempilha();
void empilha(int valor);

/*void maiuscula (char *s){
    for(int i = 0; s[i]; i++)
       s[i] = toupper(s[i]);
}
*/
int buscaSimbolo(char *id)
{
    int i;
    // maiuscula(id);
    for (i = posTab - 1; strcmp(tabSimb[i].id, id) && i >= 0; i--)
        ;

    if (i == -1)
    {
        char msg[100];
        sprintf(msg, "Identificador [%s] não encontrado!", id);
        yyerror(msg);
    }

    return i;
}

void insereSimbolo(struct elemTabSimbolos elem)
{
    int i;
    // maiuscula(elem.id);
    if (posTab == TAM_TAB)
        yyerror("Tabela de Simbolos Cheia!");
    for (i = posTab - 1; strcmp(tabSimb[i].id, elem.id) && i >= 0; i--)
        ;
    // i = buscaSimbolo(elem.id);
    if (i != -1)
    {
        if(tabSimb[i].esc == elem.esc){
        char msg[200];
        sprintf(msg, "Identificador [%s] duplicado!", elem.id);
        yyerror(msg);
        }
    }

    tabSimb[posTab++] = elem;
}

void mostraTabela()
{
    puts("Tabela de Simbolos");
    puts("------------------");
    printf("\n%30s | %s | %s |   %s  |%s| %s  | %s\n", "ID", "END", "TIP", "ESC", "ROT", "CAT", "PAR");
    for (int i = 0; i < 50; i++)
        printf("---");
    for (int i = 0; i < posTab; i++)
    {
        // esc rot cat par
        printf("\n%30s | %3d | %s | %s | %s | %s  |", tabSimb[i].id, tabSimb[i].end, tabSimb[i].tip == INT ? "INT" : "LOG",
               tabSimb[i].esc == GLOBAL ? "GLOBAL" : "LOCAL", tabSimb[i].rot, tabSimb[i].cat == VAR ? "VAR" : tabSimb[i].cat == FUN ? "FUN" : "PAR"); // VAR, PRO, FUN, PAR
               if(tabSimb[i].cat == FUN)
                  for(int j = 0; j < 20 ; j++){
                    if(tabSimb[i].par[j] == INT)
                       printf("INT ");
                    if(tabSimb[i].par[j] == LOG)
                       printf("LOG ");
                    if(tabSimb[i].par[j] != INT && tabSimb[i].par[j] != LOG)
                       j = 20;
 
                  }
    }
    printf("\n");
}

// e f v palavras reservadas
// Estrutura da Pilha Semantica
//  usada para enderecos, variaveis, rotulos

#define TAM_PIL 100
int pilha[TAM_PIL];
int topo = -1;

void empilha(int valor)
{
    if (topo == TAM_PIL)
        yyerror("Pilha semântica cheia!");
    pilha[++topo] = valor;
}

int desempilha()
{
    if (topo == -1)
        yyerror("Pilha semântica vazia!");
    return pilha[topo--];
}

void testaTipo(int tipo1, int tipo2, int ret)
{
    int t1 = desempilha();
    int t2 = desempilha();
    if (t1 != tipo1 || t2 != tipo2)
        yyerror("Incompatibilidade de tipo!");
    empilha(ret);
}
//guarda o id correto para os parametros locais e para a funcao, recebendo o total de parametros + funcao e contaVar
void indicesLocais(int contPar, int funcId){
    //guarda o id da funcao e depois no for o id das variaveis ao mesmo tempo que coloca o tipo da variavel no .par da funcao
    int j = 0;
     contPar += 2;
     contPar = -1 * contPar;
     tabSimb[funcId].end = contPar;
     indFunc = contPar;
     contPar++;
    for(int i = funcId + 1; contPar <= -3; contPar++, i++, j++){
        tabSimb[i].end = contPar; 
        tabSimb[funcId].par[j] = tabSimb[i].tip;
    }
    tabSimb[funcId].par[j] = LIXO;
    

}
//ao processar os parametros da funcao o tipo de cada parametro é empilhado, assim desempilhamos e testamos com os tipos aceitos pela funcao
void confereParametros(int posFunc){
    int t1, t2, j = 0;
    for(; tabSimb[posFunc].par[j] != LIXO; j++);
       for(int i = j - 1; i >= 0; i--){
           t1 = desempilha();
           t2 = tabSimb[posFunc].par[i];
           if(t1 != t2)
              yyerror("Erro na passagem de parametro da função!");
        }
        t1 = desempilha();
        if(t1 != LIXO)
           yyerror("Erro na passagem de parametro da função2!");
}

void removeLocais(){
    for(int i = 0; i < TAM_TAB; i++){
        if(tabSimb[i].esc == LOCAL)
        {
            tabSimb[i] = elemTabaux;
            posTab--;
        }
    }
}
