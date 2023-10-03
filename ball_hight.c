#include <stdio.h>
int main(){
    int n,time,hight1;
    time = 1;
    float length,hight2;
    length = 0.00;
    printf("Please enter n representing the times of falling:");
    scanf("%d",&n);
    for (hight1=100;hight1>0;hight1 = hight1/2){
        if (time == 1){
            length = length + 100.00;
        }
        if (n >= time && time > 1){
            length = length + hight1*2;
            if (n == time){
                hight2 = hight1;
                printf("%.2f %.2f",length,hight2);
            }
        }
        time = time+1;
    }
    return 0;
}
           

        