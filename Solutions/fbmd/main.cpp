#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;
int t;
a
long long n[100], M;
long long f[2][2] = { {1, 1}, {1, 0} }, m[2][2] = { {1, 1}, {1, 0} };
void multiply(long long f[2][2], long long m[2][2])
{
    int x, y, z, k;
    x = ((f[0][0] * m[0][0]) % 10 + (f[0][1] * m[1][0]) % 10) % 10;
    y = ((f[0][0] * m[0][1]) % 10+ (f[0][1] * m[1][1]) % 10) % 10;
    z = ((f[1][0] * m[0][0]) % 10 + (f[1][1] * m[1][0]) % 10) % 10;
    k = ((f[1][0] * m[0][1]) % 10 + (f[1][1] * m[1][1]) % 10) % 10;
    f[0][0] = x;
    f[0][1] = y;
    f[1][0] = z;
    f[1][1] = k;
}
void power(long long n)
{
    if (n == 1 || n == 0)
        return;
    power(n / 2);
    multiply(f, f);
    if (n % 2)
        multiply(f, m);
}
void zero(){

f[0][1]=f[1][0]=f[0][0]=1;
f[1][1]=0;
}
int maths_solve(long long n)
{
    power(n - 1);
    int z=f[0][0] % 10;
    zero();
    return z;

}
/*int BF_solve(long long n)
{
    int a = 0, b = 1, c;
    if (n < 2) return n;
    for (long long i = 2;i <= n; i++)
    {
        c = (a + b) % M;
        a = b;
        b = c;
    }
    return c;
}*/
int main()
{
    /*int res1, res2;
    while(true)
    {
        f[0][0] = 1;
        f[0][1] = 1;
        f[1][0] = 1;
        f[1][1] = 0;
        n = rand() % 10 + 1;
        M = rand() % 100 + 2;
        printf("%I64d %d\n", n, M);
        res1 = maths_solve(n);
        res2 = BF_solve(n);
        if (res1 == res2)
            printf("Ok\n");
        else
        {
            printf("%d %d\n", res1, res2);
            break;
        }
    }*/
    cin >>t;
    for (int i=0;i<t;i++){
    cin >> n[i] ;}
    for (int i=0;i<t;i++){
    cout << maths_solve((n[i]+1)) << "\n";}
    return 0;
}
