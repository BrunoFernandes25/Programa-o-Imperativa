#include <stdio.h>
# include <string.h>
/*
int eVogal (char c) {
    char vogais[11] = "aAeEiIoOuU";

    int r = 0;
    int k = 0;
    while (vogais[k] && (c != vogais[k])) {
        k++;
    }
    if (vogais[k]) 
        r = 1;
    
    return r;
}

int contaVogais1 (char *s) {
    int r = 0;
    int i = 0;

    while (s[i] != '\0') {
        if (eVogal(s[i])) {
            r++;
        }
        i++;
    }
    return r;
}

(com auxiliar) 
*/

int contaVogais (char *s){
   int conta = 0;
   while(*s!='\0') {
        if(*s=='A' ||*s=='E' ||*s=='I' ||*s=='O' ||*s=='U'||
           *s=='a' ||*s=='e' ||*s=='i' ||*s=='o' ||*s=='u'){
                conta++;
        }
        *s++;
    }
    printf("Num. Vogais = %d\n",conta);
    return conta;
}


int eVogal (char c) {
    char vogais[11] = "aAeEiIoOuU";

    int r = 0;
    int k = 0;
    while (vogais[k] && (c != vogais[k])) {
        k++;
    }
    if (vogais[k]) 
        r = 1;
    
    return r;
}

int retiraVogaisRep (char *s){
    int conta = 0, i = 0,j=0,k=0;
    int n = contaVogais(s);
    int m = strlen(s);
    int tam = m-n;
    char aux[tam];

    while (s[i] != '\0'){
        if(eVogal(s[i])) {  //identico ao contaVogais mas 
            conta++;
        }
        else {
            aux[j]= s[i];
            j++;
        }
        i++;
    }
    
    printf("String sem vogais ={");
    while (k<tam) {
        s[k] = aux[k];
        printf("%c ",s[k]);
        k++;
  }
    printf("}\n");
    s[tam] = '\0';
    
  printf("\nVogais retiradas = %d\n",conta);
  return conta;
}

int duplicaVogais (char *s) {
    int duplos = 0;
    int i = 0,j = 0;
    int vogais = contaVogais(s);
    int tam = strlen(s)+ vogais;
    char aux[tam];

    while (s[i]) {
        if (eVogal(s[i])){
            aux[j] = s[i];
            j++;
            aux[j] = s[i];
            j++;
            duplos++;
        }
        else {
            aux[j]=s[i];
            j++;
        }
        i++;
    }
    printf("String duplicada = {");
    for(i=0;i<tam;i++) {
        s[i]= aux[i];
        printf("%c ", s[i]);
    }
    printf("}");
    s[tam]= '\0';
    printf("\nDuplos = %d\n",duplos);
    return duplos;
}

int ordenado (int v[], int N) {
    int i;
    int r = 1;
    for(i=1;i<N;i++) {
        if(v[i]>v[i-1]) {
            r = 1;
        }
        else {
            r = 0;
            break;
        }
    }
    if(r) {
        printf("Array esta ordenado!\n");
    }
    else {
        printf("Array nao esta ordenado!\n");
    }
    return r;
}

void merge (int a[], int na, int b[], int nb, int r[]) {
    int i=0, j = 0, k= 0;
    
    for(k=0; i<na && j<nb; k++){
        if(a[i] < b[j]){    //caso elem de a[] seja menor do que de b[]
            r[k] = a[i];
            i++;
        } else {            //caso elem de b[] seja menor do que de a[]
            r[k] = b[j];
            j++;
        }
    }

    while(i<na){    
        r[k] = a[i];
        k++;
        i++;
    }

    while(j<nb){
        r[k] = b[j];
        k++;
        j++;
    }

    printf("\n{");
    for(i = 0; i<(na+nb);i++) {
        printf("%d ", r[i]);
    }
    printf("}\n");
}

int partition (int v[], int N, int x) {
    int menores = 0;
    int i, j=0;
    int k= N-1;
    int aux[N];
    
    for(i=0;i<N;i++) {
        if(v[i] <= x) {
            menores++;
            aux[j] = v[i];
            j++;
        }
        else {
            aux[k] = v[i];
            k--;
        }
    }

    for (i = 0; i<N;i++) {
        v[i] = aux[i];
        printf("%d ",v[i]);
    }

    printf("\nMenores = %d",menores);
    return menores;
}


int main () {
    
    void getIntArray(int* start, int* end) {
        for( ; start != end; start++) {
            printf("Insere um valor: ");
            scanf("%d", start);
        }
    }

    int q;
    printf (" Pergunta numero ?:");
    scanf ("%d", &q);

    char s[] = "afnewigfbwei"; //7 
    int  t[] = {1,2,3,4,5,6};

    int v[] = {1,5,2,6,9,6,4,3,0};

    switch (q) {
    case 1 : contaVogais(s);
        break;
    case 2 : retiraVogaisRep (s); 
        break;
    case 3 : duplicaVogais(s);
        break;
    case 4 :
        ordenado (t,6); 
        break;
    case 5 :{   //desta forma podemos escolher os tamanhos dos arrays como bem entendermos
        int tam1, tam2;
        printf("Tamanho array a[]: ");
        scanf("%d",&tam1);
        int a[tam1];
        getIntArray(a,a + tam1);
        printf("Tamanho array b[]: ");
        scanf("%d",&tam2);
        int b[tam2];
        getIntArray(b,b + tam2);
        int r[tam1+tam2];
        merge(a,tam1,b,tam2,r);
        break;
        }
    case 6 : partition (v,9,5);
        break;
    default: printf("Pergunta nao existe !!\n");
    }

    return 0;
}