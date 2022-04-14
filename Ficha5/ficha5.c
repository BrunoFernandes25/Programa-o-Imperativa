#include <stdio.h>
#include <string.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

//cada miniteste vale 2 valores, logo a nota dos minitestes sera a soma dos mesmo divididos por 6 *10 para equivaler a nota de 0 a 20

//1 -------------------------------------------------------------------------------------------------------
float nota_minitestes (int miniT[] ) {
    float nota = 0.0;
    float soma = 0.0;
    int i;

    for(i=0;i<6;i++) {
        soma+= miniT[i];
    }

    nota = (soma/6.0)*10; // 6.0 pois soma é float
    printf("\nNota minitestes: %.0f\n",nota);
    return nota;
}

float nota_minitestes2 (int miniT[] ) { //apenas retirei o printf
    float nota = 0.0;
    float soma = 0.0;
    int i;

    for(i=0;i<6;i++) {
        soma+= miniT[i];
    }

    nota = (soma/6.0)*10; // 6.0 pois soma é float
    return nota;
}

int nota (Aluno a) {
    float minitestes = nota_minitestes(a.miniT);
    int nota_final;
    if(minitestes < 8 || a.teste < 8) {
        nota_final = 0;
    }
    else {
        nota_final = 0.25* minitestes + 0.75*a.teste;
        if(nota_final<10){      //chumbou logo é como se tivesse 0
            nota_final = 0;
        }
    }
    
    printf("Nota teste a PI: %.2f",a.teste);
    printf("\nNota final a PI: %d",nota_final);
    printf("\n");
    return nota_final;
}

int nota2 (Aluno a) {   //apenas retirei o printf tmb
    float minitestes = nota_minitestes2(a.miniT);
    int nota_final;
    if(minitestes < 8 || a.teste < 8) {
        nota_final = 0;
    }
    else {
        nota_final = 0.25* minitestes + 0.75*a.teste;
        if(nota_final<10){      //chumbou logo é como se tivesse 0
            nota_final = 0;
        }
    }
    return nota_final;
}


// --------------------------------------------------------------------------------------------------------
void imprimeAluno (Aluno *a){
    int i;
    printf ("%5d %s (%d", a->numero, a->nome, a->miniT[0]);   // dar print ao numero nome e primeira nota
    for(i=1; i<6; i++) printf (", %d", a->miniT[i]);         // dar print aos restantes minitestes
    printf (") %5.2f %d\n", a->teste, nota2(*a));            // dar print nota do teste e depois a nota final 
}
//---------------------------------------------------------------------------------------------------------
void swapAluno (int *x, int *y) {
    int temp;
    
    temp = *x;
    *x = *y;

    *y = temp;
}

void ordenaPorNum (Aluno t [], int N) {
    for (int i = 0; i < N-1; i++) {
        for (int j = i; j < N-1; j++) {
            if (t[j].numero > t[j+1].numero) swapAluno(&t[j].numero, &t[j+1].numero);
        }
    }
}

//numa Turma com os numeros ordenados
int procuraNum (int num, Aluno t[], int N) {
    
    ordenaPorNum (t,N);
    int r = -1;
    // int i;
    int inicio, meio, fim;

    inicio = 0;
    fim = N-1;
    meio = (fim + inicio) /2;

    while (inicio < fim && (num != t[meio].numero) ) {
        if (num < t[meio].numero) {
            fim = meio-1;
        }
        else {              // (num >= t[meio.numero])
            inicio = meio + 1;
        }
        meio = (fim + inicio)/2 ;
    }
    if ((inicio < fim) && (num == t[meio].numero) ) {
        r = meio;
    }
    if(num == t[fim].numero){
        r = fim;
    }
    return r;
}

void criaIndPorNum(Aluno t[], int N, int ind[]) {
    int i,j;
    int pos = 0;
    
    for (i=0;i<N;i++) {
        for(j=0;j<N;j++){
            if(t[i].numero>t[j].numero) {
                pos++;
            }
        }
        ind[i]=pos;
        pos = 0;
    }

    printf("{ ");
    int k;
    for(k = 0;k<N;k++){
        printf("%d ",ind[k]);
    }
    printf("}");
}

//identico ao imprime aluno
void imprimeTurma (int ind[], Aluno t[], int N) {
    ordenaPorNum(t,N);
    int i,j;
    printf("Turma:\n");
    for(i = 0; i<N;i++){
        ind[i] = i;
        printf("\n[%4d] ''%s'' {%d",t[ind[i]].numero,t[ind[i]].nome,t[ind[i]].miniT[0]);
        for(j=1; j<6; j++) printf (", %d", t[ind[i]].miniT[j]);
        printf("}");
    }
}

void criaIndPorNome(Aluno t[], int N, int ind[]) {
    int i,j;
    int pos = 0;
    
    for (i=0;i<N;i++) {
        for(j=0;j<N;j++){
            if(strcmp(t[i].nome,t[j].nome)>0) {
                pos++;
            }
        }
        ind[i]=pos;
        pos = 0;
    }

    printf("{ ");
    int k;
    for(k = 0;k<N;k++){
        printf("%d ",ind[k]);
    }
    printf("}");
}



int main () {
    
    Aluno Turma1[7] =  {{4444, "Andre", {2,1,0,2,2,2}, 10.5}
                       ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
                       ,{8888, "Carla", {2,1,2,1,0,1}, 14.5}
                       ,{2222, "Joana", {2,0,2,1,0,2},  3.5}
                       ,{7777, "Maria", {2,2,2,2,2,1},  5.5}
                       ,{6666, "Bruna", {2,2,2,1,0,0}, 12.5}
                       ,{5555, "Diogo", {2,2,1,1,1,0},  8.5}};
    

   Aluno Turma2[4] =  {{4444, "Andre", {2,1,0,2,2,2}, 10.5}
                       ,{2222, "Paulo", {0,0,2,2,2,1},  8.7}
                       ,{7777, "Carla", {2,1,2,1,0,1}, 14.5}
                       ,{3333, "Joana", {2,0,2,1,0,2},  3.5}};
                       


    //for (int i=0; i<7; imprimeAluno (Turma1 + i++));
    printf("\nNotas do Andre:\n");
    nota(Turma1[0]);
    printf("------------------------------------\n");

    printf ("Procura 1111: %d\n", procuraNum (1111, Turma1, 7));
    printf ("Procura 7777: %d\n", procuraNum (7777, Turma1, 7));
    printf("------------------------------------\n");

    int in[4];
    criaIndPorNum(Turma2,4,in); //da erro aqui no VSCode mas foi testado no C tutor e codeboar e da correto
    printf("\n------------------------------------\n");

    int ind[7];
    imprimeTurma (ind,Turma1,7);
    printf("\n------------------------------------\n");

    criaIndPorNome(Turma1,7,ind);
    printf("\n------------------------------------\n");
    return 0;
}




/*
2222 -> 0
3333 -> 1 
4444 -> 2
5555 -> 3
6666 -> 4
7777 -> 5
8888 -> 6
*/
