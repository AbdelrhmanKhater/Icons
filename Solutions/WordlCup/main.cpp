#include <bits/stdc++.h>

using namespace std;
int n, a, b;
int t1, t2, res;
int Check(int n)
{
    int cnt = 0;
    while (n)
    {
        cnt++;
        n /= 2;
    }
    return cnt;
}
struct Node
{
    int num[256];
};
queue<Node> g;
Node cur, tmp;
int BFS()
{
    int lev = 1, siz;
    for (int i = 1; i <= n; i++)
        cur.num[i - 1] = i;
    g.push(cur);
    while (g.size())
    {
        siz = g.size();
        while (siz--)
        {
            cur = g.front();
            g.pop();
            for (int i = 0, j = 0; j < n / 2; j++, i += 2)
                if ((cur.num[i] == a && cur.num[i + 1] == b) || (cur.num[i] == b && cur.num[i + 1] == a))
                    return lev;
                else if (cur.num[i] == a || cur.num[i] == b )
                    tmp.num[j] = cur.num[i];
                else
                    tmp.num[j] = cur.num[i + 1];
            g.push(tmp);
            n /= 2;
        }
        lev++;
    }
}
int main()
{
    cin >> n >> a >> b;
    int N = n;
    res = BFS();
    if (res == (Check(N) - 1))
        cout << "Final!\n";
    else
        cout << res << "\n";
    return 0;
}
