#include <iostream>
using namespace std;


int n, m;
int graph[1001][1001];

// DFS�� Ư�� ��带 �湮�ϰ� ����� ��� ���鵵 �湮
bool dfs(int x, int y) {
	// �־��� ������ ����� ��� ����
	if (x <= -1 || x >= n || y <= -1 || y >= m)
		return false;

	// ���� ��带 �湮���� �ʾҴٸ�
	if (graph[x][y] == 0) {
		// �ش� ��� �湮ó��
		graph[x][y] = 1;

		//��, ��, ��, ���� ��ġ�鵵 ��� ��������� ȣ��
		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);
		return true;
	}
	return false;
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// ���� ���� �־����� ������ scanf�� �̿��Ͽ� graph�� �� �־��ֱ�
			scanf("%1d", &graph[i][j]);
		}
	}

	// ��� ��忡 ���Ͽ� ����� ä���
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// ���� ��ġ���� DFS ����
			if (dfs(i, j))
				ans++;
		}
	}
	cout << ans;
}