#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[201][201];

// �̵��� �� ���� ���� ���� (��, ��, ��, ��)
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });

	// ť�� �� ������ �ݺ�
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		
		// ���� ��ġ���� 4���� �������� ��ġ Ȯ��
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// �̷� ������ ��� ��� ����
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			//���� ��� ����
			if (map[nx][ny] == 0)
				continue;

			// �ش� ��带 ó�� �湮�ϴ� ��쿡�� �ִ� �Ÿ� ���
			if (map[nx][ny] == 1) {
				map[nx][ny] = map[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	return map[n - 1][m - 1];
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	cout << bfs(0, 0);
}