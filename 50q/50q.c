#include <stdio.h>
#include <assert.h>

/* 1. Defina um programa que le (usando a funcao scanf uma sequencia de numeros inteiros
terminada com o numero 0 e imprime no ecran o maior elemento da sequencia.*/

void maximoseq () {
    int n;
    int max;

    printf ("Digite um numero:");
    assert(scanf ("%d",&n) == 1);

    max = n;

    while (n != 0) {
        printf ("Digite outro numero (0 termina com a sequencia):");
        assert (scanf ("%d", &n) == 1);

        if (n >= max) {
            max = n;
        }
    }
    printf ("O maior digito da sequencia dada e %d\n", max);
}

int main () {
    int q;

    printf ("pergunta numero?:");
    assert (scanf ("%d", &q) == 1);

    switch (q) {
    case 1 : maximoseq ();
        break;
    }
    return 0;
}
