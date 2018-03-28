#include <bits/stdc++.h>

using namespace std;
long long l, r;
set<long long> ans;
long long res;
bool f = true;
long long GCD(long long a, long long b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
int main()
{
    cin >> l >> r;
    for (long long i = l; i <= r && f; i++)
        for (long long j = i + 1; j <= r && f; j++)
            for (long long k = j + 1; k <= r && f; k++)
                if (GCD(i, j) == 1 && GCD(j, k) == 1 && GCD(i, k) != 1)
                {
                    ans.insert(i);
                    ans.insert(j);
                    ans.insert(k);
                    f = false;
                }
    if (f)
        cout << "-1";
    while (ans.size())
    {
        res = *ans.begin();
        ans.erase(ans.begin());
        cout << res << " ";
    }
    cout << "\n";
    return 0;
}
