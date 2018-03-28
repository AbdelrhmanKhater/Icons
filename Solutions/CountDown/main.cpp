#include <bits/stdc++.h>

using namespace std;
struct Node
{
    string name;
    int desc;
};
bool operator < (Node i, Node j)
{
    if (i.desc != j.desc)
        return i.desc> j.desc;
    return i.name < j.name;
}
map<string, vector<string> > tree;
set<Node> ans;
map<string, int> lvl;
queue<string> g;
int l = 1, cnt = 0;
int m, d, n;
string father, boy;
string cur, tmp;
int res;
vector<string> child;
int t, siz;

int BFS(string parent)
{
    cur = parent;
    g.push(cur);
    int i = 0;
    cnt = 0;
    while (g.size())
    {
        siz = g.size();
        while (siz--)
        {
            cur = g.front();
            g.pop();
            if (i == d)
                return cnt;
            if (tree.count(cur) != 0 && lvl.count(cur) != 0)
                continue;
            lvl[cur] = i;
            vector<string> chil(tree[cur]);
            for (int z = 0; z < chil.size(); z++)
            {
                g.push(chil[z]);
                if (i == d - 1)
                    cnt++;
            }
        }
        i++;
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        tree.clear();
        ans.clear();
        lvl.clear();
        while(g.size())
            g.pop();
        cin >> n >> d;
        while (n--)
        {
            child.clear();
            cin >> father >> m;
            for (int i = 0; i < m; i++)
            {
                cin >> boy;
                child.push_back(boy);
            }
            tree[father] = child;
        }
        map<string, vector<string> >:: iterator it;
        for (it = tree.begin(); it != tree.end(); it++)
        {
            while (g.size())
                g.pop();
            res = BFS(it -> first);
            Node node;
            node.desc = res;
            node.name = it -> first;
            ans.insert(node);
            lvl.clear();
        }
        Node desc, cnt_d;
        int k = 0;
        cout << "Tree " << l << ":\n";
        bool check = true;
        while (ans.size() && k < 3 && check)
        {
            desc = *ans.begin();
            cnt_d = desc;
            while (ans.size() && (*ans.begin()).desc == desc.desc)
            {
                cnt_d = *ans.begin();
                ans.erase(ans.begin());
                if (!cnt_d.desc)
                {
                    check = false;
                    break;
                }
                cout << cnt_d.name << " " << cnt_d.desc << "\n";
                k++;
            }
        }
        cout << "\n";
        l++;
    }
    return 0;
}
