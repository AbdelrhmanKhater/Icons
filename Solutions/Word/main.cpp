#include <bits/stdc++.h>

using namespace std;

string word;
string To_Upper()
{
    for (int i = 0; i < word.length(); i++)
        word[i] = toupper(word[i]);
    return word;
}
string To_Lower()
{
    for (int i = 0; i < word.length(); i++)
        word[i] = tolower(word[i]);
    return word;
}
string Go_Right()
{
    int cnt_U = 0, cnt_L = 0;
    for (int i = 0; i < word.length(); i++)
        if (word[i] >= 'a' && word[i] <= 'z')
            cnt_L++;
        else
            cnt_U++;
    if (cnt_U > cnt_L)
        word = To_Upper();
    else
        word = To_Lower();
    return word;
}
int main()
{
    cin >> word;
    cout << Go_Right() << "\n";
    return 0;
}
