#include <bits/stdc++.h>

using namespace std;
int sieve[55];
int nxt[55];
int n, m;
void Sieve()
{
    memset(sieve, -1, sizeof sieve);
    for (int i = 2; i <= 50; i++)
        if (sieve[i])
            for (int j = 2 * i; j <= 50; j += i)
                sieve[j] = 0;
}
void Nxt()
{
    int last = -1;
    for (int i = 55; i > 1; i--)
        if (sieve[i])
        {
            nxt[i] = last;
            last = i;
        }
}
int main()
{
    Sieve();
    Nxt();
    cin >> n >> m;
    if (nxt[n] == m)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
