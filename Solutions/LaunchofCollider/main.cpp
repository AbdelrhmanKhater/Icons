#include <bits/stdc++.h>

using namespace std;
int res = 1000000009;
int p[200005], n;
string desc;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> desc;
    for (int i= 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < n - 1; ++i)
        if (desc[i] == 'R' && desc[i + 1] == 'L')
            res = min(res, (p[i + 1] - p[i]) / 2);
    if (res != 1000000009)
        cout << res << "\n";
    else
        cout << "-1\n";
    return 0;
}
