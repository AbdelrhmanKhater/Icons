#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int p, q;
};
int n;
Node lap[100005];
bool cmp(Node i, Node j)
{
    return i.p < j.p;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> lap[i].p >> lap[i].q;
    //sort(lap, lap + n, cmp);
    /*for(int i = 0; i < n - 1; ++i)
        if (lap[i].q > lap[i + 1].q)
        {
            cout << "Happy Alex\n";
            return 0;
        }*/
    for (int i = 0; i < n; ++i)
        if (lap[i].p != lap[i].q)
        {
            cout << "Happy Alex\n";
            return 0;
        }
    cout << "Poor Alex\n";
    return 0;
}
