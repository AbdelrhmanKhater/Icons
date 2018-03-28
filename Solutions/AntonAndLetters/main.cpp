#include <bits/stdc++.h>

using namespace std;

int freq[35];
char c, com;
int Greedy_Solve()
{
    int ret = 0;
    for (int i = 0; i < 35; i++)
        if (freq[i])
            ret++;
    return ret;
}
int main()
{
    cin >> c ;
    while (cin >> c >> com)
        freq[c - 'a'] = 1;
    cout << Greedy_Solve() << "\n";
    return 0;
}
