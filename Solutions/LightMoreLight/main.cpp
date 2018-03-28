#include <bits/stdc++.h>

using namespace std;

long long n;
void Maths_Solve(long long x)
{
    long long sqt = (long long)sqrt(x);
    if (x == (sqt * sqt))
        cout << "yes\n";
    else
        cout << "no\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    while (cin >> n && n != 0)
        Maths_Solve(n);
    return 0;
}
