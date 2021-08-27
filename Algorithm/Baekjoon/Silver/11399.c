#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return 1;
    
    if (num1 > num2)
        return -1;
    
    return 0;
}

int main(void)
{
    int n, i, sum = 0;
    scanf("%d", &n);
    int arr[n];
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    for(i = 0; i < n; i++)
    {
        sum += (i + 1) * arr[i]; // 내림차순으로 정렬한 후 총 합을 구하기 위한 식. 이런 식이 유도되는 이유는 총합이 arr[i] * 1부터 시작해 arr[n]의 가장 작은 수를 n만큼 곱해줘야 문제가 원하는 답을 유도할 수 있기 때문이다
    }
    printf("%d", sum);
    return 0;
}
