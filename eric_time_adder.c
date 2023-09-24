#include <stdio.h>
int main()
{
    int time1,time2;
    int hour1,hour2,minute1,minute2;
    printf("Please enter two time points:\n");
    scanf("%4d\n%4d",&time1,&time2);
    minute1 = time1 % 100;
    minute2 = time2 % 100;
    hour1 = (time1-minute1)/100;
    hour2 = (time2-minute2)/100;
    printf("%d%02d\n",(hour1 + hour2 + (minute1+minute2) / 60) % 24, (minute1+minute2) % 60);
    return 0;
}