#include <bits/stdc++.h>

using namespace std;
long long n;
long long Log(long long x)
{
    int cnt = 0;
    while (x)
    {
        x /= 2;
        cnt++;
    }
    return cnt;
}
int res = 0;
int main()
{
    cin >> n;
    for (long long i = Log(n); i > -1; --i)
        if (n & (1 << i))
            ++res;
    cout << res << "\n";
    return 0;
}
