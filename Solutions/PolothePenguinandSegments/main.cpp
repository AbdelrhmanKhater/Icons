#include <bits/stdc++.h>

using namespace std;
int n, k;
int r, l;
int res = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> r >> l;
        res += l - r + 1;
    }
    cout << (k - (res % k)) % k << "\n";
    return 0;
}
