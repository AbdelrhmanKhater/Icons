#include <bits/stdc++.h>

using namespace std;
string seq, ins;
int Greedy_Solve()
{
    int j = 0;
    for (int i = 0; i < ins.length(); i++)
        if (seq[j] == ins[i])
            j++;
    return j + 1;
}
int main()
{
    cin >> seq >> ins;
    cout << Greedy_Solve() << "\n";
    return 0;
}
