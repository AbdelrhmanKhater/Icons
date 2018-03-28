#include <bits/stdc++.h>

using namespace std;
string t, s;
bool Reverse()
{
    for (int i = 0; i < t.size() / 2; i++)
        swap(t[i], t[t.size() - 1 - i]);
    return t == s;
}
int main()
{
    cin >> s >> t;
    if (Reverse())
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
