#include <iostream>
using namespace std;

// v : ��� ����, e : ���� ���� (union ���� ����)
// ����� ���� �ִ� 100,000��
int v, e;
int parent[100001];

// Ư�� ���Ұ� ���� ���� ã��
int findParent(int x) {
	// ��Ʈ ��带 ã�� ������ ��������� ȣ��
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

// union
void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	// union ���� ����
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		unionParent(a, b);
	}

	cout << "�� ���Ұ� ���� ���� : ";
	for (int i = 1; i <= v; i++) {
		cout << findParent(i) << " ";
	}
	cout << "\n";

	cout << "�θ� ���̺� : ";
	for (int i = 1; i <= v; i++) {
		cout << parent[i] << " ";
	}
	cout << "\n";
}