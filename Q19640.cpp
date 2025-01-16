#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Info {
	int D;
	int H;
	int lineNum; // ���� ������� ���� ��ȣ
	int num; // ���� ����

	bool operator < (Info right) const {

		if (D == right.D) {

			if (H == right.H) {
				return lineNum > right.lineNum;
			}

			return H < right.H;
		}
		return D < right.D;
	}
};

int n, m, k;
int answer;

vector<vector<Info>> line; // �� line�� �� �ִ� ��� ����
vector<int> index; // ���� ������ ����� ��ȣ
priority_queue<Info> pq; // ������ ����� ����

void input() {

	cin >> n >> m >> k;

	line.resize(m);
	index.resize(m);

	for (int i = 0; i < n; ++i) {

		int d, h;
		cin >> d >> h;

		int tmp_line = i % m;

		line[tmp_line].push_back({ d, h, tmp_line, i + 1 });
	}

}

void solution() {

	// �ʱ� ���� �� pq�� �ֱ�
	for (int i = 0; i < m; ++i) {
		
		if (!line[i].empty()) {
			pq.push(line[i][0]);
			index[i]++;
		}
	}
	while (1) {
		
		// �� ���� ���� �� ���� ���� �̿��� ���
		Info now = pq.top();
		pq.pop();


		if (now.num == k + 1)
			break;

		answer++;

		// now.lineNum�� ��� ��� �̿�
		if (index[now.lineNum] >= line[now.lineNum].size()) {
			continue;
		}

		pq.push(line[now.lineNum][index[now.lineNum]]);
		index[now.lineNum]++;
	}

	cout << answer;
	
}

int main() {

	input();

	solution();
}