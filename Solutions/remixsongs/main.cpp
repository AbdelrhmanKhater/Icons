#include <iostream>
#include <cmath>
#include <string.h>
#include <string>
#include <map>
#include <vector>

using namespace std;
string s, str;
vector<string> strs;
int nxt[100];
void Greedy_Solve(string s)
{
    string det = "WUB";
    int j = 0;
    for (int i = 0; s.length() > 2 && i < s.length() - 2; i++)
    {
        if (s[i] == det[0] && s[i + 1] == det[1] && s[i + 2] == det[2])
        {
            nxt[j] = i;
            j++;
            i += 2;
        }
    }
    if (j == 0)
        cout << s ;
    else
    {
        string res = "";
        if (nxt[0] > 0)
        res += s.substr(0, nxt[0]) + " ";
        for (int i = 0; i < j - 1; i++)
        if (nxt[i] + 3 != nxt[i + 1])
            res += s.substr(nxt[i] + 3, nxt[i + 1] - (nxt[i] + 3)) + " ";
        if (nxt[j - 1] + 2 < s.length() - 1)
        res += s.substr(nxt[j - 1] + 3, s.length() - (nxt[j - 1] + 3)) + " ";
        cout<< res;
    }

}
int main()
{
    cin >> s;
    Greedy_Solve(s);
    cout << "\n";
}
