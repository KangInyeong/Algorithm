#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

struct Node {
	int y;
	int x;
};

int map[200][200];
queue<Node> q;
queue<Node> nq;
int n, m;
int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };
int item, iy, ix;
int item2, iy2, ix2;
int minresult = 21e8;
int visited[200][200] = { 0, };

void bfs(int y, int x) {
	
	q.push({ y,x });
	visited[y][x] = 1;
	
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + diry[i];
			int nx = now.x + dirx[i];

      //항상 범위 조심
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (visited[ny][nx] != 0)
				continue;

			if (map[ny][nx] == 0) {
				visited[ny][nx] = 1;
				nq.push({ ny, nx });
				continue;
			}

			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny, nx });
		}
	}


}

void bfs2() {

	while (!nq.empty()) {
		Node now = nq.front();
		nq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + diry[i];
			int nx = now.x + dirx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (visited[ny][nx] != 0)
				continue;

			if (map[ny][nx] == item2) {
				int tmp = visited[now.y][now.x] + 1;
				if (tmp < minresult)
					minresult = tmp;

				continue;
			}

			visited[ny][nx] = visited[now.y][now.x] + 1;
			nq.push({ ny, nx });

		}
	}
}

int flag = 0;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && flag == 0) {
				item = map[i][j];
				iy = i;
				ix = j;
				flag = 1;
			}
			if (map[i][j] != 0 && map[i][j] != item && flag == 1) {
				item2 = map[i][j];
			}
		}
	}

	bfs(iy, ix);
	bfs2();

	cout << minresult-1;
}
