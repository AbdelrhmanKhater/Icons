#include <bits/stdc++.h>

using namespace std;

int n;
string matches;
int cnt_A, cnt_D;
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> matches;
    for (int i = 0; i < n; i++)
        if (matches[i] == 'A')
            cnt_A++;
        else
            cnt_D++;
    if (cnt_A > cnt_D)
        cout << "Anton\n";
    else if (cnt_D > cnt_A)
        cout << "Danik\n";
    else
        cout << "Friendship\n";
    return 0;
}
