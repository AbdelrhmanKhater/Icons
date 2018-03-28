#include <bits/stdc++.h>

using namespace std;
char a[1000005], b[1000005];
int Number_Char(char* s)
{
    int cnt = 0;
    while (s[cnt] != '\0')
        cnt++;
    return cnt;
}
void Shift(char* s, int idx, int siz)
{
    for (int i = 0; i < siz; i++)
        s[i] = s[idx + i];
    s[siz] = '\0';
}
int Is_Bigger(char* a, char* b)
{
    int siz1 = Number_Char(a);
    int siz2 = Number_Char(b);
    if (siz1 > siz2)
        return 1;
    else if (siz2 > siz1)
        return 2;
    for (int i = 0; i < siz1; i++)
        if (a[i] > b[i])
            return 1;
        else if (b[i] > a[i])
            return 2;
    return 0;
}
char* subtract(char* a, char* b)
{
    int s, x, y;
    int z = 0;
    int siz1 = Number_Char(a) - 1;
    int siz2 = Number_Char(b) - 1;
    int j = 0;
    char c[1000005];
    for (int i = siz2; i > -1; i--)
    {
        x = (int)a[siz1--];
        y = (int)b[i];
        s = x - y - z;
        z = 0;
        if (s < 0)
        {
            s += 10;
            z = 1;
        }
        c[j++] = s + '0';
    }
    for (int i = siz1; i > -1; i--)
    {
        x = a[i] - (z + '0');
        z = 0;
        if (x < 0)
        {
            x += 10;
            z = 1;
        }
        c[j++] = x + '0';
    }
    for (int i = 0; i < j / 2; i++)
        swap(c[i], c[j - 1 - i]);
    for (int i = 0; i < j; i++)
        if(c[i] != '0')
        {
              Shift(c, i, j - i);
              break;
        }
    return c;
}
int main()
{
    cin >> a >> b;
    if (Is_Bigger(a, b) == 1)
        cout << subtract(a, b) << "\n";
    else if (Is_Bigger(a, b) == 2)
        cout << "-" << subtract(b, a) << "\n";
    else
        cout << "0\n";
    return 0;
}
