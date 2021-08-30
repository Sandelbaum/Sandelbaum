#include <stdio.h>

int arr[100001];
int sum[100001];

int main(void)
{
    int n, m, i, a, b, ans;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]); // 수의 개수인 n개만큼 수를 받아 저장
        sum[i] = sum[i - 1] + arr[i];
    }
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b); // 합을 구해야하는 구간 i와 j를 받아와 합을 구하는 것을 m회만큼 반복
        ans = sum[b] - sum[a - 1];
        printf("%d\n", ans);
    }
}
