#include <iostream>
#include <cmath>
#include <string.h>
#include <string>
using namespace std;
string s;
string Greedy_Solve()
{
     string ret = s;
     int cnt = 0;
     for (int i = 0; i < s.length(); i++)
         if (s[i] >= 'A' && s[i] <= 'Z')
            cnt++;
    if ((cnt == s.length()))
    {
            ret = "";
            for (int i = 0; i < s.length(); i++)
                ret += tolower(s[i]);
    }
    else if (((cnt == (s.length() - 1)) && islower(s[0])))
    {
            ret = "";
            ret += toupper(s[0]);
            for (int i = 1; i < s.length(); i++)
                ret += tolower(s[i]);
    }
    return ret;
}
int main()
{
    cin >> s;
    cout <<  Greedy_Solve() << "\n";
    return 0;
}
