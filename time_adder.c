#include <stdio.h>
int main()
{
    int time1,time2;
    int t1,t2,t3,t4,temp1,temp2,total;
    printf("Please enter two time points:\n");
    scanf("%4d\n%4d",&time1,&time2);
    t1 = time1 % 100;
    t2 = time2 % 100;
    t3 = (time1-t1)/100;
    t4 = (time2-t2)/100;
    temp1 = t1+t2;
    temp2 = t3+t4;
    if (temp1 >= 60)
    {
        temp1 = temp1-60;
        temp2 = temp2+1;
    }
    // total = temp1+temp2%2400;
    printf("%d%02d",temp2%24,temp1);
    return 0;
}