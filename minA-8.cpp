#include <iostream>
#include <vector>
using namespace std;

int t;
int n;
long long ans;

vector<int> arr;
vector<int> visited; // ǳ���� �������� Ȯ�� (�������� 1 �ƴϸ� 0)
vector<int> dat; // �ߺ� Ȯ��


void init() {
	
	arr.clear();
	visited.clear();
	dat.clear();

	ans = 0;
}

void input() {
	cin >> n;

	arr.resize(n);
	visited.resize(n);
	dat.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
}

// �ߺ��� �Ұ�����, ������ ��� �ִ�
void dfs(int now, long long sum) {
	if (now >= n) {

		ans = max(sum, ans);
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (dat[i] == 1)
			continue;

		dat[i] = 1;
		visited[i] = 1;

		// ���� �� �ִ� ����
		long long tmp = 0;

		// if�� ���� ���� ����
		int flag = 0;
		// ������ �ƹ��͵� ���� ��
		if (now == n - 1) {
			flag = 1;
			tmp = arr[i];
		}
			
		
		if (!flag) {
			int left = i - 1, right = i + 1;

			// ������ ���� ���� ǳ�� ã��
			while (1) {
				if (left < 0)
					break;

				if (visited[left] != 1) {
					break;
				}
				left--;
			}

			// ������ ���� ������ ǳ�� ã��
			while (1) {
				if (right >= n)
					break;

				if (visited[right] != 1)
					break;

				right++;
			}

			// ���� �� ���� ��
			if (left >= 0 && left < n && right >= 0 && right < n) {
				tmp = arr[left] * arr[right];
			}
			// ���� �� ���� ��
			else if ((left < 0 || left >= n) && (right < 0 || right >= n)) {
				tmp = arr[i];
			}
			// ���ʸ� ���� ��
			else {
				if (left < 0)
					tmp = arr[right];
				else if (right >= n) {
					tmp = arr[left];
				}
			}
			
		}
		
		dfs(now + 1, sum + tmp);

		visited[i] = 0;
		dat[i] = 0;

	}
}


int main() {
	cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		init();

		input();

		dfs(0, 0);
		 
		cout << "#" << tc << " " << ans << "\n";
	}
}