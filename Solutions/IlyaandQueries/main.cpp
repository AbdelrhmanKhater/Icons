#include <bits/stdc++.h>

using namespace std;
int cum[100005];
int q, s, e;
string desc;
int Check(int idx)
{
    if (desc[idx] == desc[idx - 1])
        return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> desc;
    for (int i = 1; i < desc.size(); ++i)
        cum[i + 1] += cum[i] + Check(i);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> s >> e;
        cout << cum[e] - cum[s] << "\n";
    }
    return 0;
}
