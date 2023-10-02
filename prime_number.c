#include <stdio.h>
int main(){
    int m,n,t;
    printf("Please enter 2 different integers m & n(m<n):");
    scanf("%d %d",&m,&n);
    t = 0;
    // a = m;
    while (m<n){
        if (m == 1){
            m = m+1;
        }
        for (int i=2;i<=m;i++){
            if (m == 2){
                printf("\nP,%d ",m);
                m = m+1;
                break;
            }
            if (m%i != 0){
                if (m-i>1){
                    t = t+1;
                    continue;
                }
                if (m-i == 1){
                    if (t == i-2){
                        printf("\nP,%d ",m);
                    }
                    m++;
                    t=0;
                    break;
                }
            }if (m%i == 0){
                m++;
                t=0;
                break;
            }
        }
    // int prime[100];
    // for (j=0;j<p;j++){
    //     printf("%d ",prime[j]);
    // }
    }
    return 0;
}