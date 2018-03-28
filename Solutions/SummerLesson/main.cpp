#include <bits/stdc++.h>

using namespace std;
int freq[1005];
int n, m, c;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        freq[c]++;
    }
    for (int i = 0; i < m; i++)
        cout << freq[i] << " ";
    cout << "\n";
    return 0;
}
