#include <bits/stdc++.h>

using namespace std;
int freq[15];
int n;
char k;
bool f = true;
string num;
int cnt = 0;
bool Check()
{
    int ret = 0;
    for (int j = 0; j <= (k - '0'); j++)
        if (freq[j])
            ret++;
    return ret == (k - '0') + 1;
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        memset(freq, 0, sizeof freq);
        f = true;
        cin >> num;
        for (int j = 0; j < num.size(); j++)
        {
            /*if (num[j] > k)
            {
                f = false;
                break;
            }*/
            freq[num[j] - '0'] = 1;
        }
        if (f && Check())
            cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
