#include <stdio.h>
#include <math.h>
int main()
{
    int time1 = 20;
    int time2 = 10;
    double tt =111.222;
    // tt = time1 / time2;
    tt = pow(time1, time2);
    printf("%f\n",tt % 10);
    return 0;
}
