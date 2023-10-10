#include<stdio.h>
int main(){
    int temp,a,b,c;
    printf("Please enter 3 integers:");
    scanf("%d %d %d",&a,&b,&c);
    if (a < b){
        temp = a;
        a = b;
        b = temp;
    }
    if  (a < c){
        temp = c;
        c = a;
        a = temp;
    }
    printf("%d",a);
    return 0;
}