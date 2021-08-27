#include <stdio.h>
#include <string.h>
void add(int x);
void rmv(int x);
void check(int x);
void toggle(int x);
void all();
void empty();

int Arr[21] = { 0, };

int main(void)
{
    int m, x, i;
    char str[9];
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%s %d", &str, &x);
        if (strcmp(str, "add") == 0)
        {
            add(x);
        }
        else if (strcmp(str, "remove") == 0)
        {
            rmv(x);
        }
        else if (strcmp(str, "check") == 0)
        {
            check(x);
        }
        else if (strcmp(str, "toggle") == 0)
        {
            toggle(x);
        }
        else if (strcmp(str, "all") == 0)
        {
            all();
        }
        else if (strcmp(str, "empty") == 0)
        {
            empty();
        }
    }
    return 0;
}
void add(int x)
{
    Arr[x] = 1;
    return;
}
void rmv(int x)
{
    Arr[x] = 0;
    return;
}
void check(int x)
{
    if (Arr[x] == 1)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
    return;
}
void toggle(int x)
{
    if (Arr[x] == 1)
    {
        Arr[x] = 0;
    }
    else
    {
        Arr[x] = 1;
    }
    return;
}
void all()
{
    for (int i = 1; i < 21; i++)
    {
        Arr[i] = 1;
    }
    return;
}
void empty()
{
    for (int i = 1; i < 21; i++)
    {
        Arr[i] = 0;
    }
    return;
}
