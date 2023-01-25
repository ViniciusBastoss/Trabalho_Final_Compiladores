// Estrutura da Tabela de Simbolos

#define TAM_TAB 100
enum {INT, LOG};
enum {GLOBAL, LOCAL};
enum {VAR, PRO, FUN, PAR}; 
enum {VAL, REF};
//#include <string.h>

typedef struct list{
    int tipo;
    struct list *prox;
}lista; 

struct elemTabSimbolos {
    char id[100];  // identificador
    int end;       // endereço
    int tip;       // tipo
    int esc;       //escopo global ou local
    int rot;       //rotulo função
    int cat;       //categoria: variavel, procedimento, funcao, parametro
    lista *par;    //lista de parametros da rotina
} tabSimb[TAM_TAB], elemTab;

int posTab = 0;

int desempilha();
void empilha (int valor);

/*void maiuscula (char *s){
    for(int i = 0; s[i]; i++)
       s[i] = toupper(s[i]);
}
*/
int buscaSimbolo(char *id){
    int i;
    //maiuscula(id);
    for (i = posTab - 1; strcmp(tabSimb[i].id, id) && i >= 0; i--);

    if(i == -1)
    {
        char msg[100];
        sprintf(msg, "Identificador [%s] não encontrado!", id);
        yyerror(msg);
    }
 
    return i;
}

void insereSimbolo (struct elemTabSimbolos elem){
    int i;
    //maiuscula(elem.id);
    if(posTab == TAM_TAB)
        yyerror("Tabela de Simbolos Cheia!");
    for (i = posTab - 1; strcmp(tabSimb[i].id,elem.id) && i >= 0; i--);
    //i = buscaSimbolo(elem.id);
    if( i != -1)
    {
        char msg[200];
        sprintf(msg, "Identificador [%s] duplicado!", elem.id);
        yyerror(msg);
    }
       
    tabSimb[posTab++] = elem;

}

void mostraTabela(){
    puts("Tabela de Simbolos");
    puts("------------------");
    printf("\n%30s | %s | %s \n", "ID", "END", "TIP");
    for(int i = 0; i < 50; i++)
        printf("-");
    for(int i = 0; i < posTab; i++)
        printf("\n%30s | %3d | %s", tabSimb[i].id, tabSimb[i].end, tabSimb[i].tip == INT? "INT" : "LOG");
    printf("\n");
}

//e f v palavras reservadas
//Estrutura da Pilha Semantica
// usada para enderecos, variaveis, rotulos

#define TAM_PIL 100
int pilha[TAM_PIL];
int topo = -1;

void empilha (int valor){
    if(topo == TAM_PIL)
       yyerror("Pilha semântica cheia!");
    pilha[++topo] = valor;
}

int desempilha(){
    if (topo == -1)
       yyerror("Pilha semântica vazia!");
    return pilha[topo--];
}


void testaTipo(int tipo1, int tipo2, int ret){
    int t1 = desempilha();
    int t2 = desempilha();
    if (t1 != tipo1 || t2 != tipo2)
       yyerror("Incompatibilidade de tipo!");
    empilha(ret);
}


