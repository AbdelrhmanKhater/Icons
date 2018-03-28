#include <bits/stdc++.h>

using namespace std;
int freq[35];
int n, k;
char w[100005];
int mn;
int main()
{
    //ios::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        mn = 0;
        memset(freq, 0, sizeof freq);
        scanf("%d%s", &k, &w);
        int siz = strlen(w);
        if (k > siz)
            printf("NO\n");
        else
        {
            for (int i = 0; i < siz; ++i)
                ++freq[w[i] - 'a'];
            for (int i = 0; i < 35; ++i)
                if (freq[i] % 2)
                    ++mn;
            if (mn <= k)
                printf("YES\n");
            else
                printf("NO\n");
        }

    }
    return 0;
}
