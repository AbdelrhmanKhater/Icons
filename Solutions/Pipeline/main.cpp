#include <bits/stdc++.h>

using namespace std;
long long n, k;
bool Check(long long sp)
{
    long long res;
    res = k * (k + 1) / 2;
    res -= (k - sp) * (k - sp + 1) / 2;
    res -= sp - 1;
    return res >= n;
}
int Binary_Solve()
{
    long long s = 1, e = k - 1, mid;
    long long ret = -1;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (Check(mid))
        {
            ret = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return ret;
}
int main()
{
    cin >> n >> k;
    if (n == 1)
        cout << "0\n";
    else
        cout << Binary_Solve() << "\n";
    return 0;
}
