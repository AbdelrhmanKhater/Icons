#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;
int n, mx;
int freq[15];
char freq_words[10][10] = {"one", "two", "three", "four", "five",
 "six", "seven", "eight", "nine", "ten"};
char words[105][15];
int number_char(char* s)
{
    int cnt = 0;
    while (s[cnt] != '\0')
        cnt++;
    return cnt;
}
char* map_number(int number)
{
    return freq_words[number - 1];
}
int main()
{
    mx = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
        freq[number_char(words[i])]++;
        mx = max(mx, number_char(words[i]));
    }
    for (int i = 1; i <= mx; i++)
    {
        cout << map_number(i) << "-letter words   " << freq[i];
        for (int j = 0; j < n; j++)
            if (i == number_char(words[j]))
                cout << "   " << words[j];
        cout << "\n";
    }
    return 0;
}
