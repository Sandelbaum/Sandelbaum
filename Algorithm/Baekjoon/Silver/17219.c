#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char address[21];
    char password[21];
}database;
int compare(const void *a, const void *b)
{
    database *temp1 = (database *)a;
    database *temp2 = (database *)b;
    return strcmp(temp1->address, temp2->address);
}
int main(void)
{
    int i, n, m;
    database *pos;
    scanf("%d %d", &n, &m);
    database list[n];
    char adrs[21];
    for(i = 0; i < n; i++)
    {
        scanf("%s %s", &list[i].address, &list[i].password);
    }
    qsort(list, n, sizeof(database), compare);

    for(i = 0; i < m; i++)
    {
        scanf("%s", &adrs);
        pos = (database*) bsearch(adrs, list, n, sizeof(database), compare);
        if(pos != NULL)
            printf("%s\n", pos->password);
    }
    return 0;
}
