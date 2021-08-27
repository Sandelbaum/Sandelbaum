#include <stdio.h>
#define SIZE 1000
int main(void)
{
    int n, i, j, count = 0;
    scanf("%d", &n);
    int checkprime[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &checkprime[i]);
    }
    int PrimeArray[SIZE];
    for (i = 2; i < SIZE; i++)
        PrimeArray[i] = 1;
    PrimeArray[0] = 0;
    PrimeArray[1] = 0;
    for (i = 2; i < SIZE / i; i++)
    {
        if (PrimeArray[i] == 0)
            continue;
        for (j = i * i; j < SIZE; j += i)

        {
            if (j % i == 0)
                PrimeArray[j] = 0;
        }
    }
    for(i = 0; i < n; i++)
    {
        if(PrimeArray[checkprime[i]] == 1)
            count++;
    }
    printf("%d", count);
}
