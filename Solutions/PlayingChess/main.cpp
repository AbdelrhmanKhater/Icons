#include <iostream>

using namespace std;

char board[10][10];
int cnt_A, cnt_B;
int chess_piece_weight(char c)
{
    int ret = 0;
    if (c == 'q' || c == 'Q')
        ret = 9;
    else if (c == 'r' || c == 'R')
        ret = 5;
    else if (c == 'b' || c == 'B' || c == 'k' || c == 'K')
        ret = 3;
    else if (c == 'p' || c == 'P')
        ret = 1;
    return ret;
}
void Play()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (board[i][j] != '.')
                if (board[i][j] >= 'A' && board[i][j] <= 'Z')
                    cnt_A += chess_piece_weight(board[i][j]);
                else
                    cnt_B += chess_piece_weight(board[i][j]);

}
int main()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> board[i][j];
    Play();
    if (cnt_A > cnt_B)
        cout << "White\n";
    else if (cnt_B > cnt_A)
        cout << "Black\n";
    else
        cout << "Draw\n";
    return 0;
}
