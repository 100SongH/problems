#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int t;
int n;
int cnt;

vector<vector<int>> map;
vector<vector<int>> jjol;
pair<int, int> two; // �� ��ġ

// �����¿�
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };


void init() {

	cnt = 0;

	map.clear();
	jjol.clear();
	two = { 0, 0 };
}


void input() {
	cin >> n;

	map.assign(n, vector<int>(n, 0));
	jjol.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				two = { i, j };
			}
		}
	}
}


void dfs(int sy, int sx, int turn) {
	if (turn >= 3) {
		return;
	}

	for (int i = 0; i < 4; ++i) {
		int ny = sy + dy[i];
		int nx = sx + dx[i];

		int flag = 0;

		// map�� ��� ���
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
			continue;
		}

		// 1�� ã�� �� ����
		while (1) {
			if (map[ny][nx] != 0) {
				flag = 1;
				break;
			}

			ny += dy[i];
			nx += dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
				break;
			}
		}

		// �پ���� ���� ���� ��
		if (!flag) {
			continue;
		}

		// �پ���� ���� ���� ��
		// ���� ��ġ : �پ���� ��

		// �� ��° �� chk
		int chk = 0;
		while (1) {
			if (chk) {
				break;
			}

			ny += dy[i];
			nx += dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) {

				break;
			}

			if (map[ny][nx] == 1) {

				jjol[ny][nx] = 1;

				map[ny][nx] = 0;

				dfs(ny, nx, turn + 1);

				map[ny][nx] = 1;
				chk = 1;
				break;
			}

			if (map[ny][nx] == 0) {
				dfs(ny, nx, turn + 1);

				if (chk) {
					break;
				}
			}

		}
	}
}


void solution() {
	map[two.first][two.second] = 0;

	dfs(two.first, two.second, 0);
	 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (jjol[i][j] != 0) {
				cnt++;
			}
		}
	}
}

int main() {
	cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		init();

		input();

		solution();
		

		cout << "#" << tc << " " << cnt << "\n";
	}
}