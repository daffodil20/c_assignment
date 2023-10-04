#include <stdio.h>
int main(){
    int num,digits,unit=1,position,temp,result,location;
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
    int array1[digits],array2[digits];
    unit = 10;
    location = digits-1;
    for (position = 1;position <= digits;position++){
        if (position == 1){
            // printf("%d ",num%unit);
            array2[position-1] = num%unit;
            array1[digits-1] = num%unit;
        }
        if (position > 1){
            temp = num/unit;
            result = temp%10;
            if (position < digits){
                // printf("%d ",result);
                location = location - 1;
                array2[position-1] = result;
                array1[location] = result;
            }
            if (position == digits){
                // printf("%d\n",result);
                location = location - 1;
                array2[position-1] = result;
                array1[location] = result;
            }
            unit = unit*10;
        }
    }
    for (position = 0;position<digits;position++){
        if (position < digits-1){
            printf("%d ",array1[position]);
        }
        if (position == digits-1){
            printf("%d\n",array1[position]);
        }
    }
    for (position = 0;position<digits;position++){
        printf("%d ",array2[position]);
    }
return 0;
}