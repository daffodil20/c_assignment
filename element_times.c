#include <stdio.h>
int max_total(char array[1000], int length){
    int i,j,max = 0,total = 0;
    char temp,result;
    for (i = 0; i <= length-1; i ++){
        if (array[i] != temp){
            for (j = 0; j <= length-1; j++){
                if (array[i] == array[j] && i != j){
                    total ++;
                }
            }
            temp = array[j];
            if (i == 0){
                max = total;
            }
            if (i > 0 && total > max){
                max = total;
                result = array[i];
            }
        }
    }
    printf("%c %d\n",result,max);
}

int main(){
    int n,counter,position;
    char string[1000],letter;
    scanf("%d",&n);
    for (counter = 0; counter <= n-1; counter ++){
        for (position = 0; position <= 999; position ++){
            scanf("%c",&letter);
            string[position] = letter;
        }
        max_total(string,position);
    }
    return 0;
}