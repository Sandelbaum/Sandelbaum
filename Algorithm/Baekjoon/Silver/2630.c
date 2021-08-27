#include <stdio.h>
#include <stdbool.h>

int cntwhite = 0, cntblue = 0;

void cut(int paper[][128], int xzero, int xmax, int yzero, int ymax); 

int main(void)  
{
    int i, j, n;
    int paper[128][128];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &paper[i][j]);
        }
    }
    cut(paper, 0, n, 0, n);
    printf("%d\n%d", cntwhite, cntblue);
    return 0;
}

void cut(int paper[][128], int xzero, int xmax, int yzero, int ymax)
{
    int i, j;
    int answer[2];
    bool allwhite = true, allblue = true;
    for(i = yzero; i < ymax; i++)
    {
        for(j = xzero; j < xmax; j++)
        {
            if(paper[i][j] == 1)
            {
                allwhite = false;
            }
            else
            {
                allblue = false;
            }
        }
    }
    if(allwhite == true)
    {
        cntwhite++;
        return;
    }
    else if(allblue == true)
    {
        cntblue++;
        return;
    }
    int halfx = (xzero + xmax) / 2;
    int halfy = (yzero + ymax) / 2;
    cut(paper, xzero, halfx, yzero, halfy);
    cut(paper, halfx, xmax, yzero, halfy);
    cut(paper, xzero, halfx, halfy, ymax);
    cut(paper, halfx, xmax, halfy, ymax);
}
