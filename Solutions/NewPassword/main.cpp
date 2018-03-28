#include <bits/stdc++.h>

using namespace std;
int n, k;
void Greedy_Solve()
{
    int idx = 0;
    for (int i = 0; i < n; i++)
        cout << (char)('a' + (idx++ % k));
    cout << "\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    Greedy_Solve();
    return 0;
}
