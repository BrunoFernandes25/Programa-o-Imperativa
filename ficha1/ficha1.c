#include <stdio.h>
#include <assert.h>
#include <math.h>

void pergunta1 () {
    int x, y;
    x = 3; y = x+1;
    x = x*y; y = x + y;

    printf("%d %d\n", x, y);
}
void pergunta2 () {
    int x, y;
    x = 0;
    printf ("%d %d\n", x, y);
}

/* assuma que os c ́odigos ASCII dos caracteres ’A’, ’0’, ’ ’ e ’a’ s ̃ao respectivamente
65, 48, 32 e 97*/

void pergunta3 () {
    
    char a, b, c;
    
    a = 'A'; b = ' '; c = '0';
    printf ("%c %d\n", a, a);
    a = a+1; c = c+2;
    printf ("%c %d %c %d\n", a, a, c, c);
    c = a + b;
    printf ("%c %d\n", c, c);
}

void pergunta4() {
    int x, y;
    x = 200; y = 100;
    x = x+y; y = x-y; x = x-y;
    printf ("%d %d\n", x, y);
}

/*
2.
a) 3 5
b) 11 66
c) _#_#_#_#_#_#_#_#_#_#
d)              (demos apenas '\n')
    1
    01
    11
    001
    101
    011
    111
    0001
    1001
    0101
    1101
    0011
    1011
    0111
    1111
*/

void desenhaquadrado (int n) {
    for (int i =0;i<n;i++) {
        for(int j=0;j<n;j++){
            printf("#");   // ou putchar('...')  com putcahr mete se entre '' por ser um char e nao uma string
        }
    printf("\n");
    }
}

void xadrez (int n) {
    for(int i= 0; i<n;i++){
        for(int j=0;j<n;j++){
            if((i+j)%2 != 0) putchar('_');  // != 0 pode ser omitido a condicao consideramosd sempre verdadeira
            else putchar('#');
        }
    printf("\n");
    }
}

void triangulov (int n) {
    for(int i = 0;i< 2*n-1;i++) {
        for(int j=0;j<2*n-i-1;j++) {   // puta de condicao primeiro que lá chegasse
            if (j<=i) {
                putchar('#');
            }
        }
    putchar('\n');
    }
}

void trianguloh (int n) {
    int c = 1;
    int space = n-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){      //para n=5 temos 8 colunas logo 2*5-1= 9, logo j<9 
            if(j<space) {
                putchar (' ');        //parte esquerda do triangulo
            }
            else if (c>0){           //colocar a quantidade de #
                putchar('#');
                c-=1;
            }
            else {
                putchar(' ');       //parte direita  do triangulo
            }
        }
    c=2*(i+1)+1;     //c aumenta sempre em 2 a cada linha, logo analisando o desenho chega se facilmente a esta condição, AH e fica nos parenteses i+1 porque ainda nao se incrementou o i no ciclo desta forma é que se obtem o numero correto de #
    space-=1;       //reduzir os espacos do triangulo da esquerda a cada linha do ciclo
    putchar('\n');
    }
} 


/*
 r= 4
                                              (1,1) -> canto superior esquerdo 
    #                                         (r+1,r+1) -> centro do circulo 
  #####                                 
 #######                                      dois pontos (x1,y1) (x2,y2)
 #######                                        (x2-x1)^2 + (y2-y1)^2 <= r^2
#########
 #######                                      (l-(r-1))^2 + (c-(r-1))^2 <= r^2
 #######                                       expressao do circulo neste caso
  #####
    #                                          matriz de ordem -> 2*r+1 * 2*r+1
                                                                   8+1  *  8+1
                                                                    9   *   9
*/                                  

int circulo (int r) {
    int l,c, contador = 0;  // para contar os # iniciamos um contador a 0 e depois metemos contador ++ para ir aumentando a medida que mete # e no fim retorna o nº de #

    for (l = 1; l <= 2*r+1; l ++) {
        for (c =1; c <= 2*r+1;c++){
            if (pow (l-r-1,2) + pow (c-r-1,2) <= pow (r,2)) {
                putchar ('#');
                contador ++;
            }
            else 
                putchar (' ');
        } 
        putchar ('\n');
    }
    return contador;

}


int main () {
    int q;
    printf ("pergunta numero?:");
    assert (scanf ("%d", &q) == 1);
    
    switch (q) {
    case 1 : pergunta1();
        break;
    case 2: pergunta2();
        break;
    case 3 : pergunta3();
        break;
    case 4 : pergunta4();
        break;
    case 5 : desenhaquadrado (5);
        break;
    case 6 : xadrez (5);
        break;
    case 7 : triangulov (5);
        break;
    case 8 : trianguloh(5);
        break;
    case 9 : printf("\n Este circulo tem %d #.\n",circulo(4));
        break;
    }
    return 0;
}