#include <bits/stdc++.h>

using namespace std;

int n;
int cols[105];

pair<int, int> Partition(int s, int e)
{
    int x = s;
    for (int i = s + 1; i <= e; i++)
        if (cols[i] <= cols[s])
            swap(cols[++x], cols[i]);
    swap(cols[s], cols[x]);
    int y = x;
    for (int i = x - 1; i > 0; i--)
        if (cols[i] == cols[x])
            swap(cols[--y], cols[i]);
    return make_pair(y, x);
}
void Quick_Sort(int s, int e)
{
    while (s < e)
    {
        pair<int, int> mid = Partition(s, e);
        if ((mid.first - s) < (e - mid.second))
        {
            Quick_Sort(s, mid.first - 1);
            s = mid.second + 1;
        }
        else
        {
            Quick_Sort(mid.second + 1, e);
            e = mid.first - 1;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cols[i];
    Quick_Sort(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << cols[i] << " ";
    cout << "\n";
    return 0;
}
