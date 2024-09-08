#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

struct Node {
    int x, y;
    int dir;
    int energy;
    int isAlive;
};

int t;
int n;

int cnt;
int ans;

int MAP[4002][4002];
vector<Node> v;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void init() {
    memset(MAP, 0, sizeof(MAP));

    ans = 0;
    cnt = 0;

    v.resize(0);
}

void input() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x, y, dir, energy;
        cin >> x >> y >> dir >> energy;

        // ����
        x = (x + 1000) * 2;
        y = (y + 1000) * 2;

        cnt++; // ����ִ� ���� ����
        v.push_back({ x, y, dir, energy, 1 });
        
        MAP[x][y] = 1; // ������ ���� ���� üũ
    }
}

void solution() {
    // 1. �ϴ� �����̱�
    while (cnt > 0) {
        for (int i = 0; i < v.size(); ++i) {
         
            Node now = v[i];

            if (now.isAlive == 0)
                continue;

            int nx = now.x + dx[now.dir];
            int ny = now.y + dy[now.dir];

            if (ny >= 4000 || nx >= 4000 || ny < 0 || nx < 0) {
                v[i].isAlive = 0;
                MAP[now.x][now.y] = 0;
                cnt--;
                continue;
            }

            // �̵�
            MAP[nx][ny] += 1;

            // ���� ��ǥ�� �����ֱ�
            MAP[now.x][now.y] = 0;

            // ��ġ ����
            v[i].x = nx;
            v[i].y = ny;
        }

        // 2. �浹 ���ο� ���� ����Ǵ� ������ ����
        // 2�� �̻��� ���ڰ� ������ ��, ����Ǵ� �������� ����?

        for (int i = 0; i < v.size(); ++i) {
            Node now = v[i]; // ���ŵ� ���� Ȯ��

            if (now.isAlive == 0)
                continue;

            if (MAP[now.x][now.y] >= 2) {
                ans += now.energy;
                v[i].isAlive = 0;
                cnt--;
            }
        }

        for (int i = 0; i < v.size(); ++i) {
            Node now = v[i];

            if (MAP[now.x][now.y] >= 2) {
                MAP[now.x][now.y] = 0;
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

        cout << "#" << tc << " " << ans << "\n";
    }
}