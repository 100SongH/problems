#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int t;
string s; // ���� ���ڿ�
int times; // ��ȯ Ƚ��

string answer;
int ans;
bool flag; // ��������

void init() {
    ans = -1;
    flag = false;
}

void input() {
    cin >> s >> times;
    // 1. 88832 ó�� �ִ��� ������ ��� (��ȸ 2��)
    // 2. 82883 ó�� �ִ��� ������ �ʴ� ��� (��ȸ 1��)

    answer = s;

    sort(answer.begin(), answer.end(), greater<>());
}

bool isTwo(string s) {
    int DAT[10];

    for (int i = 0; i < 10; ++i) {
        DAT[i] = 0;
    }
    for (int i = 0; i < s.length(); ++i) {
        DAT[s[i] - '0']++;
    }

    for (int i = 0; i < 10; ++i) {
        if (DAT[i] > 1)
            return true;
    }

    return false;
}

void dfs(string s, int cnt) {
    // 3. �ִ��� ã�� ���
    // ���� Ƚ���� ���� �ٸ��� ó��
    if (s == answer) {
        // ���� Ƚ��
        int left = times - cnt;

        // ¦��
        if (left % 2 == 0) {
            ans = stoi(s);
            flag = true;
            return;
        }

        // Ȧ��
        else {
            // �ߺ��Ǵ� �� ����
            if (isTwo(s)) {
                ans = stoi(s);
                flag = true;
                return;
            }
            else {
                swap(s[s.length() - 1], s[s.length() - 2]);
                ans = stoi(s);
                flag = true;
                return;
            }
        }
    }

    // 2. ��������
    // �ִ��� ����� ���
    // �ִ��� ������ ���ϴ� ���
    // Ƚ���� ���� ���
    if (cnt == times) {
        ans = max(ans, stoi(s));

        return;
    }

    // 1. �⺻ ���
    // �ϳ��� ī�� ����, swap�ϴ� ��� ���
    for (int i = 0; i < s.size() - 1; ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
            // left <= right : �ٲٴ°� ���信 �����
            if (s[i] >= s[j])
                continue;

            swap(s[i], s[j]);

            dfs(s, cnt + 1);

            if (flag)
                return;
            swap(s[i], s[j]);


        }
    }
}

void solution() {
    dfs(s, 0);
}

int main() {
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        init();

        input();

        solution();

        cout << "#" << tc << " " << ans << "\n";
    }
}