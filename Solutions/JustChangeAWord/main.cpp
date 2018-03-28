#include <bits/stdc++.h>

using namespace std;
int freq[35];
string w;
int main()
{
    ios::sync_with_stdio(false);
    cin >> w;
    if (w.size() % 2)
        cout << "NO\n";
    else
    {
        for (int i = 0; i < w.size(); ++i)
            ++freq[w[i] - 'a'];
        for (int i = 0; i < 35; ++i)
            if (freq[i] > w.size() / 2)
            {
                cout << "NO\n";
                return 0;
            }
        cout << "YES\n";
    }

    return 0;
}
