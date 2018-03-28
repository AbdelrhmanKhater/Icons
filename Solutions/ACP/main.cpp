#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <stdio.h>

using namespace std;
int t, n, m;
int contestants[105];
bool cmp(int i, int j)
{
    return i > j;
}
int Binary_Search(int idx, int val)
{
    int s = 0, e = idx - 1;
    int mid, ret = idx;
    while(s <= e)
    {
        mid = (s + e) / 2;
        if(contestants[mid] == val)
        {
            ret = mid;
            e = mid - 1;
        }
        else
        s = mid + 1;
    }
}
int Binary_Search1(int idx, int val)
{
    int s = idx, e = n - 1;
    int mid, ret = idx;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (contestants[mid] == val)
        {
            ret = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> contestants[i];
        sort(contestants, contestants + n, cmp);
        /*if (contestants[m - 1] == 0)
            cout << Binary_Search(m - 1, contestants[m - 1]) << "\n";
        else
            cout << Binary_Search1(m -1, contestants[m - 1]) << "\n";
            */
        if (contestants[m - 1] == 0)
        {
            int ret = -1;
            for (int i = m - 2; i >= 0; i--)
            {
                if (contestants[i] != 0)
                {
                    ret = i;
                    break;
                }
            }
            cout << ret  + 1 << "\n";
        }
        else
        {
            int ret = n - 1;
            int cur = m - 1;
            for (int i = m; i < n; i++)
            {
                if (contestants[i] != contestants[cur])
                {
                    ret = i - 1;
                    break;
                }
            }
            cout << ret  + 1 << "\n";
        }
    }
    return 0;
}
