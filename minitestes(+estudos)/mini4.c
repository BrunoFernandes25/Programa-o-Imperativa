#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y;
} Posicao;

int dist(Posicao a){
    int res = a.x * a.x + a.y * a.y;
    return res;
}



Posicao nesimo(Posicao a[], int N) {
    int i;
    int j;

    Posicao aux;

    for(i = 0; i<N; i++){
        for(j=0;j<N-i-1;j++){
            if(dist(a[j]) > dist(a[j+1])) {
                aux=a[j];
                a[j]=a[j+1];
                a[j+1]=aux;
            }
        }
    }

    return a[269];

}


/*

int total=4681;
void corrige(char* s) {
    int soma = 0;
    int i;
    for (i = 0; s[i]; i++) {
        soma += s[i] - '0';
    }
    while (*s  && soma < total) { // enquanto string nao acabar e a soma de digitos for menos que o pretendido..
        if (*s == '0') {
            int a = (soma + 9 < total) ? 9 : (total - soma);
            soma += a;
            *s = a + '0';
        }
        s++;
    }
}

*/

int main(){
    Posicao a[4] = {{4,3},{3,2},{1,1},{0,1}};
    nesimo(a,4);
    printf("{%d,%d}", a[2].x,a[2].y);
    return 0;
}