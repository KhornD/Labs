#include <stdio.h>
#include <math.h>
int main()
{
    double h;
    printf("h =");
    scanf("%lf", &h);
    printf("%-20sf(x)\n", "x");
    printf("--------------------\n");
    int count_h = (int)(2 / h);
    double y;
    for (int i = 0; i <= count_h; i++)
    {
        double x = i * h;
        if (x <= 1)
            y = sqrt(x+1) - sqrt(x)-(1/2);
        else
            y = exp(-x-(1/x));
        printf("%-20lf% lf\n",x , y);
    }
    return 0;
}
