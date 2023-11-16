#include <stdio.h>
int compare(int array[10]){
    int counter1,counter2,temp;
    for (counter1 = 0; counter1 <= 8; counter1 ++){
        for (counter2 = counter1 + 1; counter2 <= 9; counter2 ++){
            if (array[counter2] < array[counter1]){
                temp = array[counter2];
                array[counter2] = array[counter1];
                array[counter1] = temp;
            }
        }
    }
    for (counter1 = 0; counter1 <= 9; counter1 ++){
        printf("%d ",array[counter1]);
    }
}

int main(){
    int numbers[10],num,i;
    for (i = 0; i <= 9; i ++){
        if (i < 9){
            scanf("%d ",&num);
        }else{
            scanf("%d",&num);
        }
        numbers[i] = num;   
    }
    compare(numbers);
    return 0;
}