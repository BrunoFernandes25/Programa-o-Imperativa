#include <stdio.h>

/*calcular o produto de um numero m por um inteiro n atraves de um somatorio
de n parcelas constantes (e iguais a m) */
//ex: 3*4 = 4+4+4

float multInt (int n, float m) {
    float r = 0;

    for(int k=n;k>0;k--) {
        r+=m;
    }
    return r;
}

float multInt2 (int n, float m) {
    int c=0,r;

    while (n>0){
        if(n%2 != 0) {
            c+=m;
        }
        n/=2;
        m*=2;
    }
    r=c;

    return r;
}
//para x e y positivos diz no enunciado por isso nao precisamos especificar no codigo

int mdc1 (int x,int y) {
    int r=0;
    int c=0;

    if(x<y) {
        for(int i=1;i<=x;i++) {
            if(x % i==0 && y % i==0){
                r= i;
            }
        c+=1;
        }
    }
    else {
        for(int i=1;i<=y;i++) {
            if(x % i==0 && y % i==0){
                r= i;
            }
        c+=1;
        }
    }
    printf("num. de iteracoes = %d\n",c);
    return r;
}
/* pergunta numero?:3
15
49
num. de iteracoes = 15
mdc (15,49) e 1
*/

int mdc2 (int x, int y) {
    int r=0;
    int c = 0;
    while (x!=0 && y != 0) {
        if (x<y) {
            y = y-x;
            r=x;    // se pusessemos y nesta funcao nao daria mal visto terminarem ambos iguais mas na funcao mdc3 ja iria dar erro...
        }
        else if(x>y) {
            x = x-y;
            r=y;
        }
        else {
            printf("num. de iteracoes = %d\n",c);
            return x;
        }
    c+=1;
    }
    printf("num. de iteracoes = %d\n",c);
    return r;
}

/* pergunta numero?:4
15
49
num. de iteracoes = 9
mdc (15,49) e 1

e para ver que a funcao mdc3 ainda é mais eficiente tome se valores maiores 

pergunta numero?:4
327
1589
num. de iteracoes = 24
mdc (327,1589) e 1
*/

int mdc3 (int x, int y) {
    int r= 0;
    int c= 0;

    while (x!=0 && y != 0) {
        if (x<y) {
            y = y%x;
            r=x;                    // aqui se fosse r = y daria sempre o mdc igual a 0 porque se fossem numeros nao primos o resto daria sempre 0 logo tem de se guardar o x e nao o y
        }
        else if(x>y) {
            x = x%y;
            r=y;                    // o mesmo acontece aqui basta pensar em mdc3(15,3) x= 15%3 = 0 logo tem de ser guardado o y
        }
        else {
            printf("num. de iteracoes = %d\n",c);
            return x;
        }
    c+=1;
    }
    printf("num. de iteracoes = %d\n",c);
    return r;
}

/* pergunta numero?:5
327
1589
num. de iteracoes = 5
mdc (327,1589) e 1
*/

int fib1 (int n) {
    int r= 1;
    if (n>1) {
        return fib1(n-1)+fib1(n-2);
    }
    else return r;
}

int fib2(int n) {
    int temp, acc1 = 1, acc2 = 1;
    for(int i = 3; i <= n; i++) {
        temp = acc2;
        acc2 += acc1;
        acc1 = temp;
    }
    return acc2;
}

int main () {
    
    int n,p,q;
    float m;
    printf ("pergunta numero?:");
    scanf ("%d\n", &q);
    
    switch (q) {
    case 1 : 
        scanf("%d %f",&n,&m);
        float r = multInt(n,m);
        printf("%f",r);
        break;
    case 2: 
        scanf("%d %d",&n,&p);
        int rr = multInt2(n,p);
        printf("%d",rr);
        break;
    case 3 : 
        scanf("%d %d",&n,&p);
        int mdc = mdc1(n,p);
        printf("mdc (%d,%d) e %d\n",n,p,mdc);
        break;
    case 4 : 
        scanf("%d %d",&n,&p);
        int mdcc = mdc2(n,p);
        printf("mdc (%d,%d) e %d\n",n,p,mdcc);
        break;
    case 5 : 
        scanf("%d %d",&n,&p);
        int mdccc = mdc3(n,p);
        printf("mdc (%d,%d) e %d\n",n,p,mdccc);
        break;
    case 6 : 
        scanf("%d",&n);
        int fibo = fib1(n);
        printf("sequencia de fibonnaci de %d e %d\n",n,fibo);
        break;
    case 7:
        scanf("%d",&n);
        int fibbo = fib2(n);
        printf("sequencia de fibonnaci de %d e %d\n",n,fibbo);
        break;
    }
    return 0;
}
