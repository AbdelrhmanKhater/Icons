#include <stdio.h>

using namespace std;

int n;
long long num;
bool flag = true;
int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%I64d", &num);
        if (num % 2)
            flag = false;
    }
    if (flag)
        printf("Second\n");
    else
        printf("First\n");
    return 0;
}
