#include <stdio.h>


// para certo n quantas parcelas sao somadas, ex: n=6 da 111 parcelas

int ehPerfeito(int n){      
    int i, soma = 0;

    for(i = 1; i <= n/2; i++){
        if(n % i == 0)
            soma += i;
    }
    if(soma == n)
        return 1;       // é perfeito
    else
        return 0;       // não é perfeito
}

int fib(int n){                                         //nao pensei de outra forma mais eficiente por isso, apostei em criar um vetor para guardar os numeros de fibbonaci até x termo e ai percorrer o array e ver se n numero pertence nesse array          
    int i, fib1 = 1, fib2 = 1, soma;         
    
    for (i = 3; i <= n; i = i + 1) {                                        
        soma = fib1 + fib2;                    
        fib1 = fib2;                           
        fib2 = soma;                           
    }                                        
    return fib2;                             
}

int ehFibonnaci (int n){         
    int i, soma = 0;
    int r=0;

    for(i = 0; i <50; i++){
        if(n==fib(i)) {
            r=1;
        }
    }
    return r;
}

int ehImpar (int n){         
    int r=0;
    if ( n%2 != 0 ) {
        r=1;
    }
    return r;
}

int ehPrimo (int n) {
    int r=1;
    for(int i= 2; i<= n/2;i++) {
        if(n%i == 0) {
            r=0;
        }
    }
    return r;
}

int sumhpto (int n) {
    int r = 0;
    int conta_parcelas = 0;
    int conta_perfeitos = 0;
    int conta_impares = 0;
    int maior = 0;
    int conta_fibs = 0;
    int conta_primos = 0;

    while(n!=1) {
        
        if(ehPerfeito(n)) conta_perfeitos += 1;
        if(ehFibonnaci(n)) conta_fibs += 1;
        if(ehImpar(n)) conta_impares += 1;
        if(ehPrimo(n)) conta_primos += 1;
        if(n>maior) maior = n; 
        r+=n;
        conta_parcelas += 1;
        if(n%2 ==0) n=n/2;
        else n=1+(3*n);
    }
    
    printf ("Numero de parcelas igual a: [%d]\n", conta_parcelas);
    printf ("Numero de numeros perfeitos igual a: [%d]\n", conta_perfeitos);
    printf  ("Maior parcela igual a: [%d]\n", maior);
    printf ("Numero de numeros pertencentes a seq. Fibonnaci igual a: [%d]\n", conta_fibs);
    printf ("Numeros impares iguais a: [%d]\n",conta_impares);
    printf ("Numeros primos iguais a: [%d]\n",conta_primos);
    return r;
}

int main () {

    sumhpto(41);
    return 0;
}