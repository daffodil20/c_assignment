#include <stdio.h>
unsigned long multiply(int x){
    int product1;
    if (x ==1){
        return 1;
    }else{
        return x * multiply(x-1);
    }
}

int main(){
    int n;
    unsigned long result;
    scanf("%d",&n);
    result = multiply(n);
    printf("%lu",result);
    return 0;
}