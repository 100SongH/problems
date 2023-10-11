#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	int start = 0;
	// �ִ� ������ ���� �ִ����� �Ϸ��� �� ã�ƾ� �� -> �ð� �ҿ�
	int end = 1e9;

	int res = 0;
	while (start <= end) {
		long long int total = 0;
		int mid = (start + end) / 2;

		// �߶��� ���� �� �� ���
		for (int i = 0; i < n; i++) {
			if (arr[i] > mid) total += arr[i] - mid;
		}

		// ���� ���� ������ ���
		if (total < m)
			end = mid - 1;
		// ���� ���� ����� ���
		else {
			// �ִ��� �� �߶��� ���� ����
			res = mid;
			start = mid + 1;
		}
	}

	cout << res;
}