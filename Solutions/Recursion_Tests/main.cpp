#include <bits/stdc++.h>

using namespace std;
int cnt = 0;
//int arr[7] = {4, 3, 5, 3, 2, 32, 3};
char grid[6][6];
int n;
bool memo[3000][2000];
int freq[300];
int vis[3000][2000];
int arr[2000];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
string s = "abc";
void Merge(int s, int mid, int e)
{
    int n1 = mid - s + 1, n2 = e - mid;
    int arr1[n1], arr2[n2];
    for (int i = 0; i < n1; i++)
        arr1[i] = arr[s + i];
    for (int i = 0; i < n2; i++)
        arr2[i] = arr[mid + 1 + i];
    int i = 0, j = 0, siz = s;
    while ((i < n1) && (j < n2))
        if (arr1[i] < arr2[j])
            arr[siz++] = arr1[i++];
        else
            arr[siz++] = arr2[j++];
    while (i < n1)
        arr[siz++] = arr1[i++];
    while (j < n2)
        arr[siz++] = arr2[j++];
}
void Merge_Sort(int s, int e)
{
    if (s == e)
        return;
    int mid = (s + e) / 2;
    Merge_Sort(s, mid);
    Merge_Sort(mid + 1, e);
    Merge(s, mid, e);
}
void Print_Int(int n)
{
    if (n == 0)
        return;
    Print_Int(n / 10);
    cout << n % 10;
}
void Print_Bit(int n)
{
    if (n == 0)
        return;
    Print_Bit(n / 2);
    cout << n % 2;
}
int Check_Grid(int x, int y)
{
    int ret;
    if (y > n - 1)
        return Check_Grid(x + 1, y - 1);
    if (x > n - 1)
        return Check_Grid(x - 1, y + 1);
    if (memo[x][y] != -1)
        return memo[x][y];
    if (x == n -1 && y == n - 1)
        return grid[n - 1][n - 1];
    ret = Check_Grid(x, y + 1);
    ret = max(ret, Check_Grid(x + 1, y));
    return memo[x][y] = grid[x][y] + ret;
}
bool Find_Path(int x, int y)
{
    int ret = false;
    if (x > n - 1 || x < 0 || y > n - 1 || y < 0)
        return false;
    if (vis[x][y] != -1)
        return false;
    vis[x][y] = 1;
    if (grid[x][y] == 'E')
        return true;
    if (grid[x][y] == 'x')
        return false;
    for (int i = 0; i < 4; i++)
        ret = ret || Find_Path(x + dir[i][0], y + dir[i][1]);
    return ret;
}
int Flood_Fill(int x, int y, int val)
{
    int ret = 0;
    if (x > n - 1|| x < 0 || y > n - 1 || y < 0)
        return 0;
    if (grid[x][y] == 'x')
        return 0;
    if (vis[x][y] != -1)
        return 0;
    vis[x][y] = val;
    for (int i = 0; i < 4; i++)
        ret += Flood_Fill(x + dir[i][0], y + dir[i][1], val);
    return 1 + ret;
}
void Print_Brute(int idx, string str)
{
    if (idx == 2)
    {
        cout << str << "\n";
        return;
    }
    for (int i = 0; i < 3; i++)
        Print_Brute(idx + 1, str + s[i]);
}
int perm[7] = {1, 2, 3};
void Do_Perm(int idx, int num)
{
    if (idx ==  3)
    {
        cout << num << "\n";
        return;
    }
    for (int i = 0; i < 3; i++)
        if (arr[i] == -1)
        {
            arr[i] = 0;
            Do_Perm(idx + 1, num * 10 + perm[i]);
            arr[i] = -1;
        }
}
void Rec(int idx, string str)
{
    if (idx == 3)
    {
        cout << str << "\n";
        return;
    }
    Rec(idx + 1, str + s[idx]);
    Rec(idx + 1, str);
}
void Generate_Serie()
{
    string s = "123";
    stack< pair<int, string> > St;
    St.push(make_pair(0, ""));
    while (!St.empty())
    {
        int idx = St.top().first;
        string cur = St.top().second;
        St.pop();
        if (idx == 3)
            cout << cur << "\n";
        else
        {
            St.push(make_pair(idx + 1, cur));
            St.push(make_pair(idx + 1, cur + s[idx]));
        }
    }
}
int main()
{
    Generate_Serie();
    return 0;
}
