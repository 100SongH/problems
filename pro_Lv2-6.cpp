#include <string>
#include <vector>
#include <iostream>
using namespace std;

int cnt[2]; // 0: O�� ����, 1: X�� ����

int flag[2]; // O / X�� ���� ���� ����

int answer = 1;
vector<string> board;

void chk_bingo() {

    for (int i = 0; i < 3; ++i) {

        if (board[i] == "OOO") {
            flag[0]++;
        }
        else if (board[i] == "XXX") {
            flag[1]++;
        }
        // ���� 
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'O') {
                flag[0]++;
            }
            else if (board[0][i] == 'X') {
                flag[1]++;
            }

        }

    }

    // �밢��
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'O') {
            flag[0]++;
        }
        else if (board[0][0] == 'X') {
            flag[1]++;
        }

    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {

        if (board[0][2] == 'O') {
            flag[0]++;
        }
        else if (board[0][2] == 'X') {
            flag[1]++;
        }


    }

}

void win() {

    if (flag[0] != 0 && flag[1] != 0) {
        answer = 0;
        return;
    }

    // O�� �̱��
    if (flag[0] != 0) {

        // ���� O = X + 1
        if (cnt[0] != cnt[1] + 1) {
            answer = 0;
            return;
        }

    }

    // 1�� �̱��
    if (flag[1] != 0) {

        // ���� O = X
        if (cnt[0] != cnt[1]) {
            answer = 0;
            return;
        }
    }


}

int solution(vector<string> boards) {
    board = boards;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {

            if (board[i][j] == 'O')
                cnt[0]++;
            else if (board[i][j] == 'X') {
                cnt[1]++;
            }
        }
    }

    // ������ Ȯ��
    if (cnt[0] < cnt[1]) {
        answer = 0;
        return answer;
    }

    if (cnt[0] - cnt[1] > 1) {
        answer = 0;
        return answer;
    }

    chk_bingo();

    win();

    return answer;
}