#include <bits/stdc++.h>

using namespace std;
int Three_N_Plus_One(int n)
{
    if (n == 1)
        return 1;
    if (n % 2)
        return 1 + Three_N_Plus_One(3 * n + 1);
    return 1 + Three_N_Plus_One(n / 2);
}
int main()
{
    int n;
    cin >> n;
    cout << Three_N_Plus_One(n) << "\n";
    return 0;
}
