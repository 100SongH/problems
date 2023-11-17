#include <iostream>
#include <queue>
using namespace std;

// V : ��� ����, E :���� ����
// ��� ������ �ִ� 100,000��
int v, e;

// �������� �ʱ�ȭ
int indegree[100001];

// ����� ���� ����
vector<int> graph[100001];

// ���� ���� �Լ�
void topologySort() {
	vector<int> result; // ���� ����� ���� ����Ʈ
	queue<int> q;

	for (int i = 1; i <= v; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		result.push_back(now);

		// ����� �������� -1
		for (int i = 0; i < graph[now].size(); i++) {
			indegree[graph[now][i]]--;

			// ���Ӱ� �������� 0�� �Ǵ� ��� ť�� ����
			if (indegree[graph[now][i]] == 0)
				q.push(graph[now][i]);
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}

int main() {
	cin >> v >> e;

	// ���� ���� �Է¹ޱ�
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b); // a -> b;
		indegree[b]++;
	}

	topologySort();
}