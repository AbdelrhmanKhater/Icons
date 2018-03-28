#include <bits/stdc++.h>

using namespace std;
string eqn;
int nums[100], nums1[100], pos[5], cnt[5];
void Greedy_Solve()
{
    int siz = 0;
    for (int i = 0; i < eqn.length(); i++)
        if (eqn[i] != '+')
            nums[siz++]= eqn[i] - '0';
    for (int i = 0; i < siz; i++)
        cnt[nums[i] - 1]++;
    for (int i = 1; i < 3; i++)
        pos[i] = pos[i - 1] + cnt[i - 1];
    for (int i = 0; i < siz; i++)
    {
        nums1[pos[nums[i] - 1]] = nums[i];
        pos[nums[i] - 1]++;
    }
    for (int i = 0; i < siz - 1; i++)
        cout << nums1[i] << "+";
    cout << nums1[siz - 1] << "\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> eqn;
    Greedy_Solve();
    return 0;
}
