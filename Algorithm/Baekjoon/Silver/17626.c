#include <stdio.h>
#include <math.h>
int main(void)
{
    int n, i, j, k, l;
    scanf("%d", &n);
    int temp = sqrt(n);
    int powi, powj, powk, powl;
    for(i = 0; i <= temp; i++)
    {
        for(j = 0; j <= temp; j++)
        {
            for(k = 0; k <= temp; k++)
            {
                for(l = 0; l <= temp; l++)
                {
                    powi = pow(i, 2);
                    powj = pow(j, 2);
                    powk = pow(k, 2);
                    powl = pow(l, 2);
                    if(powi + powj + powk + powl == n)
                    {
                        if(i == 0)
                        {
                            if(j == 0)
                            {
                                if(k == 0)
                                    printf("1");
                                else
                                    printf("2");
                            }
                            else
                                printf("3");
                        }
                        else
                            printf("4");
                        return 0;                    
                    }
                    else
                        continue;
                }
            }
        }
    }
    return 0;
}
