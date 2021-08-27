#include <stdio.h>
#include <math.h>
int main(void)
{
   int n, idx = 0, num = 665;
   scanf("%d", &n);
   while(1)
   {
        if(idx == n)
            break;
        num++;
        for(int i = 0; i < 10; i++)
        {
            if(num / (int)pow(10, i) % 1000 == 666)
            {
                idx++;
                break;
            }
        }
   }
   printf("%d", num);
   return 0;
}
