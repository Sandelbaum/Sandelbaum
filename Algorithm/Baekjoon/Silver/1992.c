#include <stdio.h>
#include <stdbool.h>

void compress(int video[][64], int xzero, int xmax, int yzero, int ymax); 

int main(void)  
{
    int i, j, n;
    int video[64][64];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%1d", &video[i][j]);
        }
    }
    compress(video, 0, n, 0, n);
    return 0;
}

void compress(int video[][64], int xzero, int xmax, int yzero, int ymax)
{
    int i, j;
    int answer[2];
    bool allwhite = true, allblack = true;
    for(i = yzero; i < ymax; i++)
    {
        for(j = xzero; j < xmax; j++)
        {
            if(video[i][j] == 1)
            {
                allwhite = false;
            }
            else
            {
                allblack = false;
            }
        }
    }
    if(allwhite == true)
    {
        printf("0");
        return;
    }
    else if(allblack == true)
    {
        printf("1");
        return;
    }
    int halfx = (xzero + xmax) / 2;
    int halfy = (yzero + ymax) / 2;
    printf("(");
    compress(video, xzero, halfx, yzero, halfy);
    compress(video, halfx, xmax, yzero, halfy);
    compress(video, xzero, halfx, halfy, ymax);
    compress(video, halfx, xmax, halfy, ymax);
    printf(")");
}
