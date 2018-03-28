#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, k, cnt = 0, cols[29];
int ans = 1, mx = 0;
string x;

void besure()
{
    for (int i = 0; i <= mx; i++)
        if (cols[i])
            ans = 0;
}
int main()
{
    cin >> n >> k >> x;
    for (int i = 0; i < x.size(); i++)
    {
     cols[x[i] - 'a']++;
     mx = max(x[i] - 'a', mx);
    }

    for (int i = 0; i < k; i++)
    {
        int j = 0;
        while(j != mx + 1)
        {
            if (cols[j])
                cols[j]--;
            j++;
        }
    }
    besure();
    if (ans == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
