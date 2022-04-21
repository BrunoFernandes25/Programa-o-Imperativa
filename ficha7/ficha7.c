#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

// ou davamos so free(l); nem if se fazia 

int quantasP (Palavras l) {
    Palavras aux = l;
    int r = 0;
    while(aux != NULL){
        r+=1;
        aux=aux->prox;
    }
    return r;
}

char *ultima (Palavras l) {
    Palavras aux = l;
    char *pal = NULL; // iniciamos a NULL como é habitual 

    while(aux != NULL) {
        pal = aux->palavra; //colocamos a palavra encontrada no auxiliar 
        aux = aux->prox;    //e avançamos
    }
    printf("Ultima palavra: %s\n", pal);
    return pal;
}

Palavras acrescentaInicio (Palavras lst, char *p) {
    Palavras nova = malloc(sizeof(struct celula)); //Palavras daria erro e nao teria tamanho suficiente, assim teremos a certeza de ter o tamanho de um inteiro(ocorrencia) e da string
    nova->ocorr = 1;
    nova->palavra = p;  //ou strdup(p) cria assim uma copia do conteudo tornando mais rigoroso o codigo mas duplica se o espaço
    nova->prox = lst; // que é o nosso disc, e corresponde ao inicio da lista
    lst = nova;

    return lst;
}

Palavras acrescentaFim (Palavras lst, char *p) {
    Palavras nova = malloc(sizeof(struct celula)); //Palavras daria erro e nao teria tamanho suficiente, assim teremos a certeza de ter o tamanho de um inteiro(ocorrencia) e da string
    nova->ocorr = 1;
    nova->palavra = p;  //ou strdup(p) cria assim uma copia do conteudo tornando mais rigoroso o codigo mas duplica se o espaço
    nova->prox = NULL; // que é o nosso disc, e corresponde ao inicio da lista
    if(lst == NULL) {
        lst = nova;
    } 
    else {
        Palavras aux = lst;
        while((aux->prox != NULL)) {
            aux = aux->prox;
        }
        //no fim do ciclo o aux aponta para a ultima celula da lista
        aux->prox = nova;
    }
    return lst;   
}   
    /* ou
    criar uma funcao antes desta, por cima 
    struct celula *novaCelula(char *p){
        Palavras nova= malloc(sizeof(struct celula));
        nova->palavra = p;
        nova->ocorr = 1;
        nova->prox = NULL;
        return nova;
    }

    no if{
        lst = novaCelula(p); //nova;
    }
    e  no else {
        Palavras nova = novaCelula(p);
        nova->prox = aux->prox;
        aux->prox = nova;
    }

     e colocar no else desta o que ta em baixo
    else {
        Palavras aux = lst;
        while((aux->prox != NULL) && (strcmp(p,aux->palavra)>0)) {
            aux = aux->prox;
        }
        if(strcmp(p,aux->palavra) == 0){ //ou seja ja existe
            aux->ocorr++;
        }
        nova->prox = aux->prox;
        aux->prox = nova;
    }
    */

// alternativa a minha funcao listaPal(muito identica)
void listaPal (Palavras lst) {
    Palavras aux = lst;
    putchar('\n'); // apenas para ser lido de forma mais agradavel ao executar
    while(aux != NULL) {
        printf("-> '%s' [%d]\n",aux->palavra,aux->ocorr);
        aux = aux->prox;
    }
}

void libertalista2 (Palavras l){
  if(l != NULL){
     libertalista2(l-> prox);
     free(l);
  }
}

struct celula * maisFreq (Palavras l) {
    Palavras aux = l;
    if(aux == NULL){
        return NULL;
    }
    //caso contrário
    char* r = aux->palavra;         //primeira palavra que aparece em l
    int max = aux->ocorr;

    for(;aux!=NULL;aux=aux->prox){
        if(aux->ocorr>max){
            r = aux->palavra;    //guardamos em r a palavra mais frequente
            max = aux->ocorr;   //e o numero das suas ocorrencias

        }
    }
    //falta agora criar a struct para dar return
    aux = acrescentaInicio(aux,r);
    return aux;
}

struct celula * maisFreq (Palavras l){
    int r = 0;
    Palavras t = l;
    struct celula *res = NULL;
    
    while (t != NULL) {
        if (t->ocorr > r) {
            r = t->ocorr;
            res = t;
        }
        t = t->prox;
    }
    
    return res;
}


int main () {
    Palavras dic = NULL;
    
    char* canto1[6] = {"as","armas","os","os","baroes","assinalados"};
                        //completar poema depois e colocar 44

    int i;
    struct celula *p;

    //--------------------------------------------------------------------
    Palavras dicc = dic;
    for(i=0;i<6;i++){
        dicc=acrescentaInicio(dicc,canto1[i]);
    }
    printf("\nDicionario(acrescentaInicio): ");
    Palavras aux1 = dicc;   //para o ciclo while
    while(aux1 != NULL){            
        printf("%s ",aux1->palavra);
        aux1 = aux1->prox; 
    }
    libertalista2(dic);
    //--------------------------------------------------------------------
    dic = NULL;
    
    Palavras diccc = dic;
    for(i=0;i<6;i++){
        diccc=acrescentaFim(diccc,canto1[i]);
    }
    printf("\nDicionario(acrescentaFim): ");
    Palavras aux2 = diccc; //para o ciclo while
    Palavras aux3 = diccc;
    while(aux2 != NULL){            
        printf(" %s ",aux2->palavra);
        aux2 = aux2->prox;
    }
    //--------------------------------------------------------------------
    //ja podemos usar diccc nas funcoes pois nas mesmas usamos auxiliares para percorrer a struct Palavras e aqui na main ja criei a aux2 = diccc para dar print
    printf("\nQuantas palavra tem o dicionario apos inserirmos no fim?: %d ",quantasP(diccc));
    putchar('\n');
    printf("Palavras existentes:\n");
    listaPal(diccc);
    putchar('\n');
    //ate aqui tudo bem e dicc != NULL pois usamos auxiliares(o mesmo para o diccc)
    
    //libertalista2(aux3); 
    ultima (aux3); //dava erros com o liberta antes dela tive que colocar no inicio e depois iniciar dic=NULL(num outro espaco de memoria pois perdemos o acesso ao anterior)
    //--------------------------------------------------------------------
    //corrigir esta funcao depois nao retorna corretamente
    p = maisFreq(dicc); // guarda o primeiro elem em caso de ter mesmas ocorrencias
    printf("Palavra mais frequente: '%s' com [%d] vezes.\n\n",p->palavra,p->ocorr);
    return 0;

}