#include <bits/stdc++.h>

using namespace std;
int s[4];
int Greedy_Solve()
{
    int ret = 0;
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            if (s[i] == s[j])
            {
                ret++;
                i = j;
            }
            else
                break;
    return ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 0; i < 4; i++)
        cin >> s[i];
    sort(s, s + 4);
    cout << Greedy_Solve() << "\n";
    return 0;
}
