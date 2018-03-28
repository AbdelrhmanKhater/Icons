#include <bits/stdc++.h>

using namespace std;

int a, b;
int cnt;
int main()
{
    cin >> a >> b;
    while (a <= b)
    {
        cnt++;
        a *= 3;
        b *= 2;
    }
    cout << cnt << "\n";
    return 0;
}
