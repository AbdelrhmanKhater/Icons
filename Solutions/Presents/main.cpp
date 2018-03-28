#include <bits/stdc++.h>

using namespace std;
int freq[105];
int n, p;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p;
        freq[p] = i;
    }
    for (int i = 1; i <= n; i++)
        cout << freq[i] << " ";
    cout << "\n";
    return 0;
}
