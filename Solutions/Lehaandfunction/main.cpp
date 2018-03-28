#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int m;
long long a[200005], b[200005], ret = 0, mx = 0, ans[200005];

int main()
{
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%I64d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%I64d", &b[i]);
    sort(a, a + m);
    do
    {
        int i;
        for (i = 0; i < m && a[i] >= b[i]; i++)
            ret += a[i] + b[i];
        if (i == m)
            {
                if (ret > mx)
                {
                    mx = ret;
                    for (int j = 0; j < m; ans[j] = a[j], j++);
                }
            }
    }while(next_permutation(a, a + m));
    for (int i = 0; i < m; i++)
        printf("%I64d ", ans[i]);
    printf("\n");
    return 0;
}
