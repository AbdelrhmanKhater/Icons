#include <bits/stdc++.h>

using namespace std;
long long freq[100005];
string w;
int n;
int pos;
int main()
{
    ios::sync_with_stdio(false);
    cin >> w;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> pos;
        ++freq[pos];
    }
    for (int i = 1; i <= w.size() / 2; ++i)
        freq[i] += freq[i - 1];
    for (int i = 1; i <= w.size() / 2; ++i)
        if (freq[i] % 2)
            swap(w[i - 1], w[w.size() - i]);
    cout << w << "\n";
    return 0;
}
