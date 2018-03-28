#include <bits/stdc++.h>

using namespace std;
int n, m;
long long modx[10], mody[10];
long long res = 0;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < 5; i++)
    {
        modx[i] = n / 5;
        mody[i] = m / 5;
    }
    for (int i = 1, j = n % 5; j > 0; j--, i++)
        modx[i]++;
    for (int i = 1, j = m % 5; j > 0; j--, i++)
        mody[i]++;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if ((i + j) % 5 == 0)
                res += modx[i] * mody[j];
    cout << res << "\n";
    return 0;
}
