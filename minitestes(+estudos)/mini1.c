#include <stdio.h>

int func(int x) {
        int r=0;
        while (x>0) {
            r+=1;
            x=x-r;
        }
    return r;
}


void func2(){
    int x,y;
    for (y=0;y<8;y++) {    
        for (x=0;x<8;x++) {
            if (x+y<7) putchar ('.');
            else putchar('#');
        }
    putchar('\n');
    }
}



int main () {
    
    for (int i=0;i<20;i++) {
        if (func(i)== 5){ //colocar x da pergunta
            printf("%d -> %d\n",func(i),i);
        }
    }
    putchar('\n');
    func2();
    return 0;
}