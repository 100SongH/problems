#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t;
int n;

int sum[2]; // 0 : A ������, 1 : B ������

int res; // �ּڰ� (���)

vector<vector<int>> graph; // ���� �׷���
vector<int> arr; // ������ ��

vector<int> group; // ������ ������ 1 : ������ A, 2 : ������ B
vector<int> visited; // ����Ǿ� �ִ��� Ȯ��

void init() {
	graph.clear();
	arr.clear();
	group.clear();
	visited.clear();

	sum[0] = 0;
	sum[1] = 0;
	res = 2e9;

}

void input() {
	cin >> n;

	group.resize(n);
	graph.resize(n);
	visited.resize(n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int tmp;
			cin >> tmp;

			if (tmp) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	arr.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
}


// ���� �Ǿ� ������ true
// �׷��� ������ false 
bool bfs(int start, int nowGroup) {
	visited.clear();
	visited.resize(n);

	queue<int> q;

	visited[start] = 1;
	q.push(start);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); ++i) {
			int y = graph[x][i];

			// �̹� �湮
			if (visited[y])
				continue;
			
			if (group[y] != nowGroup)
				continue;
			
			visited[y] = 1;
			q.push(y);
		}
	}

	// ����Ǿ� �ִ��� Ȯ��
	for (int i = 0; i < n; ++i) {
		// group �� ���� ���� Ȯ��
		if (group[i] != nowGroup)
			continue;

		if (visited[i] == 0) {
			sum[nowGroup - 1] = 0;
			return false;
		}
			
		sum[nowGroup - 1] += arr[i];
	}

	return true;

}

void solution() {

	sum[0] = 0;
	sum[1] = 0;

	int a = -1; // ó�� ������ A�� ������ ����
	int b = -1; // ó�� ������ B�� ������ ����

	for (int i = 0; i < n; ++i) {
		if (group[i] == 1) {
			a = i;
			break;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (group[i] == 2) {
			b = i;
			break;
		}
	}

	// ��� ������ �ϳ��� ������
	if (a == -1 || b == -1) {
		return;
	}


	// ��ȿ���� ���� ������
	if (!bfs(a, 1)) return;


	if (!bfs(b, 2)) return;

	if (abs(sum[0] - sum[1]) < res) {
		res = abs(sum[0] - sum[1]);
	}
	return;
}

void dfs(int now) {
	if (now >= n) {
		// ������ ������ �� ��
		solution();
		return;
	}

	for (int i = 1; i <= 2; ++i) {
		// ����
		group[now] = i;

		// ���� �ܰ�
		dfs(now + 1);

		// ����
		group[now] = 0;

	}
}

int main() {
	cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		init();

		input();

		dfs(0);

		cout << "#" << tc << " " << res << endl;
	}
}