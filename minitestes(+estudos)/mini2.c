#include <stdio.h>
#include <stdlib.h>

int ehPerfeito(int n){      
    int i, soma = 0;

    for(i = 1; i <= n/2; i++){
        if(n % i == 0)
            soma += i;
    }
    if(soma == n)
        return soma;       // é perfeito
    else
        return 0;       // não é perfeito
}

//7 

void fibonacci (int n) {
    int soma = 0;
    int conta = 0;
    int a = 0, b = 1, aux;

    for (; n > 0; n--) {

        printf("%d\n",a);
        soma+=a;
        if(a < (ehPerfeito(a))) {
            conta+=1;
        }
        aux = a;

        a = b;

        b = (b + aux) % 10000;

    }
    printf("Soma impressos: [%d] \n",soma);
    printf("Pergunta 2: [%d]\n",conta);
}



int main () {

    fibonacci(50);
    return 0;
}