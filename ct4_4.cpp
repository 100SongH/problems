#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, d;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void turn_left() {
	d--;
	if (d == -1) d = 3;
}

int main() {

	cin >> n >> m;
	cin >> x >> y >> d;

	vector<vector<int>> map;
	map.assign(n, vector<int> (m, 1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	map[x][y] = 1;

	int ans = 1;
	int turn_time = 0;

	while (1) {
		turn_left();

		int nx = x + dx[d];
		int ny = y + dx[d];

		// ȸ���� ���� ���鿡 ������ ���� ĭ�� �����ϴ� ���
		if (map[nx][ny] == 0) {
			map[nx][ny] = 1;
			x = nx;
			y = ny;
			ans++;
			turn_time = 0;
			continue;
		}

		// ȸ���� ���� ���鿡 ������ ���� ĭ�� ���ų� �ٴ��� ���
		else
			turn_time++;

		// �� ���� ��� �� �� ���� ���
		if (turn_time == 4) {
			nx = x - dx[d];
			ny = y - dy[d];

			// �ڷ� �� �� �ִٸ� �̵�
			if (map[nx][ny] == 0) {
				x = nx;
				y = ny;
			}

			// �ڷ� �ٴٰ� ���� �ִ� ���
			else break;
			turn_time = 0;
		}
	}
	cout << ans;
}