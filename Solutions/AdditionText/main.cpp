#include <iostream>
#include <algorithm>

using namespace std;
char a[1000005], b[1000005];

int Number_Char(char* s)
{
    int cnt = 0;
    while (s[cnt] != '\0')
        cnt++;
    return cnt;
}
char *Add(char* a, char* b)
{
    char c[1000005];
    int x, y, z = 0, s;
    int siz1 = Number_Char(a) - 1;
    int siz2 = Number_Char(b) - 1;
    int siz = 0;
    int mn = min(siz1, siz2);
    for (int i = mn; i > -1; i--)
    {
        x = a[siz1--] - '0';
        y = b[siz2--] - '0';
        s = x + y + z;
        z = 0;
        if (s > 9)
        {
            s -= 10;
            z = 1;
        }
        c[siz++] = s + '0';
    }
    while (siz1 > -1)
    {
        x = a[siz1--] - '0'  + z;
        z = 0;
        if (x > 9)
        {
            x -= 10;
            z = 1;
        }
        c[siz++] = x + '0';
    }
    while (siz2 > -1)
    {
        x = b[siz2--] - '0' + z;
        z = 0;
        if (x > 9)
        {
            x -= 10;
            z = 1;
        }
        c[siz++] = x + '0';
    }
    if (z)
        c[siz++] = '1';
    for (int i = 0; i < siz / 2; i++)
        swap(c[i], c[siz - 1 - i]);
    return c;
}
int main()
{
    cin >> a >> b;
    cout << Add(a, b) << "\n";
    return 0;
}
