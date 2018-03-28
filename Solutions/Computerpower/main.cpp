#include <stdio.h>

using namespace std;

long long n, x;

long long compute_power(long long a, long long p)
{
    if (p == 1)
        return a;
    long long u;
    u = compute_power(a, p / 2);
    if (p % 2)
        return u * u * a;
    return u * u;
}
int main()
{
    scanf("%I64d %I64d", &n, &x);
    printf("%I64d\n", compute_power(n, x));
    return 0;
}
