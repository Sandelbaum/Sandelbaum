#include <stdio.h>
int main(void)
{
    int n, i, j, x, numArr[10001] = {0,};
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        numArr[x]++;
    }
    for(i = 0; i < 10001; i++)
    {
        if(numArr[i] == 0)
            continue;
        else
            for(j = 0; j < numArr[i]; j++)
            {
                printf("%d\n", i);
            }
    }
    return 0;
}
