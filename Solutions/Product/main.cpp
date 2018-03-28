#include <bits/stdc++.h>

using namespace std;
string x, y;
int num1[300], num2[300], res[600];
int siz1, siz2, siz3;
void Convert(string s, int num[300], int* siz)
{
    memset(num, 0, sizeof num);
    int idx = s.length() - 1;
    *siz = 0;
    while (idx > -1)
        num[(*siz)++] = s[idx--] - '0';
}
void Check()
{
    int idx = 0, c = 0;
    while (idx < 600)
    {
        res[idx] += c;
        c = res[idx] / 10;
        res[idx] %= 10;
        if (res[idx] != 0)
            siz3 = idx;
        idx++;
    }
}
void Prod()
{
    siz3 = 0;
    for (int i = 0; i < siz1; i++)
        for (int j = 0; j < siz2; j++)
        {
            res[i + j] += num1[i] * num2[j];
            Check();
        }
    for (int i = siz3; i > -1; i--)
        cout << res[i];
    cout << "\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    while (cin >> x >> y)
    {
        Convert(x, num1, &siz1);
        Convert(y, num2, &siz2);
        memset(res, 0, sizeof res);
        Prod();
    }
    return 0;
}
