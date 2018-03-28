#include <stdio.h>
#include <algorithm>
#include <cstdlib>

using namespace std;

long long great_common_divisor(long long a, long long b)
{
    long long tmp;
    while(b)
    {
        a %= b;
        tmp = b;
        b = a;
        a = tmp;
    }
    return a;
}
long long GCD_REC(long long a, long long b)
{
    if (b == 0)
        return a;
    return GCD_REC(b, a % b);
}
long long n1, n2;
int main()
{
    long long res1, res2;
    while(true)
    {
         n1 = rand() % 1000, n2= rand() % 1000;
         printf("%I64d  %I64d\n", n1, n2);
         res1 = GCD_REC(n1, n2);
         res2 = great_common_divisor(n1, n2);
         if (res1 == res2)
            printf("Ok\n");
         else
         {
            printf("%I64d %I64d\n", res1, res2);
            break;
         }

    }
    scanf("%I64d %I64d", &n1, &n2);
    printf("%I64d\n", great_common_divisor(n1, n2));
    return 0;
}
