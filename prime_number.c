#include <stdio.h>
int main(){
    int m,n,indivisible_counter,composite_counter;
    printf("Please enter 2 different integers m & n(m<n):");
    scanf("%d %d",&m,&n);
    indivisible_counter = 0;
    composite_counter = 0;
    // a = m;
    while (m <= n){
        if (m == 1){
            m = m+1;
        }
        int i;
        for (i = 2;i < m;i++){
            if (m == 2){
                printf("\nP,%d ",m);
                m = m+1;
                break;
            }
            if (m%i != 0){
                indivisible_counter = indivisible_counter + 1;
                // if (m-i > 1){
                //     // indivisible_counter = indivisible_counter + 1;
                //     continue;
                // }
                // if (m-i == 1){
                if (indivisible_counter == m-2){
                    printf("\nP,%d ",m);
                    m = m+1;
                    indivisible_counter = 0;
                    break;
                }
                // m = m+1;
                // indivisible_counter = 0;
                // break;
                else{
                    // m = m+1;
                    // indivisible_counter = 0;
                    continue;
                }
            }
            if (m%i == 0 && m != 2){
                composite_counter = composite_counter + 1;
                if (n == m && composite_counter == m-n+1){
                    printf("no");
                }
                m = m+1;
                indivisible_counter = 0;
                break;
            }
        }
    }
    return 0;
}