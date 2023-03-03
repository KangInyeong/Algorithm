#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y;
	int x;
};

int n, m;
int map[100][100];
int visited[100][100];
int cnt;
queue<Node> q;
int diry[4] = {-1,1,0,0};
int dirx[4] = {0,0,-1,1};

void bfs(int y, int x) {
	q.push({ y,x });
	visited[y][x] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + diry[i];
			int nx = now.x + dirx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (visited[ny][nx] == 1)
				continue;

			if (map[ny][nx] == 0)
				continue;

			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) {
				bfs(i, j);
				cnt++;
			}

		}
	}

	cout << cnt;

}
