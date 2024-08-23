#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
int res; // �� ����

vector<int> ele;
vector<queue<int>> order;

vector<int> multi;

void input() {
	cin >> n >> k;

	ele.resize(k + 1);
	order.resize(k + 1);

	for (int i = 0; i < k; ++i) {
		int tmp;
		cin >> tmp;

		ele[i] = tmp;

		order[tmp].push(i);
	}

	multi.resize(n);
	

}

void solution() {
	
	for (int i = 0; i < k; ++i) {
		// ���� Ȯ���� �����ǰ ��ȣ
		int now = ele[i];
		int flag = 0;


		// ��Ƽ�ǿ� �����ִ���
		for (int j = 0; j < n; ++j) {
			if (multi[j] == now) {
				flag = 1;
				break;
			}
		}

		// ���������� ���� �ܰ�
		if (flag) {
			if (!order[now].empty())
				order[now].pop();
			continue;
		}
			
		// ���� �ڸ��� ���� ��
		for (int j = 0; j < n; ++j) {
			if (multi[j] == 0) {
				multi[j] = now;
				flag = 1;
				break;
			}
		}

		if (flag) {
			if (!order[now].empty())
				order[now].pop();
			continue;
		}
			
		// �������� ���� ��
		// ���� �ִ� �����ǰ �� ������ ���� �ֱٿ� ������ �ʴ� �����ǰ ����
		
		int lateIndex = 0; // �����ִ� ��Ƽ�� ��ġ

		for (int j = 0; j < n; ++j) {

			// ������ �� �̻� ������ ����
			if (order[multi[j]].empty()) {
				lateIndex = j;
				break;
			}

			if (order[multi[j]].front() > order[multi[lateIndex]].front()) {
				lateIndex = j;
			}
		}
		

		res++;
		multi[lateIndex] = now;

		if (order[now].empty())
			continue;

		order[now].pop();
	}
}

int main() {
	input();

	solution();

	cout << res;
}