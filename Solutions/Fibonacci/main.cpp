#include <stdio.h>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

long long n, memo[1000001];

long long fibo(long long y)
{
    return ((1 / sqrt(5)) * (pow(((1 + sqrt(5)) / 2), y) - pow(((1 - sqrt(5)) / 2), y)));
}
long long fibo1(long long y)
{
    if (memo[y] != -1)
        return memo[y];
    return memo[y] = fibo1(y - 2) + fibo1(y - 1);
}
int main()
{
    memset(memo, -1, sizeof memo);
    memo[0] = 0, memo[1] = 1;
    /*while(true)
    {
        int x = rand() % 10000;
        printf("%d\n", x);
        long long res1, res2;
        res1 = fibo(x);
        res2 = fibo1(x);
        if (res1 == res2)
            printf("Ok\n");
        else
            printf("%I64d %I64d\n", res1, res2);
    }*/
    scanf("%I64d", &n);
    printf("%I64d", fibo(n));
    return 0;
}
