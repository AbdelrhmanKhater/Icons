#include <bits/stdc++.h>

using namespace std;
int n;
string magnets[100005];
int Greedy_Solve()
{
    int ret = 1;
    for (int i = 1; i < n; i++)
        if (magnets[i] != magnets[i - 1])
            ret++;
    return ret;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> magnets[i];
    cout << Greedy_Solve() << "\n";
    return 0;
}
