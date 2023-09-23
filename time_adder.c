#include <stdio.h>
int main()
    {
    int time1,time2;
        printf("Please enter two time points:\n");
        scanf("%d\n%d",&time1,&time2);
    int t1,t2,t3,t4,temp1,temp2,total;
        t1 = time1 % 100;
        t2 = time2 % 100;
        t3 = time1-t1;
        t4 = time2-t2;
        temp1 = t1+t2;
        temp2 = t3+t4;
    if (temp1 >= 60)
        {
        temp1 = temp1-60;
        temp2 = temp2+100;
        }
    if (temp2 >= 2400)
        {
        temp2 = temp2-2400;   
        }
    total = temp1+temp2;
    printf("%d",total);
    return 0;
    }