#include <bits/stdc++.h>

using namespace std;
int freq[30];
char c;
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n * m; i++)
    {
        cin >> c;
        freq[c - 'A']++;
    }
    if (freq['C' - 'A'] || freq['M' - 'A'] || freq['Y' - 'A'])
        cout << "#Color\n";
    else
        cout << "#Black&White\n";
    return 0;
}
