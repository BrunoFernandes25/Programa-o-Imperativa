#include <stdio.h>

/* Write a program in C to make such a pattern like a pyramid
with numbers increased by 1 */

void piramide (int n) { //n= nº de linhas
    int i=0;
    int j=0;
    int k;
    int espacos= n-1;
    int num=1;

    for (i=0;i<n;i++) { //linhas
        for(k= espacos;k>0;k--) {    //em vez de analisar por coluna, vamos analisar por linha
           printf(" ");
        } 
        for(j=0;j<i+1;j++){
            printf("%d ",num);
            num++;
        }
    putchar('\n');
    espacos--;
    }
    putchar('\n');
}

void piramide_repete (int n) { //n= nº de linhas
    int i=0;
    int j=0;
    int k;
    int espacos= n-1;
    int num=1;

    for (i=0;i<n;i++) { //linhas
        for(k= espacos;k>0;k--) {    //em vez de analisar por coluna, vamos analisar por linha
           printf(" ");
        } 
        for(j=0;j<i+1;j++){
            printf("%d ",num);
        }
    putchar('\n');
    num++;
    espacos--;
    }
    putchar('\n');
}

void triangulo_Floyd (int n) {
    int i,j,p,q;
    for(i=1;i<=n;i++){
        if(i%2==0) { //linha par 
            p=1;q=0;
        }
        else {      //linha impar
            p=0;q=1;
        }
    for(j=1;j<=i;j++){
	    if(j%2==0)      //colunas pares
	        printf("%d",p);
	    else
	        printf("%d",q); //colunas impares
    }                       //tendo em conta as linhas
    printf("\n");
   }
    putchar('\n');
}

void soma_impares (int n) {
    int i;
    int impar=0;
    int k=1;
    printf("Os numeros impares sao: ");

    for(i=0;i<n;i++) {
        printf("%d ",k);
        impar+=k;
        k+=2;
    }   
    printf("\nA soma do numero natural impar ate %d termos: %d",n,impar);
    putchar('\n');    
}

void numeros_perfeitos (int min, int max) { //intervalo de [n,m]
    int soma;
    int k;
    int i;
    for(k=min;k<max;k++) {     //percorre todo o intervalo
        soma=0;     // a soma comeca em cada numero a 0 senao iria guardar as somas anteriores e ia dar asneira
        i=1;
        while(i<k){ //enquanto que divisor for menor que o proprio numero, o proprio numero nao pode ser dividido por ele mesmo como é logico dai (i<k)
            if (k%i==0) {  //se i divide k
                soma=soma+i;
                i++; //incrementamos o i para ver se existe mais algum divisor inferior ou igual ao numero
            }
            else {
                i++;
            }
        }
        if (soma == k) {    //se a soma dos divisores for igual ao proprio numero entao é numero perfeito
            printf("%d ",k);
        }
    }
    putchar('\n');
}


int main () {
    piramide(4);
    piramide_repete(4);
    triangulo_Floyd (4);
    soma_impares(10);
    numeros_perfeitos (1,50);

    return 0;

}