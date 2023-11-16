#include <stdio.h>
int transfer(int h_input){
    printf("%d",h_input);
}

int main(){
    int h_num;
    scanf("%x",&h_num);
    transfer(h_num);
    return 0;
}