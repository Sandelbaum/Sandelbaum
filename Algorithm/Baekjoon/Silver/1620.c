#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[21];
    int index;
}ib;

int compare(const void *a, const void *b)
{
    ib *temp1 = (ib *)a;
    ib *temp2 = (ib *)b;
    return strcmp(temp1->name, temp2->name);
}

int compare_n(const void *a, const void *b)
{
    ib *temp1 = (ib *)a;
    ib *temp2 = (ib *)b;
    if(temp1->index < temp2->index)
        return -1;
    else if(temp1->index > temp2->index)
        return 1;
    else
        return 0;
}

int main(void)
{
    int n, m, i, data;
    char ipdata[21];
    scanf("%d %d", &n, &m);
    ib dg[n];
    ib dgc[n];
    ib* pos;
    for(i = 0; i < n; i++)
    {
        scanf("%s", dg[i].name);
        dg[i].index = i + 1;
        strcpy(dgc[i].name, dg[i].name);
        dgc[i].index = i + 1;
    }
    qsort(dg, n, sizeof(ib), compare);
    qsort(dgc, n, sizeof(ib), compare_n); 
    for(i = 0; i < m; i++)
    {
        scanf("%s", ipdata);
        data = atoi(ipdata);
        if(data != 0)
        {
            printf("%s\n", dgc[data - 1].name);
        }
        else
        {
            pos = (ib*) bsearch(ipdata, dg, n, sizeof(ib), compare);
            if(pos != NULL)
                printf("%d\n", pos->index);
        }
    }
    return 0;
}
