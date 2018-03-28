#include <bits/stdc++.h>

using namespace std;
string user_name;
int freq[35];
int Check()
{
    int ret = 0;
    for (int i = 0; i < user_name.length(); i++)
        freq[user_name[i] - 'a']++;
    for (int i = 0; i < 30; i++)
        if (freq[i])
            ret++;
    return ret;
}
int main()
{
    cin >> user_name;
    if (Check() % 2)
        cout << "IGNORE HIM!\n";
    else
        cout << "CHAT WITH HER!\n";
    return 0;
}
