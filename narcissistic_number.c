#include <stdio.h>
int main(){
    int num,digit1,digit2,digit3;
    for (digit1=1;digit1<10;digit1++){
        for (digit2=0;digit2<10;digit2++){
            for (digit3=0;digit3<10;digit3++){
                num = digit1*100 + digit2*10 + digit3;
                if (num == digit1*digit1*digit1 + digit2*digit2*digit2 + digit3*digit3*digit3){
                    printf("%d ",num);
                }
            }
        }
    }
    return 0;
}