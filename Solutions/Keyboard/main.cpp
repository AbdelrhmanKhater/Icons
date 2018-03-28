#include <bits/stdc++.h>

using namespace std;
map<char, int> m;
char r;
string w;
string kb = "qwertyuiopasdfghjkl;zxcvbnm,./";
int d = 1;
int main()
{
    ios::sync_with_stdio(false);
    cin >> r >> w;
    if (r == 'R')
        d = -1;
    for (int i = 0; i < kb.size(); i++)
        m[kb[i]] = i;
    for (int i = 0; i < w.size(); i++)
        cout << kb[m[w[i]] + d];
    cout << "\n";
    return 0;
}
