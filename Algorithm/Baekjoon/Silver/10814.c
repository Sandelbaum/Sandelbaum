#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int age;
    char name[101];
    int order;
}person;

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    person *p1 = ((person*)a);
    person *p2 = ((person*)b);

    if (p1 -> age == p2 -> age)
    {
        if(p1 -> order > p2 -> order)
            return 1;
        else
            return -1;
    }
    else if (p1 -> age > p2 -> age)
        return 1;
    else
        return -1;
}

int main(void)
{
    int n, i;
    scanf("%d", &n);
    person namelist[n];
    for(i = 0; i < n; i++)
    {
        scanf("%d %s", &namelist[i].age, &namelist[i].name);
        namelist[i].order = i;
    }
    qsort(namelist, n, sizeof(namelist[0]), compare);
    for(i = 0; i < n; i++)
    {
        printf("%d %s\n", namelist[i].age, namelist[i].name);
    }
    return 0;
}
