#include <stdio.h>
#include <stdlib.h>

#define Max 10 //por exemplo podiamos por mais mas nao havia necessidade

//nao esquecer typedef para ser mais simples a sintaxe depois
typedef struct staticStack {
    int sp;     //percorre o numero de values que for passado ex: sp = 3 entao percorre os primeiros 3 values da stack 
    int values [Max];
} SStack;   //nao sei como colocar na main para *SStack

 void printStack (SStack *s) {
    printf("SP = %d\n",s->sp);
    printf("{");
    int i;
    for( i = 0; i < s->sp; i++) printf("%d%s", s->values[i], i == s->sp - 1 ? "" : ", ");
    printf("}\n");
}
 void initStackk (SStack *s) {
    s -> sp = 0; //usamos -> pois (*)SStack logo nao poderia ser o "." 
}
 int isEmptyy (SStack *s){
    //se o stack pointer do nulo entao está vazia
    return s -> sp == 0;
}

int push (SStack *s, int x) {
    int tam = s->sp;
    int r = 0;
    if(tam == Max) {
        r = 1;
    }
    else {
        tam = s->sp++;
        s->values[tam] = x;
    }
    return r;
}

int pop (SStack *s, int *x) {
    int r = 0;
    int tam = --(s-> sp);
    if (tam == 0) {
        r=1;
    }
    else {
        *x = s->values[tam];
    }
    return r;
}

int top (SStack *s, int *x) {
    int r = 0;
    int tam = s->sp;
    if (isEmptyy(s)) { //nao for vazia 
        r = 1;
    }
    else {
        *x = s->values[tam-1]; //se fosse igual a tam nao iriamos tar a olhar para o elem do topo pois já o teriamos ultrapassado
    }
    return r;
}
//-----------------------------------------------------------------------------------------------------------------------------------------

typedef struct staticQueue {
    int inicio;
    int tam;
    int valores[Max];
} SQueue;

void printQueue (SQueue *q) {
    printf("{");
    int j;   
    for(j = 0; j < q->tam; j++) printf("%d%s",q->valores[q->inicio + j],j == q->tam - 1 ? "" : ", ");
    printf("}\n");
}

void initQueue (SQueue *q) {
    q-> tam = 0;
}

int isEmptyQ (SQueue *q) {
    return q->tam == 0;
}

int enqueue (SQueue *q, int x) {
    int r = 0;
    if (q->inicio + q->tam >= Max) {
        r = 1;
    }
    else {
        q->valores[q->inicio + q->tam++] = x; // tam++ para acrescentar o elem x na posicao seguinte
    }
    return r;
}

int dequeue (SQueue *q, int *x) {   //remove o do inicio 
    int r = 0;
    int tam = q->tam--;
    int tamanho = tam - q->inicio;
    if (isEmptyQ(q)) {
        r = 1;
    }
    else {
        *x = q->valores[q->inicio++];
    }
    return r;
}

int inicio (SQueue *q, int *x) {
    int r = 0;
    if(isEmptyQ(q)){
        r = 1;
    }
    else {
        *x=q->valores[q->inicio];
    }
    return r;
}
//-----------------------------------------------------------------------------------------------------------------------------------------

typedef struct dinStack {
    int size;
    int sp;      
    int *values;
} DStack;   

 void printStack2 (DStack *s) {
    printf("SP = %d\n",s->sp);
    printf("{");
    int i;
    for( i = 0; i < s->sp; i++) printf("%d%s", s->values[i], i == s->sp - 1 ? "" : ", ");
    printf("}\n");
}

void initDStackk (DStack *s) {
    s -> sp = 0; //usamos -> pois (*)SStack logo nao poderia ser o "." 
    s -> size = 1;
    s -> values = (int*)malloc(sizeof(int));
}

 int isEmptyyy (DStack *s){
    //se o stack pointer do nulo entao está vazia
    return s -> sp == 0;
}

int pushh (DStack *s, int x) {
    if (s->size <= s-> sp) {    // ou seja se nao houver mais espaco(size) teremos que acrescentar, duplicando
        s->values = (int*)realloc(s->values, 2* s->size * sizeof(int));
    }
    //se nao for preciso entao damos so push a stack ja existente
    s->values[s->sp++] = x;
    return 0;
}

int popp (DStack *s, int *x) {
    int r = 0;
    if (isEmptyyy(s)) {
        r = 1;
    }
    else {
        *x = s->values[--(s->sp)];
    }
    return r;
}

int topp (DStack *s, int *x) {
    int r = 0;
   
    if (isEmptyyy(s)) { //nao for vazia 
        r = 1;
    }
    else {
        *x = s->values[s->sp-1]; //se fosse igaul a tam nao iriamos tar a olhar para o elem do topo pois já o teriamos ultrapassado
    }
    return r;
}
//-----------------------------------------------------------------------------------------------------------------------------------------

typedef struct dinQueue {
    int size;       //guarda o tamanho do array values      (2º elem da representacao do queue static)
    int inicio;
    int tam;      //tamanho da Queue dinamica completa
    int *values;
} DQueue;

void printQueue2 (DQueue *q) {
    printf("{");
    int j;   
    for(j = 0; j < q->tam; j++) printf("%d%s",q->values[q->inicio + j],j == q->tam - 1 ? "" : ", ");
    printf("}\n");
}

void initDQueue (DQueue *q) {
    q-> size = 0;
    q-> inicio = 0;
    q-> tam = 0;
    q-> values = malloc (q->size *sizeof(int));
}

int isEmptyQQ (DQueue *q) {
    return q->tam == 0;
}


int enqueuee (DQueue *q, int x) {
  
    if(q->size <= q->inicio + q->tam) { //que significa que já nao há mais espaço
        q->values = (int*) realloc(q->values,2 * q->size * sizeof(int));
        q->size *= 2;
    }
    //caso haja espaço
    q->values[q->inicio + q->tam++] = x;
    
    return 0;
}



int main () {
    printf("-------------------------------- Stack ---------------------------------\n");
    SStack stack1 = {3,{1,2,3}};
    
    printStack(&stack1);
    putchar('\n');
    
    initStackk(&stack1);
    printStack(&stack1);
    if(isEmptyy(&stack1)){
        printf("True\n");
    }
    else {
        printf("False\n");
    };
    putchar('\n');

    SStack stack2 = {9,{1,2,3,4,5,6,7,8,9}};
    int num1= 10;
    push (&stack2,num1);
    printf("Valor adicionado: %d\n",num1);
    printStack(&stack2);
    putchar('\n');

    int num2;
    pop(&stack2,&num2);
    printf("Valor removido: %d\n",num2);
    printStack(&stack2);
    putchar('\n');
    
    top(&stack2,&num2);
    printf("Valor no topo da stack: %d\n",num2);
    printStack(&stack2);
//----------------------------------------------------------------------------------------------------
    printf("-------------------------------- QUEUE ---------------------------------\n");
    SQueue queue1 = {1,3,{1,2,3,4,5}}; // = {2,3,4}
    
    printQueue(&queue1);
    putchar('\n');
    
    initQueue (&queue1);
    printQueue(&queue1);
    if(isEmptyQ(&queue1)){
        printf("True\n");
    }
    else {
        printf("False\n");
    };
    putchar('\n');

    SQueue queue2 = {1,4,{1,2,3,4,5}};
    int num3 = 6;
    enqueue(&queue2,num3);
    printf("Valor adicionado: %d\n",num3);
    printQueue(&queue2);
    putchar('\n');
    
    int num4;
    dequeue (&queue2,&num4);
    printf("Valor removido: %d\n",num4);
    printQueue(&queue2);
    putchar('\n');
    
    inicio (&queue2,&num4);
    printf("Valor inicial: %d\n", num4);
    printQueue(&queue2);
    putchar('\n');
//----------------------------------------------------------------------------------------------------
    printf("-------------------------------- Stack2 ---------------------------------\n");
    DStack stack3;
    stack3.size = stack3.sp = Max;
    stack3.values = (int*)malloc(Max*sizeof(int));
    int k;
    for (k = 0; k<Max;k++) {
        stack3.values[k] = k; // escolher igual ao que queremos para preencher a stack
    }
    DStack stack4 = stack3;

    printStack2(&stack3);
    putchar ('\n');

    initDStackk(&stack3);
    printStack2(&stack3);
    if(isEmptyyy(&stack3)){
        printf("True\n");
    }
    else {
        printf("False\n");
    };
    putchar('\n');

    pushh (&stack4,10);
    printStack2(&stack4);
    putchar ('\n');

    int num5;
    popp (&stack4,&num5);
    printf("Valor removido: %d\n",num5);
    printStack2(&stack4);
    putchar ('\n');

    int num6;
    topp (&stack4,&num6);
    printf("Valor no topo da stack: %d\n",num6);
    printStack2(&stack4);
    putchar ('\n');

//----------------------------------------------------------------------------------------------------
    
    printf("-------------------------------- QUEUE2 ---------------------------------\n");
    DQueue queue3;
    queue3.tam = Max;
    queue3.inicio = 0 ;
    queue3.size  = Max;
    queue3.values= malloc(Max *sizeof(int));
    int l;
    for(l=0;l<Max;l++) {
        queue3.values[l] = 2*(l+1); //numeros pares
    }
    printQueue2(&queue3);
    putchar ('\n');

    DQueue queue4 = queue3;
    
    initDQueue (&queue3);
    printQueue2(&queue3);
    if(isEmptyQQ (&queue3)){
        printf("True\n");
    }
    else {
        printf("False\n");
    };
    putchar('\n');

    printQueue2(&queue4);
    
    enqueuee (&queue4,22);
    printQueue2(&queue4);
    
    putchar('\n');


    return 0;

}