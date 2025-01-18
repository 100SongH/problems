#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<string> string_set;
unordered_map<int, int> chk; // ���� �������� Ȯ��

void splitStr(string s) {

    int a = 1, b = 0;

    while (1) {

        b = s.find("}", a);

        if (b == -1) {
            string_set.push_back(s.substr(a));
            break;
        }

        string_set.push_back(s.substr(a, b - a));

        a = b + 2;
    }
}

bool cmp(string a, string b) {
    return a.length() < b.length();
}


vector<int> makeAnswer() {

    sort(string_set.begin(), string_set.end(), cmp);
    vector<int> answer;

    for (int i = 0; i < string_set.size(); ++i) {

        int a = 1, b = 0;
        int num = 0;

        // string�� , �� split
        while (1) {
            b = string_set[i].find(",", a);

            if (b == -1) {
                if (a < string_set[i].size()) {
                    num = stoi(string_set[i].substr(a));

                    if (!chk[num]) {
                        chk[num] = 1;
                        answer.push_back(num);
                    }
                }
                break;
            }

            num = stoi(string_set[i].substr(a, b - a));
            if (!chk[num]) {
                chk[num] = 1;
                answer.push_back(num);
            }
            a = b + 1;
        }

        cout << "\n";
    }
    return answer;
}

vector<int> solution(string s) {

    // }�� �������� split
    splitStr(s);

    return makeAnswer();
}