#include <bits/stdc++.h>

using namespace std;
string s;
int n, freq[10];
int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        freq[s[i] - '0']++;
    cout << s.size() - 2 * min(freq[0], freq[1]) << "\n";
    return 0;
}
