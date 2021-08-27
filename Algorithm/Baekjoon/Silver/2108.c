#include <stdio.h>
#include <math.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

int main(void)
{
    int n, i, j, idx, max = 0, cnt = 0, overlapindex = 0;
    scanf("%d", &n);
    int num[n], mode[8001] = {0,};
    int sum = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        sum += num[i];
    }
    qsort(num, sizeof(num) / sizeof(int), sizeof(int), compare);
    printf("%.0f\n", round(sum / (double)n));
    printf("%d\n", num[(n - 1) / 2]);
    for(i = 0; i < n; i++)
    {
        mode[num[i] + 4000]++;
        if(mode[num[i] + 4000] > max)
            max = mode[num[i] + 4000];
    }
    for(i = 0, idx = 0; i < 8001; i++)
    {
        if(mode[i] == 0)
        {
           continue;
        }
        if(mode[i] == max)
        {
            if(cnt == 0)
            {
                idx = i;
                cnt++;
            }
            else if(cnt ==1)
            {
                idx = i;
                break;
            }
        }
    }
    printf("%d\n", idx - 4000);
    printf("%d", num[n-1] - num[0]);
    return 0;
}
