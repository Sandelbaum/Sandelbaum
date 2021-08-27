#include <stdio.h>
#include <stdlib.h>
int arr[25][25] = {0, }, house[25 * 25] = {0, }, n, cnt = 0;

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

void dfs(int x, int y, int cnt)
{
    arr[x][y] = 0;
    house[cnt]++;
    if (x + 1 < n && arr[x + 1][y] == 1) dfs(x + 1, y, cnt);
    if (x - 1 >= 0 && arr[x - 1][y] == 1) dfs(x - 1, y, cnt);
    if (y + 1 < n && arr[x][y + 1] == 1) dfs(x, y + 1, cnt);
    if (y - 1 >= 0 && arr[x][y - 1] == 1) dfs(x, y - 1, cnt);
    return;
}

int main(void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] == 1)
                {
                    dfs(i, j, cnt);
                    cnt++;
                }
        }
    }
    printf("%d\n", cnt);
    qsort(house, cnt, sizeof(int), compare);
    for(int i = 0; i < cnt; i++)
    {
        if(cnt != 0)
            printf("%d\n", house[i]);
    }
    return 0;
}
