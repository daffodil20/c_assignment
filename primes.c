#include <stdio.h>
int main(){
    int composite,prime_factor,i,factor_counter;
    printf("Please input a composite number:");
    scanf("%d",&composite);
    factor_counter = 0;
    for (i = 1;i < composite; i++){
        if (composite % i == 0){
            composite = composite/i;
            
            prime_factor = i;
            factor_counter ++;
        }
    //         while (temp < composite)
    //             composite
    //     }
    // for ()
    // if (i == composite
    }
return 0;
}