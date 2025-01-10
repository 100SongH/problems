#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = { 0, 0 };

    // �ߺ� Ȯ�ο� map
    unordered_map<string, int> chk; // value = 1 -> �̹� ����

    // ���� ���° ������
    int turn = 1;

    // Ż���� ��ȣ
    int num = 0;


    for (int i = 0; i < words.size(); ++i) {

        // �̹� ����
        if (chk[words[i]] == 1) {
            answer = { num + 1, turn };
            break;
        }

        // �����ֱ� ��Ģ ����
        if (i > 0 && words[i - 1][words[i - 1].size() - 1]
            != words[i][0]) {

            answer = { num + 1, turn };
            break;
        }

        // ���ο� ����
        if ((num + 1) % n == 0) {
            turn++;
        }

        num++;
        num %= n;
        chk[words[i]] = 1;
    }

    return answer;
}