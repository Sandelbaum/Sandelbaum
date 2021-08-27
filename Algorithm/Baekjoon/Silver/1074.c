#include <stdio.h>
#include <math.h>
int r, c, qnumber;

void visit(int n, int xzero, int yzero, int xmax, int ymax);

int main(void)
{
    int n;
    scanf("%d %d %d", &n, &c, &r);
    int xmax = pow(2, n), ymax = pow(2, n);
    visit(n, 0, 0, xmax, ymax);
    printf("%d", qnumber);
    return 0;
}

void visit(int n, int xzero, int yzero, int xmax, int ymax)
{
    if(n == 0)
    {
        return;
    }
    int halfx = (xzero + xmax) / 2, halfy = (yzero + ymax) / 2, quarter = pow(4, n - 1);
    if(r < halfx && c < halfy)
    {
        visit(n - 1, xzero, yzero, halfx, halfy);
    }
    else if(r >= halfx && c < halfy)
    {
        qnumber += quarter;
        visit(n - 1, halfx, yzero, xmax, halfy);
    }
    else if(r < halfx && c >= halfy)
    {
        qnumber += quarter * 2;
        visit(n - 1, xzero, halfy, halfx, ymax);
    }
    else if(r >= halfx && c >= halfy)
    {
        qnumber += quarter * 3;
        visit(n - 1, halfx, halfy, xmax, ymax);
    }
}
