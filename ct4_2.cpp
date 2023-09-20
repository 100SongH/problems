#include <iostream>
#include <string>
using namespace std;

bool check(int h, int m, int s) {
	// h�� 0 ~ 23 : ���� �ڸ����� 3�ϼ��� ����
	if (h % 10 == 3)
		return true;
	
	// m�� ��� ���� �ڸ����� ���� �ڸ��� ��� ����
	if (m % 10 == 3 || m / 10 == 3)
		return true;

	// s�� ��� ���� �ڸ����� ���� �ڸ��� ��� ����

	if (s % 10 == 3 || s / 10 == 3)
		return true;
	
	return false;

}
int main() {
	int n;
	cin >> n;
	
	int cnt = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 59; j++) {
			for (int k = 0; k <= 59; k++) {
				string str = " " + i + j + k;
				if (check(i, j, k)) {
					cnt++;
				}
			}
		}
	}
	cout << cnt;
}