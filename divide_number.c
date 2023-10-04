#include <stdio.h>
int main(){
    int num,digits,unit=1,position,temp,result;
    printf("Please enter an integer:");
    scanf("%d",&num);
    for (digits = 1;digits >= 0;digits++){
        if (unit<=num && num<unit*10){
            printf("%d\n",digits);
            break;
        }else{
            unit = unit*10;
        }
    }
    //     if ((num/unit) >= 1){
    //         unit = unit*10;
    //         if ((n/unit) < 10){
    //             break;
    //         }
    //     }
    //     if ((n/unit) < 1){
    //         break;
    //     }
    // printf("%d",digits);
    // }
    unit = 10;
    for (position = 1;position <= digits;position++){
        if (position == 1){
            printf("%d ",num%unit);
        }
        if (position > 1){
            temp = num/unit;
            result = temp%10;
            if (position == digits){
                printf("%d\n",result);
            }
            if (position < digits){
                printf("%d ",result);
            }
            unit = unit*10;
        }
    }
return 0;
}