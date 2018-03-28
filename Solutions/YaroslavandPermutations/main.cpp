#include <bits/stdc++.h>

using namespace std;
int n, num[105];
int freq[1005];
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> num[i];
        freq[num[i]]++;
    }
    for (int i = 0; i < 1005; ++i)
        if (freq[i] > ceil(n / 2.0))
        {
            cout << "NO\n";
            return 0;
        }
    cout << "YES\n";
    return 0;
}
