#include <stdio.h>

int arr[50][50] = {0,}, m, n;

int dfs(int x, int y)
{
    arr[x][y] = 0;
    if (x + 1 < m && arr[x + 1][y] == 1) dfs(x + 1, y);
    if (x - 1 >= 0 && arr[x - 1][y] == 1) dfs(x - 1, y);
    if (y + 1 < n && arr[x][y + 1] == 1) dfs(x, y + 1);
    if (y - 1 >= 0 && arr[x][y - 1] == 1) dfs(x, y - 1);
    return 0;
}

int main(void)
{
    int t, i, j, k, x, y, cnt;
    scanf("%d", &t);
    for(i = 0; i < t; i++)
    {
        scanf("%d %d %d", &m, &n, &k);
        for(j = 0; j < k; j++)
        {
            scanf("%d %d", &x, &y);
            arr[x][y] = 1;
        }
        cnt = 0;
        for(int a = 0; a < m; a++)
        {
            for(int b = 0; b < n; b++)
            {
                if(arr[a][b] == 1)
                {
                    dfs(a, b);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
