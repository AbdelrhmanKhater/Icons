#include <bits/stdc++.h>

using namespace std;
string digit;
int main()
{
    cin >> digit;
    for (int i = 0; i < digit.size(); i++)
        if (digit[i] > '4' && !(i == 0 && digit[i] == '9'))
            digit[i] = '9' - digit[i] + '0';
    cout << digit << "\n";
    return 0;
}
