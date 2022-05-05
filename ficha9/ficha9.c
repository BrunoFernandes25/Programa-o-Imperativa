#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *esq;
    struct nodo *esq;
} *ABin;

ABin newABin (int r,ABin e, ABin d){
    ABin a = malloc (sizeof(struct nodo));
    if(a != NULL){
        a->valor = r;
        a->esq = e;
        a->dir = d;
    }
    return a;
}
//1
//(a)
int altura (ABin a){
    if(a == NULL) return 0;
    int e = altura(a->esq);
    int d = altura(a->dir);
    return ((e<d) ? d :e) +1; //+1 (raiz) 
}
//(b)
int nfolhas (ABin a){
    if(a == NULL) return 0;
    if(a->esq == NULL && a->dir == NULL) return 1;
    return nfolhas(a->esq) + nfolhas(a->dir);
}
//(c)
ABin maisEsquerda (ABin a){
    if(a == NULL) return NULL;
    while (a->esq != NULL) {
        a= a->esq;
    }
    return a;
}
//(d)
imprimeNivel(ABIn a, int l){
    if(l == 0){
        printf("%d ", a->valor);
    }
    else if(l>0){
        if(a->esq != NULL) imprimeNivel(a->esq,l-1);
        if(a->dir != NULL) imprimeNivel(a->dir,l-1);
    }
}
//(e)
int procuraE(ABin a, int x){
    if (a == NULL) return -1;
    if(a->valor == x) return 0; // 0 == True
    int res; // ira retornar num de x que encontrar
    if(a-> esq != NULL) r+= procuraE(a->esq,x);
    if(a-> dir != NULL) r+= procuraE(a->dir,x);
    return r;
}

//2
//(a)
struct nodo *procura (ABIn a, int x){
    while(a != NULL && a->valor != x) {
        a = (a->valor > x) ? a->esq :  a->dir; //valor>x entao procuremos na esquerda, senao na direita
    } 
    return a;
}
//(b)
int nivel (ABin a ,int x) {
    int niv = 0;
    while (a != NULL && a->valor != x){
        //fazemos de forma identica ao procura e por cada vez que se avancar na arvore(ou seja descer), aumentamos um nivel, se encontrar retorna esse nivel
        a = (a->valor > x) ? a->esq : a->dir;
        niv += 1;
    }
    return (a==NULL) ? (-1) : niv;
}
//(c)
void imprimeAte (ABin a, int x) {
    if (a != NULL){
        if(a->esq != NULL) imprimeAte(a->esq,x);
        if(a->valor <x) printf(" %d ", a->valor);
        if(a->dir != NULL) imprimeAte(a->dir,x);
    }
}

