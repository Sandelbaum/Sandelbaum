#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}

int main(void)
{
    int n, m, a, i;
    scanf("%d", &n);
    int arr1[n];
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    qsort(arr1, sizeof(arr1) / sizeof(int), sizeof(int), compare);
    scanf("%d", &m);
    int arr2[m];
    for(i = 0; i < m; i++)
    {
        scanf("%d", &a);
        if(bsearch(&a, arr1, n, sizeof(int), compare) != NULL)
        {
            arr2[i] = 1;
        }
        else
            arr2[i] = 0;
    }
    for(i = 0; i < m; i++)
    {
        printf("%d\n", arr2[i]);
    }
    return 0;
}
