#include <stdio.h>
int main(){
    int composite,prime_factor,i,factor_counter,array[100],length,t;
    printf("Please input a composite number:");
    scanf("%d",&composite);
    factor_counter = 0;
    length = 0;
    prime_factor = 2;
    // for (i = 2;i < composite; i++){
    //     if (composite % i == 0){
    //         composite = composite/i;
    //         prime_factor = 2;
    //         factor_counter ++;
            while (prime_factor < composite){
                composite = composite/prime_factor;
                t = t+1;
                if (t > 1){
                    i = prime_factor;
                    if (prime_factor == i){
                        factor_counter ++;
                        if (factor_counter >= 2){
                            length ++;
                            array[length - 1] = prime_factor;
                        prime_factor = 2;
                        continue;
                        }
                    }else{
                        continue;
                    }
                    prime_factor = prime_factor + 1;
                // prime_factor = prime_factor + 1;
            }
            
            
        }
    //         while (temp < composite)
    //             composite
    //     }
    // for ()
    // if (i == composite
    }
return 0;
}