#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int crdn;
    int index;
    int rank;
}Coordinate;

int compare(const void *a, const void *b)
{
    Coordinate *num1 = (Coordinate *)a;
    Coordinate *num2 = (Coordinate *)b;
    return (num1->crdn - num2->crdn);
}

int compare_i(const void *a, const void *b)
{
    Coordinate *num1 = (Coordinate *)a;
    Coordinate *num2 = (Coordinate *)b;
    return (num1->index - num2->index);
}

int main(void)
{
    int i, n, rn = 0;
    scanf("%d", &n);
    Coordinate arr[n];
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].crdn);
        arr[i].index = i;
    }
    qsort(arr, n, sizeof(Coordinate), compare);
    for(i = 0; i < n; i++)
    {
        int j = 1, cnt = 0;
        arr[i].rank = rn;
        while(arr[i].crdn == arr[i + j].crdn)
        {
            arr[i + j].rank = rn;
            j++;
            cnt++;
        }
        i += cnt;
        rn++;
    }
    qsort(arr, n, sizeof(Coordinate), compare_i);
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i].rank);
    }
    return 0;
}
