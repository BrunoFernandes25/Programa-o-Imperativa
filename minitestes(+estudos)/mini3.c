#include <stdio.h>

int maxCres(int v[],int N) {
    int i;
    int max=0, conta = 0;

    for(i = 1; i<N; i++) {
        if(v[i] >v[i-1]) {
            conta++;

            if(conta>max) {
                max= conta;
            }
        }
        else {  
            conta=1;
        }
    }

    printf("%d",max);
    return max;
}

int main () {
    int v[] = {1,2,3,0,1,4,10,12,5,4};
    maxCres(v,10);
    return 0;
}
