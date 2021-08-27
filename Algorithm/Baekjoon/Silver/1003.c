#include <stdio.h>
int main(void)
{
    int fibo0[41], fibo1[41], i, t, n;
    fibo0[0] = 1;
    fibo1[0] = 0;
    fibo0[1] = 0;
    fibo1[1] = 1;
    for(i = 2; i <= 40; i++)
    {
        fibo0[i] = fibo0[i-1] + fibo0[i-2];
        fibo1[i] = fibo1[i-1] + fibo1[i-2];
    }
    scanf("%d", &t);
    for(i = 0; i < t; i++)
    {
        scanf("%d", &n);
        printf("%d %d\n", fibo0[n], fibo1[n]);
    }
    return 0;
}
