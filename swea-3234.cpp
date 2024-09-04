#include <iostream>
#include <vector>
using namespace std;

int t;

int n; // ����
int arr[10]; // ����
int expo[10];
int fact[10];

int visited[10]; // index: ���� ���� ����, value: ��� ����
vector<int> path;

vector<int> LeftChoo;
vector<int> RightChoo;

int ans;
int cnt;
int sum;

void init() {
	ans = 0;
	cnt = 0;
	sum = 0;

	path.clear();
	LeftChoo.clear();
	RightChoo.clear();

	for (int i = 0; i < 10; ++i) {
		visited[i] = 0;
		arr[i] = 0;
	}
}

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];

		sum += arr[i];
	}
}

void dfs1(int now) {
	if (now >= n) {
		for (int i = 0; i < path.size(); ++i) {
			cout << path[i] << " ";
		}
		cout << "\n";
		cnt++;

		return;
	}

	for (int i = 0; i < n; ++i) {
		if (visited[i])
			continue;

		path.push_back(arr[i]);
		visited[i] = 1;

		dfs1(now + 1);

		path.pop_back();
		visited[i] = 0;
	}
}

void dfs2(int now, int left, int right) {
	// ���� ���� ����, ������ ������ �ø��� ��� ����� �� Ȯ��
	// ���� ���� ���� X

	if (now >= n) {
		cout << "result(" << cnt << ")\n";


		for (int i = 0; i < LeftChoo.size(); ++i) {
			cout << LeftChoo[i] << " ";
		}
		cout << " | ";


		for (int i = 0; i < RightChoo.size(); ++i) {
			cout << RightChoo[i] << " ";
		}
		cout << "\n";
		cnt++;
		return;
	}

	for (int i = 0; i < n; ++i) {
		
		if (visited[i])
			continue;

		// ������ ���ʺ��� ���ƾ� ��
		LeftChoo.push_back(arr[i]);
		visited[i] = 1;


		dfs2(now + 1, left + arr[i], right);

		LeftChoo.pop_back();
		visited[i] = 0;
		
		// ��Ʈ��ŷ 1
		// �߸� �÷��� �� �������� �� ũ�� �� ���� ���� ���� -> continue
		if (left < right + arr[i])
			continue;

		// ������ ����
		RightChoo.push_back(arr[i]);
		visited[i] = 1;

		dfs2(now + 1, left, right + arr[i]);

		RightChoo.pop_back();
		visited[i] = 0;
	}
}

void dfs3(int now, int left, int right) {
	// ���� ���� ����, ������ ������ �ø��� ��� ����� �� Ȯ��
	// ���� ���� ���� X

	if (now >= n) {
		cnt++;
		return;
	}

	// ���� �� ���� ���� �̻��� �Ѿ��ٸ� -> continue
	// ���� �ִ� �����ߵ�� ���� �� �ִ� ���յ��� ī����

	for (int i = 0; i < n; ++i) {

		if (visited[i])
			continue;

		if (left > sum / 2) {
			cnt += (expo[n - now] * fact[n - now]);
			return;
			
		}
		// ������ ���ʺ��� ���ƾ� ��

		visited[i] = 1;

		dfs3(now + 1, left + arr[i], right);

		visited[i] = 0;

		// ��Ʈ��ŷ 1
		// �߸� �÷��� �� �������� �� ũ�� �� ���� ���� ���� -> continue
		if (left < right + arr[i])
			continue;

		// ������ ����
		visited[i] = 1;

		dfs3(now + 1, left, right + arr[i]);

		visited[i] = 0;
	}
}
void solution() {
	dfs3(0, 0, 0);
	ans = cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fact[0] = 1;
	expo[0] = 1;
	for (int i = 1; i < 10; ++i) {
		fact[i] = fact[i - 1] * i;
		expo[i] = expo[i - 1] * 2;

	}

	cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		init();

		input();

		solution();

		cout << "#" << tc << " " << ans << "\n";
	}
}