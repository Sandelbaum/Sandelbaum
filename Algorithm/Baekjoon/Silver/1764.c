#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char name[21];
}icanthear;
typedef struct{
    char name[21];
}icantsee;

int compare(const void *a, const void *b)
{
    const char *p1 = (const char *)a;
    const char *p2 = (const char *)b;
    return strcmp(p1,p2);
}
int main(void)
{
    int n, m, i, cnt = 0;
    scanf("%d %d", &n, &m);
    if(n == 0 ||m == 0)
    {
        printf("0");
        return 0;
    }
    icanthear neverheard[n];
    icantsee neverseen[m];
    for(i = 0; i < n; i++)
    {
        scanf("%s", &neverheard[i]);
    }
    for(i = 0; i < m; i++)
    {
        scanf("%s", &neverseen[i]);
    }
    qsort(neverheard, n, sizeof(neverheard[0]), compare);
    qsort(neverseen, m, sizeof(neverseen[0]), compare);
    for(i = 0; i < n; i++)
    {
        if(bsearch(&neverheard[i], neverseen, m, sizeof(neverseen[0]), compare) != NULL)
            cnt++;
    }
    printf("%d\n", cnt);
    for(i = 0; i < n; i++)
    {
        if(bsearch(&neverheard[i], neverseen, m, sizeof(neverseen[0]), compare) != NULL)
            printf("%s\n", bsearch(&neverheard[i], neverseen, m, sizeof(neverseen[0]), compare));
    }
    return 0;
}
