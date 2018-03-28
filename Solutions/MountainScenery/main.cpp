#include <bits/stdc++.h>

using namespace std;
int n, k, p[205];
int main()
{
    cin >> n >> k;
    n = 2 * n + 1;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 1; i < n && k; i += 2)
    {
        if (p[i] - p[i - 1] > 1 && p[i] - p[i + 1] > 1)
        {
            p[i]--;
            k--;
        }
    }
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n";
    return 0;
}
