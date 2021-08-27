#include <stdio.h>
int main(void)
{
    int n, i, max = 0;
    scanf("%d", &n);
    int tower[n + 1], index[n + 1];
    for(i = 1; i <= n; i++)
    {   
        scanf("%d", &tower[i]);
        if(max < tower[i])
        {
            printf("0 ");
            max = tower[i];
        }
        else
        {
            int dst = i - 1;
            for(; tower[dst] < tower[i]; dst = index[dst]);
            index[i] = dst;
            printf("%d ", dst);
        }
    }
    return 0;
}
