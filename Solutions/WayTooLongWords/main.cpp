#include <bits/stdc++.h>

using namespace std;

int n;
string words[105];
void Greedy_Solve(int idx)
{
    cout << words[idx][0];
    cout << words[idx].length() - 2;
    cout << words[idx][words[idx].length() - 1] << "\n";
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> words[i];
    for (int i = 0; i < n; i++)
        if (words[i].length() > 10)
            Greedy_Solve(i);
        else
            cout << words[i] << "\n";
    return 0;
}
