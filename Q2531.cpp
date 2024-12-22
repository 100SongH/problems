#include <iostream>
#include <vector>
using namespace std;

int n, d, k, c;
int type; // �� ����

int answer;

vector<int> arr; // �ʹ� ����
vector<int> dat; // �ʹ� ���� ī��Ʈ

void input() {

	cin >> n >> d >> k >> c;

	dat.resize(d + 1);
	arr.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
}

void solution() {
	int sindex = 0, eindex = k - 1;
	dat[c]++;
	type++;

	for (int i = 0; i < k; ++i) {

		int now = arr[i]; // ���� �ʹ� ��ȣ
		
		// ó�� ������ �ʹ� -> ����++
		if (dat[now] == 0) {
			type++;
		}

		dat[now]++;
	}

	answer = type;
	
	while (1) {
		
		// ���� �տ� �ִ� �ʹ� �����
		dat[arr[sindex]]--;
		if (dat[arr[sindex]] == 0)
			type--;


		sindex = (sindex + 1) % n;
		eindex = (eindex + 1) % n;

		if (dat[arr[eindex]] == 0)
			type++;
		

		dat[arr[eindex]]++;

		answer = max(answer, type);

		// ó������ ���ƿ�
		if (sindex == 0)
			break;

	}

	cout << answer;
}

int main() {

	input();

	solution();

}