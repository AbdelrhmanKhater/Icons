#include <iostream>

using namespace std;
int n, rating[1005][2];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> rating[i][0] >> rating[i][1];
    for (int i = 0; i < n; i++)
        if (rating[i][0] != rating[i][1])
        {
            cout << "rated\n";
            return 0;
        }
    for (int i = 1; i < n; i++)
        if (rating[i][0] > rating[i - 1][0])
        {
            cout << "unrated\n";
            return 0;
        }
    cout << "maybe\n";
    return 0;
}
