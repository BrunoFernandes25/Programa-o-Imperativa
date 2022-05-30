#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//C Pointer

/*1. Write a program in C to show the basic declaration of pointer.*/

void pointerBasico(){
    int m=10;
    int n,o;
    int *z= &m;

    printf("\nPointer : Declaracoes basicas de pointers : \n");
    //dará warnings pois z é um pointer mas funciona
    printf("\nz armazena o endereco de m = %d", z);
    printf("\n*z armazena o valor de m = %d",*z);
    printf("\n&m eh o endereco de m = %d",&m);

    printf("\n\n&n eh o endereco de n = %d",&n);
    printf("\n&o eh o endereco de o = %d",&o);
    printf("\n&z ej o endereco de z = %d",&z);
}
/* Write a program in C to demonstrate the use of &(address of) and *(value at address) operator.*/

void pointerUsoDeOperadores(){
    printf("\n\nPointer : Demonstrar o uso de & e de * : \n");

    int m = 300;
    float fx = 300.600006;
    char cht = 'z';

    printf("\nUso do operador & :");
    printf("\n------------------------------------------");

    int *pm;
    float *pfx;
    char *pcht;
    //apontamos para o valor que pretendemos
    pm=&m;
    pfx = &fx;
    pcht = &cht;

    //endereços das variáveis
    printf("\nEndereco de m = %d",&m); //tendo endereco temos de ter apontadores
    printf("\nEndereco de fx = %d",&fx);
    printf("\nEndereco de cht = %d",&cht);
    //valores das variáveis
    printf("\n\nUsando operadores & e * : ");
    printf("\n------------------------------------------");
    printf("\nValor no endereco de m = %d",*(&m));
    printf("\nValor no endereco de fx = %.2f",*(&fx));
    printf("\nValor no endereco de cht = %c",*(&cht));

    printf("\n\nUsando apenas operador * :");
    printf("\n------------------------------------------");
    printf("\nEndereco de m = %d",&pm);
    printf("\nEndereco de fx = %d",&pfx);
    printf("\nEndereco de cht = %d",&pcht);
    printf("\n------------------------------------------");

    printf("\nValor no endereco de m = %d",*pm);
    printf("\nValor no endereco de fx = %.2f",*pfx);
    printf("\nValor no endereco de cht = %c\n",*pcht);
}


//For loops

/* Write a C program to display Pascal's triangle.*/

void trianguloPascal(int n){
    int i,j;
    int espacos;
    int temp = 0;
    int num = 1;
    
    for(i = 0;i<n;i++){
        for(espacos=temp;espacos<n-1;espacos++){
            printf(" ");
        }
        for(j = 0;j<=i;j++){
            if(i==0 || j==0){
                num=1;
                printf("%d",num);
            }
            else{
                num=num*(i-j+1)/j;
                printf("%4d",num); //2d ficava bem para poucas linhas apenas
            }
        }
        printf("\n");
        temp++;
    
    }
}
/*
linha 0     ____1____               //4 espacos tamanho triangulo 5
            ___1_1___
            __1_2_1_
            _1_3_3_1
linha 4     1_4_6_4_1

linha com mais 1 num sempre que o num dessa linha 
*/


//Linked lists

/* Write a program in C to create and display a Singly Linked List.*/
typedef struct node {
    int valor;
    struct node *prox;
} *LInt;

LInt createList(int n, LInt l){
    LInt r = malloc(sizeof(struct node));
    //r=l; daria "erro" pois l == NULL
    if(r != NULL){
        r->valor = n;
        r->prox = l;
    }
    return r;
}

void printLista(LInt l){
    LInt r = malloc(sizeof(struct node));
    r=l;
    //printf("Lista: ");
    while(r != NULL){
        printf("%d ",r->valor);
        r = r->prox;
    }
    if(r == NULL) printf("NULL");
    printf("\n");
}


LInt insereNoFim( int x, LInt l){
    LInt inserido, r = l; //r = l garante que nao seja perdido a cabeca da lista;
    
    if(l == NULL){ //caso a lista esteja vazia adiciona se apenas o elemento quepretendemos
        r = malloc(sizeof(struct node));
        r->valor = x;
        r->prox = NULL;  
    
    }
    else{
        while(r->prox != NULL){ //so desta fomra garantimos que conseguimos parar no ultima celula da lista antes de NULL
        r = r->prox;
        }
        //arrnajamos espaco para o novo nodo
        inserido = malloc(sizeof(struct node));
        inserido->valor = x;
        inserido->prox = NULL;
        //e passamo-lo para ser o prox da lista original já existente
        r->prox = inserido;
    }
    
    return r;
}


LInt insereNoInicio (int x, LInt l){
    LInt r;
    //alocar memoria para o valor x
    r = malloc(sizeof(struct node));
    r->valor= x;
    r->prox = NULL;

    //proximo passara a ser a lista
    r->prox = l;
    l=r;
    return l;
}

LInt removeInicio(LInt l){
    //LInt l tem de ter como valor inicial o l->prox e remover o primeiro dando free
    LInt r = l;
    if(r == NULL)return NULL;
    l=r->prox;
    free(r);
    return l; 

}

LInt removeFim(LInt l){
    LInt r = l;
    if(r ==  NULL) printf("\nLista vazia (ira printar NULL se fizermos printLista)\n");
    else{
        if(r->prox == NULL){
            //lista so tem 1 elem
            free(r);
            return NULL;
        }
        else{
            while(r->prox->prox != NULL){
                r = r->prox;
            }
            free(r->prox);
            r->prox = NULL;
        }
    }
    return r;

}

//ordenar lista


//remover elem de lista desordenada, assumindo que esse elemento existe
LInt removeElem(LInt l, int x){
    LInt r=l,ant;
    //caso a lista recebida seja NULL
    if(r==NULL){
        l = NULL;
    }
    //para remover o elemento verificamos se já encontramos o valor, e guardamos o seu anterior
    while(r->valor != x && r != NULL){
        ant = r;
        r=r->prox;
    }
    //aqui já se encontrou o valor a remover
    if(r == l){
        l=r->prox;
    }
    else{
        ant->prox = r->prox; //liga ao elemento a seguir ao que pretendemos remover
    }
    free(r);
    return l;
}


//remover elem a escolha,numa ordenada
LInt removeElemOrd(LInt l, int x){
    LInt r=l,ant = NULL;
    //caso a lista recebida seja NULL
    if(r==NULL){
        l = NULL;
    }
    //para remover o elemento verificamos se já encontramos o valor, e guardamos o seu anterior
    while((r->valor < x) && r != NULL){
        ant = r;
        r=r->prox;
    }
    //aqui já se encontrou o valor a remover
    if(r->valor == x && ant == NULL){
        l=r->prox;
        //ant->prox = r->prox;
    }
    else{
        ant->prox = r->prox; //liga ao elemento a seguir ao que pretendemos remover
    }
    free(r);
    return l;
}



//inserir elemento numa lista ordenada
//inserir 7
//10 18 20 25
LInt insereListaOrd(LInt l, int x){
    //percorremos a lista enquanto l->valor for menor a x depois adicionamo lo no respetivo lugar
    LInt r=l,ant,adicionado;
    
    adicionado = malloc(sizeof(struct node));
    //no caso de ser preciso inserir logo no inicio
    
    if(x<r->valor || r == NULL){
        adicionado->valor= x;
        adicionado->prox = r;
        r=adicionado;
    }
    else{
        while (r != NULL && r->valor<x){
            ant=r;
            r=r->prox;
        }
    //neste momemto 
    //r->valor = 25
    //ant = 20;

    //logo ant->prox=adicionado;
    
    adicionado->valor= x;
    adicionado->prox = r;

    ant->prox=adicionado;
    r=l;
    }
    return r;
}

//tamanho de uma lista ligada

int tamanhoLista(LInt l){
    int tam = 0;
    LInt r = l;
    while(r != NULL){
        tam++;
        r = r->prox;
    }
    printf("\nTamanho da lista: %d\n", tam);
    return tam;
}

//limpar lista
void freeLista(LInt l){
    LInt r=l;
    LInt lista;
    while(r != NULL){
        lista=r->prox;
        free(r);
        r = lista;
    }
}

//reverter lista
//2 7 10 18 20 22 24 25 30 NULL

LInt reverteLista(LInt l){
    LInt frente, contraria= NULL;

    while(l !=  NULL){
        frente = l->prox;
        l->prox=contraria;
        contraria=l;
        l = frente;
    }
    return contraria;
}

//remover duplicados retornando o numero de duplicados

int removeDups(LInt *l){
    int dups = 0;

    for(;*l;l=&(*l)->prox){
        LInt anterior = (*l);
        LInt seguinte = (*l)->prox;
        for(;seguinte;seguinte = anterior->prox){
            if(seguinte->valor == (*l)->valor){
                dups += 1;
                anterior->prox = seguinte->prox;
                free(seguinte);
            }
            else{
                anterior=seguinte;
            }
        }
    }
    printf("duplicados : %d", dups);
    return dups;
}

//clone de uma lista

LInt clone(LInt l){
    LInt novaLista;
    LInt *sitio;

    sitio = &novaLista;
    while(l != NULL){
        *sitio = malloc(sizeof(struct node));
        (*sitio)->valor = l->valor;
        l = l->prox;
        sitio = &((*sitio)->prox);
    }
    *sitio = NULL;
    return novaLista;
}

int maximo (LInt l){
    LInt r = l;
    int max = r->valor;
    while (r != NULL) {
        if(r->valor > max){
            max = r->valor;
        }
        r = r->prox;
    }
    printf("%d",max);
    return max;
}

//apaga todos os nodos a partir do n-esimo elemento

int take (int n, LInt *l){
    int i = 0;

    while(i<n && *l){ //vamos avançando 
        l = &((*l)->prox);
        i++;
    }

    if(!(*l)){ // se a lsita for NULL
        return i;
    }
    //caso nao seja NULL
    while (*l){
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
    }

    return i;
}

//funcao inversa da take

int drop(int n, LInt *l){

    if(!(*l)){
        return 0;
    }
    int i = 0;
    while(i<n && (*l)){
        LInt temp = (*l);
        *l = (*l)->prox;
        free(temp);
        i++;
    }
    return i;
}

//Lista para Array
int listtoArray(LInt l, int v[], int N){
    int i;
    for(i = 0;i<N && l; i++,l = l->prox){
        v[i] = l->valor;
    }
    return i;
}

//Array para lista
LInt arrayToList(int v[],int N){ 
    LInt l;
    LInt *r = &l; //aqui nao poderia ser feito de outra forma acho, pois precisamos de guardar os elementos num endereco da memoria
    int i;

    for(i = 0;i<N;i++){
        *r = malloc(sizeof(struct node));
        (*r)->valor = v[i];
        r = &(*r)->prox;
    }

    *r = NULL;
    return l;
}

//lista das somas csonsecutivas
LInt somasAcl(LInt l){
    LInt r=l,res,rr;
    int acc = r->valor;
    //inicializamos a lista rr com o primeiro valor a acumulado 
    rr = malloc(sizeof(struct node));
    rr->valor = acc;
    rr->prox  = NULL;
    r = r->prox;
    l = rr;
    while(r != NULL){
        acc += r->valor; //aqui adiciona se o valor atual em r para adicionar o valor na lista res
        //alocar memoria para o novo valor e o seu apontador proximo
        res = malloc(sizeof(struct node));
        res->valor = acc;
        res->prox = NULL;
        //avancamos com r para continuar a criar a nova lista
        rr->prox = res;
        rr = rr->prox;
        r = r->prox; //ta correto para ir percorrendo a lista

    }
         //aqui r já esta em NULL teriamos de guardar um apontador para o inicio desta lista
    return l;
}
//ou duma forma mais inteligente e reduzida
/*
LInt somasAcL(LInt l){
	LInt head;
	LInt *r = &head;

	int acc = 0;

	for(; l ; r = &(*r)->prox ){
		acc += l->valor;
		*r = malloc(sizeof(struct lligada));
		(*r)->valor = acc;
		l = l->prox;
	}

	*r = NULL;

	return head;
}
*/

//colocar o primeiro elem de uma lista no fim, nao podendo alocar nem libertar memoria

LInt rotateLista(LInt l){
    //caso a lista seja vazia ou tenha apenas um elemento, ela permanece igual
    if(l == NULL ||l->prox == NULL){
        return l;
    }
    //nos restantes casos
    LInt aux = l;
    LInt r = l->prox;

    while(aux->prox != NULL){
        aux = aux->prox;
    }
    //obtemos assim o ultimo elemento da lista que iremos trocar pelo primeiro
    aux->prox = l;//elemento  colocado no inicio da lista
    l->prox = NULL;

    return r;

}

LInt parte (LInt l){
    //{1,2,3,4,5,6} parte faz com que lista y = {2,4,6} e em x = {1,3,5}
    LInt res =l;
    LInt a,b;
    int i = 0;
    LInt r,rr;
    r = a;
    rr = b;
    r = malloc(sizeof(struct node));
    r->valor=l->valor;
    r->prox = NULL;
    
    l = l->prox;

    rr = malloc(sizeof(struct node));
    rr->valor=l->valor;
    rr->prox = NULL;
    l = r;
    LInt ll= rr;
    //avançamos duas vezes pois ja inserimos os 2 primeiros valores
    res=res->prox;
    res=res->prox;
    while(res != NULL){
        if(i % 2 == 0){
            a = malloc(sizeof(struct node));
            a->valor = res->valor;
            a->prox=NULL;
            r->prox=a;
            r = r->prox;
        }
        else{
            b = malloc(sizeof(struct node));
            b->valor= res->valor;
            b->prox = NULL;
            rr->prox=b;
            rr=rr->prox;
        }
        res = res->prox;
        i++;
    }
    return l; //funciona tanto para impares como para pares
}
//copiei
/*
LInt parte (LInt l){
    LInt head, *p = &head, *i = &l;
    int j;
    for (j = 1; *i; j++) {
        if (!(j%2)) {
            *p = *i;
            *i = (*i)->prox;
            p = &(*p)->prox;
           
        }
        else 
            i = &(*i)->prox;
    }
    *p = NULL;
    return head;
}*/


//Arvores binarias

typedef struct nodo{
    int valor;
    struct nodo *esq,*dir;
} * ABin;

ABin newABin (int r,ABin e, ABin d){
    ABin a = malloc (sizeof(struct nodo));
    if(a != NULL){
        a->valor = r;
        a->esq = e;
        a->dir = d;
    }
    return a;
}

ABin insereNodo(ABin a, int x){
    ABin  *sitio;
    sitio = &a;

    while (*sitio != NULL && (*sitio)->valor != x){
        if(x<(*sitio)->valor){
            sitio  = &((*sitio)->esq);
        }
        else{
            sitio  = &((*sitio)->dir);
        }
    }
    if(*sitio == NULL){
        *sitio = malloc(sizeof(struct nodo));
        (*sitio)->valor = x;
        (*sitio)->esq = (*sitio)->dir = NULL;
    }

    return a;
}

void printarvore(ABin a, int space) {
    int COUNT = 10;
    // caso base
    if (a == NULL)
        return;
    
    // aumenta a distancia entre niveis da arvore
    space += COUNT;
 
    // Processa lado direito da arvore primeiro
    printarvore(a->dir, space);
 
    // Printa nodo atual apos o espaco
    // conta
    printf("\n");
    int i;
    for (i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", a->valor);
 
    // Processa lado esquerdo da arvore
    printarvore(a->esq, space);
}


int altura (ABin a){
    if(a == NULL) return 0;
    int e = altura(a->esq);
    int d = altura(a->dir);
    return ((e<d) ? d :e) +1; //+1 (raiz) 
}

ABin cloneArvore(ABin a){
    ABin r = a;

    if(a == NULL){
        r = NULL;
    }
    else{
        r = malloc(sizeof(struct nodo));
        r->valor = a->valor;
        r->esq = cloneArvore(a->esq);
        r->dir = cloneArvore(a->dir);
    }
    return r;
}

//espelho de uma arvore
ABin espelho(ABin *a){
    ABin espelhada;
    
    if(*a == NULL){
        espelhada = NULL;
    }
    else{
        espelhada = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = espelhada;
        espelho(&(*a)->esq);
        espelho(&(*a)->dir);
    }
    return espelhada;
}

//free ABin
int freeAB(ABin a){
	int r = 0;

    if(a){
	    r+= 1+ freeAB(a->esq) + freeAB(a->dir);
	    free(a);
	}
    return r;
}

//liberta espaco a partir de certo nivel da arvore

int pruneAB (ABin *a, int l){
    int nvl = 0;

    if(*a == NULL){
        nvl = 0;
    }
    else{
        if(l == 0){ //toda a arvore é libertada
            nvl += 1 + pruneAB(&(*a)->esq,l) + pruneAB(&(*a)->dir,l);
            free(*a); //logo libertamos memoria da arvore toda desde a raiz
            *a = NULL;
        }
        else{
            nvl += pruneAB(&(*a)->esq,l-1);
            nvl += pruneAB(&(*a)->dir,l-1);
        }
    }

    return nvl;
}

int iguais(ABin a, ABin b){ //? da sempre 0 ver depois
	int r = 0;  

	if(!a && b || a && !b){
        r = 1;	// falso
    }
	else{
        if(!a && !b || a == b){
            r = 0;	// verdade    
        } // ambos null ou ambos não null
        else{
            r = a->valor == b->valor && iguais(a->esq, b->esq) && iguais(a->dir, b->dir);
        }
    }
	
	return r;
}
//Arvore inorder
void inorder(ABin a, LInt *l){
    if(a == NULL){
        *l = NULL;
    }
    else{
        inorder(a->esq,l);

        while(*l != NULL){
            l = &(*l)->prox;
        }

        *l=malloc(sizeof(struct nodo));
        (*l)->valor = a->valor;
        inorder(a->dir,&(*l)->prox);
    }
}

//Arvore preorder

void preorder(ABin a,LInt *l){
    if(a == NULL){
        *l = NULL;
    }
    else{
        *l = malloc(sizeof(struct nodo));
        (*l)->valor = a->valor;
        preorder(a->esq,&(*l)->prox);
        while(*l != NULL){
            l=&(*l)->prox;
        }
        preorder(a->dir,l);
    }
}

//Arvore posorder
void posorder(ABin a,LInt *l){
    if(a != NULL){
        posorder(a->esq,l);
        while(*l){
            l=&(*l)->prox;
        }
        posorder(a->dir,l);
        while(*l){
            l=&(*l)->prox;
        }
        *l = malloc(sizeof(struct nodo));
        (*l)->valor = a->valor;
        (*l)->prox = NULL;
    }
    else{
        *l = NULL;
    }
}

int contaFolhas(ABin a){
    int soma=0;

    if(a != NULL){
        if(a->esq == NULL && a->dir == NULL){
            soma=1;        
        }
        else{
            soma = contaFolhas(a->esq) + contaFolhas(a->dir);
        }
    }   
    return soma;
}

//testar se certo elemento pertence a uma arvore
int pertence(ABin a, int x){
    int r = 1;
    if(a == NULL){
        return r;
    }
    if(a->valor == x)
		r = 0;
        return r;
	if(a->valor > x){
        return pertence(a->esq ,x);
    }
	else{
        return pertence(a->dir, x);
    }

}
//determinar o nivel de certo elemento numa arvore

int depthOrd(ABin a, int x){
    int r=1;
    while(a != NULL){
        if(a->valor == x){
            return r;
        }
        else if(a->valor <x){
            r++;
            a=a->dir;
        }
        else{
            r++;
            a=a->esq;
        }
    }
    return -1;
}

//adiciona elem a arvore caso nao exista
int addOrd(ABin *a,int x){
    int r = 0;
    while(*a != NULL && r != 1){
        if(x>(*a)->valor){
            a = &(*a)->dir;
        }
        else if(x<(*a)->valor){
            a = &(*a)->esq;
        }
        else{
            r = 1;
        }
    }

    //caso seha diferente de um entao adicionam-lo
    if(r != 1){
        *a = malloc(sizeof(struct nodo));
        (*a)->valor = x;
        (*a)->esq = (*a)->dir = NULL;
    }
    return r;
}

//testar se uma arvore eh de procura

int deProcura(ABin a){//esta errada ver depois
    if(a == NULL){
        return 0; //verdade
    }
    if(a->dir != NULL && a->esq != NULL){
        if(a->dir->valor > a->valor && a->esq->valor < a->valor){
            return deProcura(a->esq) && deProcura(a->dir);
        }
        else return 1;
    }

    if(a->dir != NULL && a->valor<a->dir->valor){
        return deProcura(a->dir);
    }
    if(a->esq != NULL && a->valor > a->esq->valor){
        return deProcura(a->esq);
    }
    return 1;
}
int main(){

//--------------------------------
    pointerBasico();
    pointerUsoDeOperadores();
//--------------------------------
    printf("\n\nTriangulo de Pascal");
    trianguloPascal(10);
//--------------------------------
    //Listas
    LInt lista = NULL;
    printf("\n\n[Lista criada inicialmente] \n");
    lista = createList(5,lista); // ou fazemos assim ou entao colocamos no insereNofim lista = ....;
    printLista(lista);
    //adicionar elementos na lista 
    printf("\n[Lista com novos elementos no fim] \n");
    insereNoFim(10,lista);
    insereNoFim(15,lista);
    insereNoFim(20,lista);
    insereNoFim(25,lista);
    insereNoFim(30,lista);
    printLista(lista);
    printf("\n[Lista com novo elemento na cabeca da lista] \n");
    lista = insereNoInicio(0,lista); // aqui sou obrigado a ter lista = ...
    printLista(lista);
    printf("\n[Lista com remocao do primeiro elemento da lista] \n");
    lista = removeInicio(lista); // aqui sou obrigado a ter lista = ...
    printLista(lista);
    printf("\n[Lista com remocao do ultimo elemento da lista] \n");
    removeFim(lista);
    printLista(lista);
    printf("\n[Lista com remocao do elemento escolhido] \n");
    lista = removeElem(lista,5); //caso nao exista o n dá erro pois partimos do principio que existia
    printLista(lista);
    printf("\n[Lista com remocao do elemento escolhido numa lista Ordenada] \n");
    lista = removeElemOrd(lista,15); //nao funciona tambem para numeros inexistentes na lista
    printLista(lista);
    printf("\n[Lista com insercao do elemento escolhido numa lista Ordenada] \n");
    lista = insereListaOrd(lista,18);
    printLista(lista);
    lista = insereListaOrd(lista,22); //adiciona no sitio certo mas nao da o return correto
    printLista(lista);
    lista = insereListaOrd(lista,24);
    printLista(lista);
    lista = insereListaOrd(lista,30);
    printLista(lista);
    lista = insereListaOrd(lista,7); //da erro ao inserir no inicio
    printLista(lista);
    lista= insereListaOrd(lista,2);
    printLista(lista);
    //2 7 10 18 20 22 24 25 30 NULL
    tamanhoLista(lista);
    printf("\n[Lista pela ordem inversa]\n");
    lista = reverteLista(lista);
    printLista(lista);
    lista= insereNoInicio(20,lista);
    insereNoFim(7,lista);
    insereNoFim(20,lista);
    printf("\nDuplicados nesta lista:");
    removeDups(&lista);
    LInt lista2 =NULL;
    printf("\n\nLista clonada: ");
    lista2 = clone(lista);
    printLista(lista2);
    printf("\n\nMaximo da lista: ");
    maximo(lista2);
    printf("\n\nLista ate a posicao 7: ");
    take(7,&lista2);
    printLista(lista2);
    printf("\nLista a partir da posicao 3: ");
    drop(3,&lista2);
    printLista(lista2);
    printf("\n\n[Lista para Array]\n");
    int v[4] ;
    listtoArray(lista2,v,4); //deveriamos conseguir obter 0 por exemplo caso nao existisse mais elems na lista
    int i;
    for(i = 0; i<4; i++){
        printf("%d ",v[i]);
    }
    printf("\n\n[Array para lista]\n");
    LInt lista3 = NULL;
    lista3 = arrayToList(v,4);
    printLista(lista3);
    printf("\n[Lista das somas acumuladas]\n");
    lista3 = somasAcl(lista3);
    printLista(lista3);
    printf("\n[Lista com rotacao]\n");
    lista3 = rotateLista(lista3);
    printLista(lista3);
    insereNoFim(10,lista3);
    insereNoFim(20,lista3);
    insereNoFim(30,lista3);
    printf("\n[Lista partida(posicoes impares)]\n");
    lista3 = parte(lista3);
    printLista(lista3);
    
    
    //Arvores
    ABin arvore;
    arvore = newABin(20,NULL,NULL);
    insereNodo(arvore,10);
    insereNodo(arvore,5);
    insereNodo(arvore,15);
    insereNodo(arvore,30);
    insereNodo(arvore,25);
    insereNodo(arvore,40);
    printarvore(arvore,0);
    printf("\n\n[Altura da arvore]: %d",altura(arvore));
    ABin arvore2;
    arvore2 = cloneArvore(arvore);
    //printarvore(arvore2,0);
    printf("\n\n[Arvore espelho]\n");
    espelho(&arvore);
    printarvore(arvore,0);
    printf("\n[Arvore limpa a partir de certo nivel]\n");
    pruneAB(&arvore,2);
    printarvore(arvore,0);
    ABin arvore3;
    arvore3 = newABin(50,NULL,NULL);
    insereNodo(arvore3,30);
    insereNodo(arvore3,75);
    insereNodo(arvore3,20);
    insereNodo(arvore3,40);
    insereNodo(arvore3,50);
    insereNodo(arvore3,60);
    printf("\nAs arvores sao iguais(0): %d\n",iguais(arvore,arvore3));//deveria dar 1
    printf("As arvores sao iguais(0): %d\n",iguais(arvore,arvore2));
    //printf("\n[Arvore concatenada]\n");
    //printarvore(,0);
    LInt lista4;
    inorder(arvore,&lista4);
    printf("\n[Lista inorder da arvore]\n");
    printLista(lista4);
    printf("\n[Lista preorder da arvore]\n");
    preorder(arvore,&lista4);
    printLista(lista4);
    printf("\n[Lista posorder da arvore]\n");
    posorder(arvore,&lista4);
    printLista(lista4);
    printf("\n[Folhas da arvore:] %d\n",contaFolhas(arvore));
    printf("\n[Numero 20 pertence a arvore?(1/0)  %d]\n",pertence(arvore,20));
    printf("\n[Numero 100 pertence a arvore?(1/0) %d]\n",pertence(arvore,100));
    printf("\n[Nivel do elemento 20] %d\n",depthOrd(arvore,20));
    printf("\n[Nivel do elemento 100] %d\n",depthOrd(arvore,100));
    espelho(&arvore);
    addOrd(&arvore,50);
    printarvore(arvore,0);
    printf("\n[Arvore eh de procura(0/1)]\n  %d",deProcura(arvore));

//-----------------------------------------------------------------------
}