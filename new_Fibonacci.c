#include<stdio.h>
int main(){
    int n,counter,f0 = 7,f1 = 11,f = 0;
    scanf("%d",&n);
    for (counter = 2;counter <= n;counter ++){
        f = f1+f0;
        if (counter < n){
            f0 = f1;
            f1 = f;
        }
    }
    if (f % 3 == 0){
        printf("yes");
    }else{
        printf("no");
    }
    return 0;
}