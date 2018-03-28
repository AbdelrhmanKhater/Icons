#include <bits/stdc++.h>

using namespace std;
int n, freq[35];
string s;
void Greedy_Solve()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (s[i] >= 'a' && s[i] <= 'z')
            {
                if (!freq[s[i] - 'a'])
                    cnt++;
                freq[s[i] - 'a'] = 1;
            }
        else
            {
                if (!freq[s[i] - 'A'])
                    cnt++;
                freq[s[i] - 'A'] = 1;
            }
    if (cnt == 26)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
    //ios::sync_with_stdio(false);
    cin >> n >> s;
    Greedy_Solve();
    return 0;
}
