#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 5
/*
sizeof(LInt) tamanho do apontador 
sizeof(struct...) tamanho de tudo (valor e proximos, ou folhas da arvore)
*/

typedef struct slist {
    int valor;
    struct slist * prox;
    } * LInt;

LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x; 
        r->prox = xs; 
    }
    xs=r;
    return r;
}


LInt newLIntV2 (int x, LInt *pxs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x; 
        r->prox = *pxs; 
    }
    *pxs = r;
    return r;
}

//----------------------------------------------------------------------

typedef LInt Stack;

void initStack(Stack *s); //passado o endereço de uma lista
int SisEmpty(Stack s);
int push(Stack *s, int x);
int pop(Stack *s, int *x);
int top(Stack s, int *x);

//1
void initStack(Stack *s){
    (*s) = NULL;//iniciar stack a NULL ver folha aula
}

int SisEmpty(Stack s){
    return(s == NULL); //caso seja verdade é vazia 
}
//supostamente podemos inserir enquanto a memoria do programa tiver espaço, coisa que em arrays nao era possivel se o mesmo atingisse o limite;
//podemos ser mais rigorosos fazendo (*)
int push(Stack *s, int x){ //aqui usamos o pointer do s e nao o s
    *s=newLInt(x,*s);
    return ((*s)!= NULL? 0:1); //caso corra bem da 0
}

int pop(Stack *s, int *x){
    //so consigo retirar algo se existir elementos
    int r = 1;
    if (!SisEmpty(*s)){ //se nao for vazia
        LInt res = *s;  //auxiliar para retirar o valor e depois retornara a auxiliar e nao a lista original
        *s = (*s)->prox;
        *x = (res->valor);
        free(res); // e libertamos espaco pois ja guardamos o 20 para retirar e o s ja aponta para o proximo elemento/bloco
        r=0;
    }
    return r;
}

int top(Stack s, int *x) {
    int r = 1;
    if (!SisEmpty(s)){ //se nao for vazia
        *x = (s->valor);   // podemos usar o s e nao o *s pois aqui nao temos apontador de apontador como na anterior
        r=0;
    }
    return r;
}
//------------------------------------------------------------------------------------------------------------------------------

typedef struct {
    LInt inicio,fim;   
}Queue;

void initQueue(Queue *q);
int QisEmpty(Queue q);
int enqueue(Queue *q, int x);
int dequeue (Queue *q, int *x);
int frontQ (Queue q, int *x);

void initQueue(Queue *q){
    q->inicio = q->fim = NULL;
}

int QisEmpty(Queue q){ // passa por valor e nao por referencia dai o "."
    return (q.inicio == NULL);
}
int enqueue(Queue *q, int x) {
    LInt novo = newLInt(x,NULL); // inicio = x fim = NULL
    
    if(QisEmpty(*q)){
        q->inicio = q->fim= novo;
    }
    else { //se ja tiver valores inseridos
        q->fim->prox= novo;
        q->fim= novo;// atualizamos o fim equiv. a q->fim->prox 
    }
    return(novo!=NULL)?0:1;
}

int dequeue (Queue *q, int *x) {
    int r = 1;
    if(!QisEmpty(*q)){
        //valor na frente da fila
        *x = q->inicio->valor;
        //falra agora retirar da frente da fila
        //1. apenas 1 elem 
        //2. mais que 1 elem
        if(q->inicio == q->fim){
            free(q->inicio); // ja esta guardado o valor logo libertamos memoria
            //e iniciamos a queue a NULL para poder estar disponivel caso pprecisemos mais tarde
            q->inicio = q->fim = NULL;
        }
        else{
            LInt res = q->inicio; //nodo a eliminar;
            q->inicio = q->inicio->prox;// avancamos com o inicio, embora podesseos usar uma auxiliar
            free(res);
        }   
        r = 0;        
    }

    return r;
}

int frontQ(Queue q, int *x) {
    int r = 1;
    if(!QisEmpty(q)){
        *x= q.inicio->valor;
        r = 0;
    }
    return r;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------

typedef LInt QueueC; //ta a mais

void initQueueC(QueueC *q);
int QisEmptyC(QueueC q);
int enqueueC(QueueC *q, int x);
int dequeueC (QueueC *q, int *x);
int frontQC (QueueC q, int *x);

void initQueueC(QueueC *q) {
    (*q)=NULL;
}
int QisEmptyC(QueueC q){
    return(q ==NULL);
}
int enqueueC(QueueC *q, int x){
    if(QisEmptyC(*q)){
        *q = newLInt(x,NULL);
        (*q)->prox = *q;
    }
    else{
        (*q)->prox = newLInt (x,(*q)->prox);
        (*q) = (*q)->prox;
    }
    return ((*q) && (*q)->prox)?0:1;
}

int dequeueC (QueueC *q, int *x){
    int r = 1;
    if(!QisEmptyC(*q)){
        *x = (*q)->prox->valor; //acedemos ao ultimo e vou ao proximo(que é o primeiro ver desenho folha) e acedo ao valor
            //(*q)->prox nodo na frente da fila
        //agora retiremos esse nodo
        //1. um nodo apenas
        if((*q) == (*q)->prox){ //ver !! folha
            free(*q);
            (*q) = NULL;
        }
        //2. mais que um nodo
        else {
            LInt res = (*q)-> prox;
            (*q)->prox = (*q)->prox->prox;
            free(res);
        }
        r = 0;
    }
    return r;
}

int frontQC (QueueC q, int *x) {
    int r = 1;
    if(!QisEmptyC(q)){
        *x=q->prox->valor;
        r = 0;
    }
    return r;
}
//-------------------------------------------------------------------------------------------------
typedef struct dslist {
    int valor;
    struct dslist *ant,*prox;
} *DList;

typedef struct {
    DList rear,front; //rear = back
} Deque;
//podemos inseir e deletar em ambas as pontas do deque dai ser double ended
  
DList newDList (int x, DList xs){
    DList r = malloc(sizeof(struct dslist));
    if (r != NULL){
        r->valor=x; 
        r->prox = xs; 
        r->ant = NULL;
    }
    xs = r;
    return r;
} 

void initDeque(Deque *q);
int DisEmpty (Deque q);
int pushBack (Deque *q, int x);
int pushFront (Deque *q, int x);
int popBack (Deque *q, int *x);
int popFront (Deque *q, int *x);
int popMax (Deque *q, int *x);
int back (Deque q, int *x);
int front (Deque q, int *x);

void initDeque(Deque *q) {
    q->front = NULL;
    q->rear=NULL;
}

int DisEmpty(Deque q){
    return q.front == NULL;
}

int pushFront (Deque *q, int x) {
    DList r = malloc(sizeof(struct dslist));
    int res = 1;
    assert(r != NULL); // caso exp dentro seja True nao acontece nada senao aparece erro
    res=0;
    r->valor = x;
    r->prox = q->front;
    r->ant = NULL;
    if(q->rear == NULL) {
        q->front = q->rear = r;
    }
    else {
        q->front->ant = r;
        q->front = r;
    }
    return res;
}

int pushBack (Deque *q, int x){
	DList r = malloc(sizeof(struct dslist));
	int res = 1;
    assert(r != NULL);
    res = 0;
	r->valor = x;
	r->ant = q->rear;
	r->prox = NULL;
	if (q->front == NULL) {
		q->front = q->rear = r;
	} else {
		q->rear->prox = r;
		q->rear = r;
	}
    return res;
}

int popFront (Deque *q, int *x) {
    if (q->rear == NULL) return -1;
    
    DList temp = q->rear;
    *x = temp->valor;
    q->rear = temp->ant;
    free(temp);
    
    if (q->rear != NULL) q->rear->prox = NULL;
    else q->front = NULL;
    
    return 0;
}


int popBack (Deque *q, int *x) {
    int r = 1;
    if (!DisEmpty(*q)) {
        r = 0;
        *x = q->rear->valor;
        DList temp = q->rear;
        if (q->rear == q->front)
            q->front = NULL;
        q->rear = q->rear->prox;
        free(temp);
    }
    return r;
}




/*
dslist = node_structure
*head = front
*tail = rear

*/





//-------------------------------------------------------------------------------------------------

int main() {

    LInt lista = NULL;
    lista = newLInt(200,lista);
    newLInt(100,lista); // nao se atribui a uma lista logo vai ser ignorado, estará na memoria mas nao é possivel acede-lo

    newLIntV2(50,&lista);   //temos *pxs e a LInt tambem ja tem "*" logo é passado 2 apontadores, mudando assim o conteudo do seu endereço

    DList dlista = NULL;
    dlista = newDList(100,dlista);
    //aula
    int i,a,b;
    Stack s;
    printf("Stack:\n");
    initStack(&s);
    push(&s,1);
    push(&s,1);
    // para seq. de Fib.
    //so precisamos dos 2 primeiros valores
    for(i=0;i<10;i++) {
        pop(&s,&a);
        top(s,&b);
        push(&s,a); // b tava [errado] senao ficaria na stack 1 1 [1] 3 e nao 1 1 [2] 3
        push(&s,a+b);
    }
    while(!SisEmpty(s)){
        pop(&s,&a);
        printf("%d ", a);
    }

    Queue q;
    printf("\nQueue:\n");
    initQueue(&q);
    enqueue(&q,1);
    enqueue(&q,1);
    // para seq. de Fib.
    //so precisamos dos 2 primeiros valores
    for(i=0;i<10;i++) {
        dequeue(&q,&a);
        frontQ(q,&b);
        enqueue(&q,a); // b tava [errado] senao ficaria na stack 1 1 [1] 3 e nao 1 1 [2] 3
        enqueue(&q,a+b);
    }
    while(!QisEmpty(q)){
        dequeue(&q,&a);
        printf("%d ", a);
    }

    QueueC d;
    printf("\nDQueue:\n");
    initQueueC(&d);
    enqueueC(&d,1);
    enqueueC(&d,1);
    // para seq. de Fib.
    //so precisamos dos 2 primeiros valores
    for(i=0;i<10;i++) {
        dequeueC(&d,&a);
        frontQC(d,&b);
        enqueueC(&d,a); // b tava [errado] senao ficaria na stack 1 1 [1] 3 e nao 1 1 [2] 3
        enqueueC(&d,a+b);
    }
    while(!QisEmptyC(d)){
        dequeueC(&d,&a);
        printf("%d ", a);   // dava 1 3 2 3 1 4 3 5 2 5 3 4 porque nao é possivel aceder ao ultimo elem tamos sempre a aceder aos ultimos 2 exceto o final 
    }

    return 0;
}