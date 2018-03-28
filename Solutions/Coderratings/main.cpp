#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cstdlib>

using namespace std;

struct rate
{
    long long f, s, idx;
};
bool cmp(rate coder1, rate coder2)
{
    if (coder1.f != coder2.f)
        return coder1.f < coder2.f;
    if (coder1.s != coder2.s)
        return coder1.s < coder2.s;
    return coder1.idx < coder2.idx;
}

rate coders[300005];
int n, ans1[300005], ans2[300005];
long long BIT[1000005], mx = 0;

int solve(int idx)
{
    int ret = 0;
    for (int i = idx; i; i -=(i & -i))
        ret += BIT[i];
    return ret;
}
void update(int idx)
{
    for (int i = idx; i <= mx; i += (i & -i))
        BIT[i]++;
}
void BIT_solve()
{
    sort(coders, coders + n, cmp);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (i && coders[i].f == coders[i - 1].f && coders[i].s == coders[i - 1].s) cnt++;
        else cnt = 0;
        ans1[coders[i].idx] = solve(coders[i].s) - cnt;
        update(coders[i].s);
    }
}
/*void naive_solve()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
           if ((coders[i].f > coders[j].f && coders[i].s > coders[j].s) || (coders[i].f == coders[j].f && coders[i].s > coders[j].s) ||(coders[i].f > coders[j].f && coders[i].s == coders[j].s))
                cnt++;
        }
        ans2[i] = cnt;
    }
}*/
int main()
{
  /* while(true)
   {
       n = rand() % 5 + 1;
       printf("%d\n", n);
       memset(BIT, 0, sizeof BIT);
       mx = 0;
       for (int i = 0; i < n; i++)
       {
           coders[i].f = rand() % 9 + 1;
           coders[i].s = rand() % 9 + 1;
           coders[i].idx = i;
           mx = max(mx, coders[i].s);
           printf("%d ", coders[i].f);
           printf("%d\n", coders[i].s);
       }
       naive_solve();
       BIT_solve();
       for (int i = 0;i < n; i++)
       {
           if (ans1[i] == ans2[i])
                printf("Ok\n");
           else
           {
               printf("%d %d %d\n", ans1[i], ans2[i], i);
               return 0;
           }
       }
   }*/
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%I64d %I64d", &coders[i].f, &coders[i].s);
        mx = max(mx, coders[i].s);
        coders[i].idx = i;
    }
    BIT_solve();
    for (int i = 0; i < n; i++)
        printf("%d\n", ans1[i]);
    return 0;
}
