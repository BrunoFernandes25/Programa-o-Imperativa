#include <stdio.h>

/*
1.  1 1 4
    2 2 6
    3 3 8
    4 4 10
    5 5 12

2. i=3 j=5  a=b=42 (tem na memoria merda porque sao apontadores) a=3(a com apontador e o seu valor é &i) b=5(b com apontador e o seu valor é &j) i=4(se o i aumentou entao a aponta para i+1 tambem ) 
        j=4+5=9 (b aponta para j e &j=9)  b=4 (b=a signigica que o apontador b fica a apontar para o mesmo de a, logo o seu valor é 4) j=9+4= 13
*/

void swapM (int *x, int *y) {
    int temp;
    temp = *x;
    *x=*y;
    *y= temp;
    //printf("%d %d",*x,*y); optei por por no main assim basta aceder ao valor da variavel local em vez de retornar o apontador que ia dar ao mesmo praticamente
}

void swap (int v[],int i, int j) {
    int temp;
    temp= v[i];
    v[i]=v[j];
    v[j]= temp;
}

int soma (int v[], int N) {
    int total = 0;
    for(int i=0;i<N;i++){
        total+=v[i];
    }
    return total;
}

void invertearray (int v[],int N) {
    int i;
    int newArray[N];

    for(i=0; i<N; i++){
        newArray[i] = v[N-1-i]; //troca pos.0 com a pos.9 no caso deste array, a pos.1 com a pos.8, etc
    }

    for(i=0; i<N; i++){     //da print ao array invertido
        printf("%d ", newArray[i]);
    }
}

int maximum (int v[], int N, int *m) {
    int x;
    if (N<1) return 1;
    
    *m=v[0]; //apontador para o primeiro elem do array
    for(int i=1;i<N;i++) {        //vamos agora ver se existe algum maior que este 
        if(v[i]>*m) {
            *m=v[i];
        }
    }
    x= *m;
    printf("Maximo igual a %d",x);
    return 0;
}

void quadrados (int q[], int N) {
    for (int i=0; i<N;i++) {
        q[i] = (i+1)*(i+1);
        printf("%d ",q[i]);
    }
}
// resultado = {0,1,4,9,16,25,36,49,64,81...}

void pascal (int v[], int N) {  
    int linhaant[N-1];
    if (N==1) v[0] = 1;
    else {
        //int linhaant[N-1];    //vetor  da linha anterior
        pascal(linhaant,N-1);//guardamos a linha anterior, ter em atencao que ele vai executar pascal ate obter resultados
        v[0]=1;
        for(int i=1;i<N-1;i++) { //ciclo que prenche as posicoes entre os 1's
            v[i] = linhaant[i-1]+linhaant[i]; // calcula o valor da posicao i somando o valor anterior em cima e o valor da linha anterior à esquerda deste ultimo
        }
        v[N-1]=1;
    }
}

//tentar fazer depois em casa

int main () {

    int q;
    int x,y;
    int max;
    int tamanho;
    int array[10] = {1,2,3,4,5,6,7,8,9,0};
    int quadrado[10] = {}; //0 nao é Natural
    printf ("pergunta numero?:");
    scanf("%d\n",&q);

    switch (q) {
    case 1:
        scanf("%d %d",&x,&y);
        swapM(&x,&y);
        printf("x= %d y= %d",x,y);
    break;
    case 2: 
        scanf("%d %d",&x,&y);
        swap(array,x,y);
        printf("x= %d y= %d",array[x],array[y]);
    break;
    case 3:
        printf("Total da soma do array= %d",soma(array,5)); // bug tem que se dar enter a uma outra letra/numero
    break;
    case 4:
        scanf("%d",&tamanho);
        invertearray(array,tamanho); //com o scanf deixa de dar bug no compilador de ter que carregar 2 vezes a quetao pretendida 
    break;
    case 5: 
        maximum(array,10,&max);  // bug continua mas da correto
    break;                 //usa se &max, ou seja, o endereco de max, para depois ao ser passado o apontador comparar o valor nesse endereco apontado
    case 6:
        scanf("%d",&tamanho);
        quadrados(quadrado,tamanho); //bug na mesma quando uso arrays
    break;
    case 7:             //este já nao da bug
        scanf("%d",&tamanho);
        int array1[tamanho];
        pascal(array1,tamanho);
        for (int j=0;j<tamanho;j++) {
	        printf("%d ",array1[j]);
	    }
    break;
    }
    return 0;
}