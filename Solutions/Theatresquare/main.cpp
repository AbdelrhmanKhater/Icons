#include <stdio.h>
#include <cmath>

using namespace std;

long long n, m, a;

int main()
{
    long long x, y;
    scanf("%I64d %I64d %I64d", &n, &m, &a);
        x = ceil(n / (a * 1.0));
        y = ceil(m / (a * 1.0));
        printf("%I64d", x * y);
    return 0;
}
