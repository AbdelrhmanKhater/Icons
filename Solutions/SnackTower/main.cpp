#include <bits/stdc++.h>

using namespace std;
struct cmp{
    bool operator () (int i, int j)
    {
        return i > j;
    }
};

int n, x;
set<int, cmp> S;
void Greedy_Solve(int num)
{
    int chosen = num;
    while (num--)
    {
        cin >> x;
        S.insert(x);
        if (x == chosen)
            while (S.size() && *S.begin() == chosen)
            {
                cout << chosen << " ";
                chosen--;
                S.erase(S.begin());
            }
        cout << "\n";
    }
}
int main()
{
    cin >> n;
    Greedy_Solve(n);
    return 0;
}
