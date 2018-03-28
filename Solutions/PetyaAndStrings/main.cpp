#include <bits/stdc++.h>

using namespace std;

string s1, s2;
string To_Lower(string s)
{
    int cnt = 0;
    while (s[cnt] != '\0')
    {
        s[cnt] = tolower(s[cnt]);
        cnt++;
    }
    return s;
}
int main()
{
    cin >> s1 >> s2;
    s1 = To_Lower(s1);
    s2 = To_Lower(s2);
    if (s1 > s2)
        cout << "1\n";
    else if (s2 > s1)
        cout << "-1\n";
    else
        cout << "0\n";
    return 0;
}
