#include <bits/stdc++.h>

using namespace std;
string s1, s2;
int Greedy_Solve()
{
    cin >> s1 >> s2;
    if (s1 == s2)
        return -1;
    return max(s1.size(), s2.size());
}
int main()
{
    cout << Greedy_Solve() << "\n";
    return 0;
}
