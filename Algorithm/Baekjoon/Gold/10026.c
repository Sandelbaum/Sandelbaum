#include <stdio.h>

char carr[100][100], dcarr[100][100];
int n, ccnt = 0, dcnt = 0;

int rdfs(int x, int y)
{
    carr[x][y] = 'W';
    if (x + 1 < n && carr[x + 1][y] == 'R') rdfs(x + 1, y);
    if (x - 1 >= 0 && carr[x - 1][y] == 'R') rdfs(x - 1, y);
    if (y + 1 < n && carr[x][y + 1] == 'R') rdfs(x, y + 1);
    if (y - 1 >= 0 && carr[x][y - 1] == 'R') rdfs(x, y - 1);
    return 0;
}

int gdfs(int x, int y)
{
    carr[x][y] = 'W';
    if (x + 1 < n && carr[x + 1][y] == 'G') gdfs(x + 1, y);
    if (x - 1 >= 0 && carr[x - 1][y] == 'G') gdfs(x - 1, y);
    if (y + 1 < n && carr[x][y + 1] == 'G') gdfs(x, y + 1);
    if (y - 1 >= 0 && carr[x][y - 1] == 'G') gdfs(x, y - 1);
    return 0;
}

int bdfs(int x, int y)
{
    carr[x][y] = 'W';
    if (x + 1 < n && carr[x + 1][y] == 'B') bdfs(x + 1, y);
    if (x - 1 >= 0 && carr[x - 1][y] == 'B') bdfs(x - 1, y);
    if (y + 1 < n && carr[x][y + 1] == 'B') bdfs(x, y + 1);
    if (y - 1 >= 0 && carr[x][y - 1] == 'B') bdfs(x, y - 1);
    return 0;
}

void rgdfs(int x, int y)
{
    dcarr[x][y] = 'W';
    if (x + 1 < n && (dcarr[x + 1][y] == 'G' || dcarr[x + 1][y] == 'R')) rgdfs(x + 1, y);
    if (x - 1 >= 0 && (dcarr[x - 1][y] == 'G' || dcarr[x - 1][y] == 'R')) rgdfs(x - 1, y);
    if (y + 1 < n && (dcarr[x][y + 1] == 'G' || dcarr[x][y + 1] == 'R')) rgdfs(x, y + 1);
    if (y - 1 >= 0 && (dcarr[x][y - 1] == 'G' || dcarr[x][y - 1] == 'R')) rgdfs(x, y - 1);
    return;
}

int dbdfs(int x, int y)
{
    dcarr[x][y] = 'W';
    if (x + 1 < n && dcarr[x + 1][y] == 'B') dbdfs(x + 1, y);
    if (x - 1 >= 0 && dcarr[x - 1][y] == 'B') dbdfs(x - 1, y);
    if (y + 1 < n && dcarr[x][y + 1] == 'B') dbdfs(x, y + 1);
    if (y - 1 >= 0 && dcarr[x][y - 1] == 'B') dbdfs(x, y - 1);
    return 0;
}

int main(void)
{
    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf(" %c", &carr[i][j]);
            dcarr[i][j] = carr[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(carr[i][j] == 'R')
                {
                    rdfs(i, j);
                    ccnt++;
                }
            else if(carr[i][j] == 'G')
                {
                    gdfs(i, j);
                    ccnt++;
                }
            else if(carr[i][j] == 'B')
                {
                    bdfs(i, j);
                    ccnt++;
                }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dcarr[i][j] == 'R'||dcarr[i][j] == 'G')
                {
                    rgdfs(i, j);
                    dcnt++;
                }
            else if(dcarr[i][j] == 'B')
                {
                    dbdfs(i, j);
                    dcnt++;
                }
        }
    }
    printf("%d %d", ccnt, dcnt);
}
