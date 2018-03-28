/*#include <iostream>
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

using namespace std;

short t, n;
int su, eu, ans = 0, mx, mn;
int SEGT[40000005];
int nums[105][2];
//int BF[10000005];
void SEGT_update(int idx, int s, int e, int x, int y)
{
    if (y < s || x > e)
        return;
    if (s >= x && e <= y)
    {
        SEGT[idx]++;
        return;
    }
    int mid = (s + e) / 2;
    SEGT_update(idx * 2, s, mid, x, y);
    SEGT_update(idx * 2 + 1, mid + 1, e, x, y);
}
int SEGT_solve(int idx, int s, int e, int pos)
{
    if (pos < s || pos > e)
        return 0;
    if (s == e)
        return SEGT[idx];
    int mid = (s + e) / 2;
    return SEGT_solve(idx * 2, s, mid, pos) + SEGT_solve(idx * 2 + 1, mid + 1, e, pos) + SEGT[idx];
}
/*int BF_solve()
{
    for (int i = 0; i < n; i++)
        for (int j = nums[i][0]; j <= nums[i][1]; j++)
            BF[j]++;

}
int main()
{
    std::ios::sync_with_stdio(false);
   /* int res1 = 0, res2;
    while (true)
    {
        res1 = 0;
        memset(SEGT, 0, sizeof SEGT);
        memset(BF, 0, sizeof BF);
        n = rand() % 10 + 1;
        cout << n << "\n";
        for (int i = 0; i < n; i++)
        {
            nums[i][0] = rand() % 10 + 1;
            nums[i][1] = rand() % 10 + 1;
            if (nums[i][1] < nums[i][0]) swap(nums[i][0], nums[i][1]);
            cout << nums[i][0] << " " << nums[i][1] << "\n";
            SEGT_update(1, 1, 10, nums[i][0], nums[i][1]);
        }
        BF_solve();
        for (int i = 1; i < 11; i++)
            res1 = max(res1, SEGT_solve(1, 1, 10, i));
        res2 = *max_element(BF, BF + 11);
        if (res1 == res2)
            cout << "Ok\n";
        else
        {
            cout << res1 << " " << res2 << "\n";
            break;
        }
    }
    cin >> t;
    //t = 100;
    while (t--)
    {
        cin >> n;
        //n = 100;
        mx = -1, mn = 1e6;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i][0] >> nums[i][1];
            //su = 1, eu = 10000000;
            mx = max(mx, nums[i][0]);
            mn = min (mn, nums[i][1]);
        }
        memset(SEGT, 0, sizeof SEGT);
    }
    for (int i = 0; i < n; i++)
        SEGT_update(1, mn, mx, nums[i][0], nums[i][1]);
        for (int i = 1; i <= mx; i++)
            ans = max(ans, SEGT_solve(1, mn, mx, i));
        cout << ans << "\n";

    return 0;
}*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

short t, n;
int ans = 0, mx, mn;
int SEGT[33554432];
pair<int, int> nums[105];
void SEGT_update(int idx, int s, int e, int x, int y, int val)
{
    if (y < s || x > e)
        return;
    if (s >= x && e <= y)
    {
        SEGT[idx] += val;
        return;
    }
    int mid = (s + e) / 2;
    SEGT_update(idx * 2, s, mid, x, y, val);
    SEGT_update(idx * 2 + 1, mid + 1, e, x, y, val);
}
int SEGT_solve(int idx, int s, int e, int pos)
{
    if (pos < s || pos > e)
        return 0;
    if (s == e)
        return SEGT[idx];
    int mid = (s + e) / 2;
    return SEGT_solve(idx * 2, s, mid, pos) + SEGT_solve(idx * 2 + 1, mid + 1, e, pos) + SEGT[idx];
}
int main()
{
	//std::ios::sync_with_stdio(false);
    scanf("%d", &t);
    while (t--)
    {
    	ans = 0;
        scanf("%d", &n);
        mx = -1e9, mn = 1e9;
        for (int i = 0; i < n; i++)
        {
            scanf("%I64d %I64d", &nums[i].first, &nums[i].second);
            mx = max(mx, nums[i].second);
            mn = min (mn, nums[i].first);
        }
        //memset(SEGT, 0, sizeof SEGT);
    for (int i = 0; i < n; i++)
        SEGT_update(1, mn, mx, nums[i].first, nums[i].second, 1);
        for (int i = 1; i <= mx; i++)
            ans = max(ans, SEGT_solve(1, mn, mx, i));
       printf("%d\n", ans);
     for (int i = 0; i < n; i++)
		 SEGT_update(1, mn, mx, nums[i].first, nums[i].second, -1);
    }
    return 0;
}


