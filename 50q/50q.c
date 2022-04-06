#include <stdio.h>      // include basico de C
#include <assert.h>    // para usar o assert
#include <string.h>   // para usar o strlen
#include <stdlib.h>  // para usar NULL

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

void mediaseq () {
    int n=1;
    double soma=0; //tem de ser double senao na media em baixo soma/count iria dar inteiro logo a media final seria sempre com 0 casas decimais
    int count=0;
    double media = 0;

    while (n!=0) {
        printf("Digite um numero: ");
        assert(scanf("%d",&n)==1);
        if (n==0) break;
        soma+=n;
        count++;
    }
    
    media = soma/count;
    printf("A media e: %.5f\n",media); //pois media é do tipo double
}

void secondmax () {
    int n;
    int max;
    int secmax;

    printf ("Digite um numero:");
    assert(scanf ("%d",&n) == 1);

    max = secmax = n;

    while (n != 0) {
        printf ("Digite outro numero (0 termina com a sequencia):");
        assert (scanf ("%d", &n) == 1);

        if (n >= max && n>=secmax) {
            secmax = max;
            max = n;
        }
    }
    printf ("O segundo maior digito da sequencia dada e %d\n", secmax);
}

int bitsUm (unsigned int n) {          //ex 8= 1000  27 = 11011
    int k=n;
    int uns=0;
    while (n!=0) {
        if (n % 2 == 1) {
            uns++;
        }
        n=n/2;
    }
    printf("Numero de bits 1's em %d e %d \n",k,uns);
    return uns;

    //pela divisao descobrir se é 1 ou 0 e somar os 1 e retornar o seu total 
}

int trailingZ(unsigned int n) {
    int k=n;
    int zeros=0;
    while (n!=0) {
        if(n%2==0) {
            zeros++;
        }
    n=n/2;
    }
    printf("Numero de bits 0's em %d e %d \n",k,zeros);
    return zeros;
    
}

int qDig (unsigned int n){   //conta quantos digitos precisas para escrever x numero, ex: 440 serao 3
    int digits=0;
    while(n!=0) {
        n=n/10;
        digits++;
    }
    printf("Precisa de %d digitos.\n",digits);
    return digits;
}

char *strcatt (char s1[], char s2[]) {
    char res [strlen(s1)+strlen(s2)]; // novo array com o tamanho das 2 strings inicializado
    int i,j;
    for(i=0;i<strlen(s1);i++) {
           res[i]=s1[i]; 
    }
    for(j=0;j<strlen(s2);j++){
        res[i+j]=s2[j]; // posciao res[i+j]pega na ultima posicao do array anterior ou seja onde tava '\0' e adiciona a primeira letra da string s2
    }
    res[strlen(s1) + strlen(s2)] = '\0'; //faltava adicionar no fim da nova string resultado o caracter '\0'
    s1=res; // string s1 contem agora a string concatenada
    printf("Nova string concatenada: %s \n",s1);
    return s1;        //ira dar warning porque tamos a dar return a uma string que nao foi passada como parametros, logo pensei em devolver a s1 que contem a string concatenada
}
//melhorando esta funcao 
/*char *strcatt (char s1[], char s2[]) {
    while (*s1!= '\0') {
        s1++; // avança-se com o apontador de s1 até cehgar a '\0'
    }
}
*/

char *strcpyy (char *dest, char source[]) {
    int i;
    for(i= 0;source[i] != 0;i++){
        dest[i]=source[i];
    }
    dest[i] = '\0';
    printf("%s",dest);
    return dest;
}

char* strstrr (char s1[], char s2[]) {
    // int i = 0  aqui poderia usar e em vez de incrementar o s1 e s2 incrementava o i para os s1[i] e s2[i]..
    char *pos1 = s1;                 //posicao_que_ocorre_s1
    char *pos2 = s2;                //posicao_que_ocorre_s2

    if ((*s1 == '\0' && *s2 == '\0')) return s1;

    while (*s1) {
        if (*s1 == *s2) {      // caso a primeira ocurrencia de s1 seja igual a s2 ..
            pos1 = s1;            // passo a colocar o pointer de s1 na posicao da primeira ocurrencia igual para mais tarde indicar o que tenho a retornar..
            
            s1++;
            s2++;    
            
            while (*s1 == *s2 && *s1 != '\0' ) {
                s1++;          //iremos fazer isto enquanto que a string continuar igual ou seja até ao '\0' ou até serem diferentes..
                s2++;
            }
            
            if (*s2 == '\0') {
                s1 = pos1;
                printf ("%s",s1);
                return s1;   
            } 
            else {
                s1 = pos1;
                pos2 = pos1;
                printf ("%s",s1);
                return s1;
            }

        }
    s1++;                 // caso nao sejam iguais apontador indica para letra seguinte e compara se sao iguais senao continua ..
    }
    
    return NULL;
}

//ver tabela ASCII
int strcmpp(char s1[], char s2[]) {
    int i = 0,p,q;
        
    while(s1[i] == s2[i] && s1[i]){ // enquanto s1 nao terminar e os termos de ambas as strings forem iguais
        i++; // vamos avancando em ambas
    }
        
    p = s1[i];  //guardamos em p o caracter na pocisao i em s1 (em ASCII)
    q = s2[i];  //guardamos em q o caracter na pocisao i em s2 (em ASCII)
    printf("%d",p-q);// depois faz se a subtraçao dos dois (nesta ordem) e obtemos o que é pretendido
    return p - q;
}

void strrevv (char s[]) {
    //percorrer até ao fim a string inicial e depois comecar do fim para o inicio a arrecadar os caracteres até obter a string invertida
    int i = strlen(s)-1; //ultima posicao da string que servira para o ciclo for seguinte
    int j=0;
    char rev[strlen(s)]; //criar uma string com o tamanho da inicial
    
    for (j=0;j<strlen(s);j++){
        rev[j]=s[i];
        i--; //vamos andando para tras na string
    }
    rev[j] = '\0';
    printf("%s \n",rev);
}

void strnoV (char s[]) {
    char semvogal[strlen(s)]; //no maximo ela tera o tamanho da original caso contrario sera menor 
    int i=0;
    int j=0;
    int count=0;
    
    for(i=0;i<strlen(s);i++) {
        if (s[i] != 'a' || s[i] != 'e' || s[i] != 'i' || s[i] != 'o' || s[i] != 'u' || s[i] != 'A' || s[i] != 'E' || s[i] != 'I' || s[i] != 'O' || s[i] != 'U') {
            semvogal[j]= s[i];
            j++;
        }
        else {
            count++;
        }
    }
    int tam_semvogal = strlen(s) -count;
    semvogal[tam_semvogal];
    printf("String sem vogais: %s \n",semvogal);
}

void truncWW (char t[],int n) {
    int i;
    char limit = ' ';
    int k=0,j=0;
    char s[50]; // poderia pensar em algo que me desse o valor exato do tamanho deste array mas vejo depois

    for (i=0;t[i]!= '\0';i++){  //enquanto que a string nao acabar ...
        if (t[i]== limit) {       //vamos ter em conta o n e o limitador
            k=0; // pois encontramos ' ' logo depois iremos para o else e precisamos do k=0
            s[j]=t[i]; // colocamos o espaco na nova string tambem
            j++; // eavancamos o j para o proximo elem
        }
        else { //caso nao seja igual ao limitador
            if (k<n) { // vamos guardar os elems enquanto k<n
                s[j]=t[i]; //na nova string
                j++;    //avancamos o j onde ira ser guardado o elem. seguinte
                k++;    //e incrementamos o k
            }
        }
    }
    s[j]='\0';
    printf("%s",s);
}

// ["a","a","b","c","a"]
char charMaisfreq (char s[]) {
        int maior = 0;
        int conta = 0;
        int i = 0,j = 0; 
        char maisFreq = s[i];
        
        for(i = 0;i<strlen(s);i++) {
            conta = 0;
            for (j = 0;j<strlen(s);j++) {
                if(s[i] == s[j]) {
                    conta += 1;
                }
                if(conta> maior) {
                    maior=conta;
                    maisFreq = s[i];
                }
            }
        }
    printf("%c", maisFreq);

    return maisFreq;
}
//ou 
void ordenaChars (char s[]) {
    int i,j;
    char temp;

    for(i = 0;i<s[i];i++) {
        for(j=i+1;j<s[j];j++) {
            if(s[j]<s[i]) {     //se o char seguinte é maior que o anterior..
                temp = s[j];
                s[j]= s[i];
                s[i]=temp;
            }
        }
    }
    //printf("%s\n",s);
}

char charMaisfreq2 (char s[]) {
    
    ordenaChars(s);
    
    int i,j;
    int conta = 0;
    int maior = 0;
    char maisFreq=s[0];

    for(i=0;i<strlen(s);i++) {
        conta=0;
        for(j=i+1; s[j]==s[i];j++) {
            conta+=1;
        }
        if(conta>maior) {
            maior = conta;
            maisFreq = s[i];
        }
    }

    printf("%c", maisFreq);

    return maisFreq;
}

int iguaisConsecutivos (char s[]) {
    int conta = 1, maxiguais = 0;
   
   for(int i = 0; s[i]; i++) {
        if(s[i] == s[i + 1]) {
            conta++;
        }
        else {
            if(conta > maxiguais) {
                maxiguais = conta;
            }
        conta = 1;
        }
    }
    printf("%d",maxiguais);
    return maxiguais;
}

int difConsecutivos (char s[]) {
    int conta = 1, maxdifs = 0;
    
    for(int i = 0; s[i]; i++) {
        if(s[i] == s[i + 1]) {
            conta++;
        }
        else {
            if(conta > maxdifs) {
                maxdifs = conta;
            }
        conta = 1;
        }
    }
    printf("%d",maxdifs);
    return maxdifs;
}

int maiorPrefixo (char s1[],char s2[]) {
    int i=0;
    int conta = 0;

    for(i = 0; s1[i] == s2[i] && (s1[i] || s2[i]);i++ ) {
        conta++;
    }
    printf("%d",conta);
    return conta;
}

int maiorSufixo(char s1[], char s2[]) {
    int i = strlen(s1)-1; // ultimo elem da string s1
    int j = strlen(s2)-1;
    int conta = 0;

    while(i>=0){
        if(s1[i] == s2[j]){
            conta++;
            i--;
            j--;
        } 
        else {
            printf("%d",conta);
            return conta;
        } 
    }
    printf("%d",conta);
    return conta;
}

int sufPref (char s1[], char s2[]) {
    //vai ao inicio de s2 e procura por esse elem em s1 e avanca em ambas enquanto for iguais e retorna o resultado do conta
    int i = 0,j = 0,conta = 0;
    while(s1[i]) {
        if(s1[i]==s2[j]){
            i++;
            j++;
            conta++;
        }
        else{
            i++;
        }
    }
    printf("%d",conta);
    return conta;
}
    
int contaPal (char s[]) { // palavra = conj.caracteres, ou seja, inclui simbolos desde que diferentes de ' ' 
    int i = 0;
    int pal = 0;
    int r = pal;

    while(i<strlen(s)){
        if(s[i] == ' ') {
            i++;
        }
        else {
            while(s[i] != ' ') {
                i++;
            }
        pal+=1;
        }
    }
    r = pal;
    printf("%d",r);
    return r;
}

int contaVogais (char s[]) {
    int i = 0;
    int vog = 0;
    int r = vog;

    for(i = 0;s[i];i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            vog+=1;
        }
    } 
    r = vog;
    printf("%d",r);
    return r;
}

int contida (char a[], char b[]) {
    int i;
    int j;
    int bool = 1; // se pertence (1)

    for(i=0; a[i];i++) {
        int pertence = 0; //Inicialmente nao pertence pois ainda nao comecamos a percorrer b[], so ficara "= 1" se for igual 
       for(j=0;b[j];j++) {
           if(a[i] == b[j]) {
               pertence = 1;    //logo pertence
           }
       }
        if (pertence == 0){ // caso nao pertença, ou seja, percorrendo b[] nenhum caracter e igual a esta letra 
            bool = 0;    //entao bool = 0(False)
            break;      // e damos break porque nao precisamos de continuar a percorrer b[]
        }
    }
    printf("%d",bool);
    return bool;
}

int palindorome (char s[]) {
    int r = 0;
    int i;
    int j = strlen(s)-1; //ultima posicao de s[]
    for(i = 0;i<(strlen(s)/2);i++){
        if(s[i] == s[j]) {
            r=1;
            j-=1;
        }
        else {
            r = 0;
            break;
        }
    }
    printf("%d",r);
    return r;
}

int remRep(char x[]){   //remove os que se repetem sucessivamente
    int i, j;

    for(i=0; x[i]; i++){
        if(x[i] == x[i+1]){     //se forem diferentes nao nos interessa, avancamos
            for(j=i+1; x[j]; j++){   // casao sejam iguais, na posicao seguinte(i+1) iremos colocar a seguinte a este(ou seja, i+2), fazendo com que copiemos os elems para a esquerda até terminar o array
                x[j] = x[j+1];
            }
            i--;    //decrementamos o i, deforma a que este fique a 0 sempre quando iniciar o 1º ciclo for, para repetir o processo até terminarmos com o array sem repeticos e com os '\0' nas posicoes restantes que ocupavam os repetidos
        }    
    }
    printf("%d",i);
    return i;
}

//identica a de cima mas so temos de comparar se numa determinada posicao, a posicao seguinte é tambem um espaco e se for repetimos o algoritmo anterior
int limpaEspacos (char t[]) {
    int i, j;

    for(i=0; t[i]; i++){
        if(t[i]== ' ' && t[i+1] == ' '){    
            for(j=i+1; t[j]; j++){   
                t[j] = t[j+1];
            }
            i--;
        }    
    }
    printf("%d",i);
    return i;
}

void insere (int v[], int N, int x) {
    int i,j;
    for(i = 0;i<N;i++) {
        if(v[i] > x) {  //enquanto que v[i]<x avancamos
            //copiar os elems dessa posicao para a frente
            for (j=N;j>i;j--){ // j=N('\0') e como o "novo" array passara a ter N+1 elems a posicao N é ocupada, N+1 ja nao('\0') 
                v[j] = v[j-1];
            }
        //e colocamos x na posicao que falta
        v[i]= x;
        break; // nao precisamos de continuar o 1º ciclo for, ja esta tudo feito       
        }
        if(i==N-1) { // excecao com 1 elem
            v[N]=x;
        }
    }
    /*
    for(int i = 0;i<7;i++){
            printf("%d ", v[i]);
        } so para dar print*/

}

void merge (int r [], int a[], int b[], int na, int nb){
    int i=0, j=0, k;

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

    int z;
    for(z=0;z<na+nb;z++){
        printf("%d ",r[z]);
    }
}

int crescente ( int a[],int i, int j){
    int k;
    int r=1; // se tiver ordenado
    for(int k = i; k < j; k++) {
        if(a[k + 1] < a[k]) r = 0;  //caso nao seja entao r=0
    }
    printf("%d",r);
    return r;
}

int retiraNeg(int v[], int N) { //pensar em puxar para a esquerda os numeros como nos arrays das strings acima
    int i,j;
    for(i=0;i<N;i++) {
        if(v[i]<0) {
           for(j=i;j<N-1;j++){  //j=posicao do negativo 
                v[j] = v[j+1];  //colocamos o seguinte na posicao do negativo
            }
            N--; // terminando este ciclo temos todos os numeros puxados 1 casa para a esquerda logo podemos descartar o ultimo elem decrementando o tamanho do array  
        }
    }

    /*int k;
    for(k=0;k<N;k++){
        printf("%d",v[k]);
    }*/
    return N;
}

int menosFreq (int v[], int N) {
    int i,j;
    int min=N;
    int conta;
    for(i=0;i<N;i++) {
        conta=1;    //existe no minimo 1 ocurrencia do proprio elemento, e iniciamo lo sempre que termina o 2 ciclo para contar de novo o elem. seguinte do array
        for(j=i+1;j<N;j++){
            if(v[i] == v[j]){
                conta+=1;
            }
        }
        if(conta<min) {
            min= v[i];
        }
    }
    printf("%d",min);
    return min;
}

int maisFreq (int v[], int N) {
    int i,j;
    int max=0;
    int conta;
    for(i=0;i<N;i++) {
        conta=1;
        for(j=i+1;j<N;j++){
            if(v[i] == v[j]){
                conta+=1;
            }
        }
        if(conta>max) {
            max= v[i];
        }
    }
    printf("%d",max);
    return max;
}

int maxCresc (int v[], int N) {
    int i,j,k;
    int max = 0;
    int conta = 1;
    
    for(i=1;i<N;i++) {  //em vez de comparar posicao i com i+1, comparo i-1 com i, assim nao terei problemas com o fim do array
        if(v[i-1]>v[i]) {
            if(conta>max) {
                max = conta;
                conta=1;
            }
        }
        else {
            conta++;
        }
    }
    printf("%d",max);
    return max;
}

void ordena_vetor (int v[], int n) {
    int i = 0,j,temp;
    
    for (i = 0;i<n;i++) {
        for (j= i+1;j<n;j++) {
            if (v[i] > v[j]) {
            temp = v[j];                                    //swap (v[i+1],v[i]);
            v[j] = v[i];
            v[i] = temp;
        }
        }
    }
    //for (i = 0; i < n;i++) {              // apenas para testar se ficava ordenado
    //    printf("%d ", v[i]);
    //}
}

int elimRep (int v[], int n) {
    int i,sem_rep=1;
    
    ordena_vetor (v,n);                 //chama se a funcao ordena para ser mais facil trabalhar, visto tar ordenado

    for (i = 1;i < n;i++) {
        if (v[i-1] == v[i]);        // no caso de ser repetido ignora se e passamos a comparacao seguinte
        else {                  
            sem_rep++;              // caso sejam diferentes entao aumentamos o numero de sem_rep ou seja um numero nao repetido foi encontrado
        }
    }
    printf ("%d",sem_rep);              // para confirmar os resultados 
    return sem_rep;
}

int elimRepord (int v[], int n) {
   int i,sem_rep=1;

    for (i = 1;i < n;i++) {
        if (v[i-1] == v[i]);        // no caso de ser repetido ignora se e passamos a comparacao seguinte
        else {                  
            sem_rep++;              // caso sejam diferentes entao aumentamos o numero de sem_rep ou seja um numero nao repetido foi encontrado
        }
    }
    
    printf ("%d",sem_rep);              // para confirmar os resultados 
    
    return sem_rep;
}

int comunsOrd (int a[],int na, int b[], int nb) {
    int i=0,j=0;
    int conta = 0;

    while(i<na && j<nb) {
        if(a[i] == b[j]) { //caso o elem de ambas os arrays seja igual entao avancamos em ambos
            conta++;
            i++;
            j++;
        }
        else {
            if(a[i]<b[j]) {
                i++;    //visto que o i nunca ira ser encontrado no segundo array
            }
            else {
                j++;
            }
        }
    }
    printf("%d",conta);
    return conta;
}
/*
int comunsOrd (int a[], int na, int b[], int nb) {
    int i,j,comuns = 0;

    for (i = 0; i <na; i++) {               //comparamos o certo elemento do primeiro vetor
        for (j = 0; j<nb;j++) {             // com todos os restantes do segundo vetor
            if (a[i] != a[i-1]) {           // este if faz com que caso o valor do primeiro vetor for igual ao seguinte nao entre na contabilizacao dos numeros em comum pois ja vai existir
                if (a[i] == b[j]) {         //  aqui compara se o elemento do primeiro e do segundo vetor e vemos se sao iguais e se forem aumenta se mais a frente comuns
                    if (b[j] != b[j-1]) {    // este if faz o mesmo que o outro em cima, compara se o elemento em questao e o seguinte nao sao iguais no segundo vetor para assim nao serem contabilizados
                        comuns++;
                    }
                }
            }
        }
    }
    printf ("%d",comuns);
    return comuns;

*/

int comuns (int a[],int na,int b[],int nb) {
    int conta=0;
    int i,j;

    for(i=0;i<na;i++) {
        for(j=0;j<nb;j++) {
            if(a[i] == b[j]) {
                conta++;
            }
        }
    }
    printf("%d",conta);
    return conta;
}

int midInd (int v[], int n) {
    int i,j;
    int min =0;

    for(i=1;i<n;i++) {
        if(v[i]<v[min]){
            min = i;
        }
    }
    printf("%d",min);
    return min;
}

void somasAc (int v[], int Ac [], int N) {
    int soma = 0;
    int i,j;

    for(i=0;i<N;i++) {
        soma+= v[i];
        Ac[i]= soma;
        printf("%d ",Ac[i]);
    }

}

int triSup (int N, float m [N][N]) {           // ao rodar esta funcao o apontador para a matriz da NULL ver isto mais tarde mas a funcao esta certa..
    int i,j,r=0;

    for (i = 0; i<N; i++) {
        for (j=0;j<N;j++) {
            if (m[i][j] != 0) {
                r = 1;
            }
        }
    }
    printf ("%d",r);
    return r;
}

void transposta (int N, float m [N][N]) {
    int i, j;
    float temp;
    
    for(i=1; i<N; i++){
        for(j=0; j<i; j++){     //j<i se fosse <N iria voltar a trocar o que ja haviamos trocado
            temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
    /*
    int a,b;
    for (a = 0; a<N; a++) {
        for (b=0;b<N;b++) {
            printf("%.0f ",m[a][b]);
        }
    printf("\n");
    }*/
}

void addTo (int N, int M, int a[N][M], int b[N][M]) {
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            a[i][j]= a[i][j] + b[i][j]; 
        }
    }
    int c,d;
    for (c=0; c<N; c++) {
        for (d=0;d<M;d++) {
            printf("%d ",a[c][d]);
        }
    printf("\n");
    }
}


int main () {
    int q;
    char s1[] = "LCC vai ta foder !! ";
    char s2[]= "Obrigado Bruno irei faze-lo.";
    char s3[50];
    char s4[] = "abababab cdcdcdcdcd efefefefefefefefef";
    char s5[] = "aaaabacabaaaaaaac";    //7 conseq. iguais e difs 
    char s6[] = "abbcdef";
    char s7[] = "abbcjkih";
    char s8[] = "abbc";
    char s9[] = "sdsdbbc";
    char s10[] = "batota";
    char s11[] = "totalidade";    
    char s12[] = " a a bbb a";
    //char s13[] = "a a bbb a      afa  faeifneiuf fnfn n n n n n nnnnn";
    char s13[] = "braga";
    char s14[] = "bracara augusta";
    char s15[] = "abbabba";
    char s16[] = "abc      b f s ";
    int v[] = {1};
    //merge
    int a[] = {1,2,3,4,5,6,5};
    int b[] = {3,6,9,12,15,12,111};
    int r[10] ;
    int na = 5;
    int nb=5;

    int neg[] = {1,2,-3,4,-5,6};

    int c[] = {1,2,3,3,4,5,5,6,6,7};
    int d[] = {1,2,3,2,1,4,10,12,5,4};
    int e[] = {1,2,3,2,1,4,2,4,5,4};
    int f[] = {1,1,1,2,3,4,5,5,6,7};
    int g[] = {1,2,3,4,5};
    int h[] = {2,4,6,8,10};
    int i[] = {1,2,5,4,3};
    int j[] = {4,10,2,8,6,3,6};
    int k[] = {5,3,0,2,1,6,4};
    int l[] = {0,10,20,30};
    int tam = sizeof(l)/sizeof(int);
    int m[tam];
    float n[2][3] = {{1,2,3},
                    {0,4,5}
                    };
    int o[2][3] = {{1,2,3},
                    {0,4,5}
                    };
    int p[2][3] = {{1,2,3},
                    {0,4,5}
                    };

    printf ("pergunta numero?:");
    assert (scanf ("%d", &q) == 1);

    switch (q) {
    case 1 : maximoseq ();
        break;
    case 2 : mediaseq ();
        break;
    case 3 : secondmax ();
        break;
    case 4 : bitsUm(27);
        break;
    case 5 : trailingZ(8);
        break;
    case 6 : qDig(4294967295); // limite maximo de unsignet long int 
        break;
    case 7 : strcatt(s1,s2);
        break;
    case 8 : strcpyy(s3,s1);
        break;
    case 9: strcmpp (s1,s2);
        break;
    case 10 : strstrr(s1,s2);
        break; 
    case 11 : strrevv (s1);
        break; 
    case 12 : strnoV (s1);
        break;
    case 13 : truncWW (s4,4);
        break;
    case 14 : charMaisfreq (s4);
        break;
    /*case 15 : charMaisfreq2 (s4);
        break;
    */
    case 15 : iguaisConsecutivos (s5);
        break;
    case 16 : difConsecutivos (s5);
        break;
    case 17 : maiorPrefixo (s6,s7);
        break;
    case 18 : maiorSufixo (s8,s9);
        break;
    case 19 : sufPref (s10,s11);
        break; 
    case 20 : contaPal (s12);
        break;
    case 21 : contaVogais (s2);
        break;    
    case 22 : contida (s13,s14);
        break;
    case 23 : palindorome (s15);
        break;
    case 24 : remRep (s5);
        break;    
    case 25 : limpaEspacos(s16);
        break;
    case 26 : insere(v,7,4);
        break;   
    case 27 : merge (r, a, b,na,nb);
        break;
    case 28 : crescente(a,2,5); 
        break;  
    case 29 : retiraNeg(neg,6);
        break; 
    case 30 : menosFreq(c,10);
        break;
    case 31 : maisFreq(c,10);
        break;
    case 32 : maxCresc(d,10);
        break;
    case 33 : elimRep (e,10);
        break;
    case 34 : elimRepord(f,10);
        break;
    case 35 : comunsOrd(g,5,h,5);
        break;
    case 36 : comuns (i,5,j,7);
        break;
    case 37 : midInd (k,7);
        break;
    case 38 : somasAc(l,m,4);
        break;
    case 39 : triSup (3,n);
        break; 
    case 40: transposta(3,n);
        break;
    case 41: addTo(2,3,o,p);
        break;
    }
    return 0;
}
