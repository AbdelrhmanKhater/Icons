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
struct sub
{
    int st, cid, pid, f;
};
struct contestant
{
    int cid, nsp, t;
};
bool cmp(sub i, sub j)
{
    if (i.cid != j.cid)
        return i.cid < j.cid;
    if (i.pid != j.pid)
        return i.pid < j.pid;
    return i.st < j.st;
}
bool cmp1(contestant i, contestant j)
{
    if (i.nsp != j.nsp)
        return i.nsp > j.nsp;
    if (i.t != j.t)
        return i.t < j.t;
    return i.cid < j.cid;
}
sub subs[1005], subs1[1005];
contestant contestants[105];
contestant contestants1[105];
int result[15][105], last_result[15][105];
int c, p , s, t;
void Greedy_Solve()
{
    int cur_id = subs[0].cid, cur_p = subs[0].pid ;
    int cur_sum = 0, cur_f = subs[0].f, cur_nps = 0;
    int last_f = 0;
    for (int i = 0; i < s; i++)
    {
        cur_f = subs[i].f;
        if (cur_id != subs[i].cid)
        {
            contestants[cur_id - 1].cid = cur_id;
            contestants[cur_id - 1].nsp = cur_nps;
            cur_id = subs[i].cid;
            cur_p = subs[i].pid;
            last_f = 0;
            cur_sum = 0;
            cur_nps = 0;
        }
        else if (cur_p != subs[i].pid)
        {
            cur_p = subs[i].pid;
            cur_sum = 0;
            last_f = 0;
        }
        if (!cur_f && !last_f)
            cur_sum += 20;
        else if(cur_f && !last_f)
        {
            last_f = 1;
            cur_sum += subs[i].st;
            contestants[cur_id - 1].t += cur_sum;
            cur_nps++;
        }
    }
    contestants[cur_id - 1].cid = cur_id;
    contestants[cur_id - 1].nsp = cur_nps;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> c >> p >> s;
        for (int i = 1; i <= c; i++)
            {
                contestants[i - 1].cid = i;
                contestants[i - 1].nsp = 0;
                contestants[i - 1].t = 0;
            }
        for (int i = 0; i < s; i++)
            cin >> subs[i].st >> subs[i].cid >> subs[i].pid >> subs[i].f;
        sort(subs, subs + s, cmp);
        Greedy_Solve();
        sort(contestants, contestants + c, cmp1);
        for (int i = 0; i < c; i++)
            cout << contestants[i].cid << " " << contestants[i].nsp << " " << contestants[i].t << "\n";
    }
    return 0;
}
