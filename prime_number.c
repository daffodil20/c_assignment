#include <stdio.h>
int main(){
    int m,n,num,composite_counter;
    printf("Please enter 2 different integers m & n(m<n):");
    scanf("%d %d",&m,&n);
    composite_counter = 0;
    num = m;
    while (num <= n){
        if (num == 1){
            num = num+1;
        }
        if (num == 2){
            printf("\nP,%d ",num);
            num = num+1;
        }
        int i;
        for (i = 2;i < num;i++){
            if (num%i == 0 && num != 2){
                composite_counter = composite_counter + 1;
                // printf("no");
                if (n == num && composite_counter == n-m+1){
                    printf("no");
                }
                num = num+1;
                break;
            }
            if (num%i != 0){
                if (num - i > 1){
                    continue;
                }else{
                    printf("\nP,%d ",num);
                    num = num+1;
                    break;
                }
            }
        }
    }
    return 0;
}