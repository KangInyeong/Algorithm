#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct Node {
	int y;
	int x;
};

int h, w;
int map[100][100];
int by, bx;
int ydir[8] = { -3,-3,-2,2,3,3,2,-2 };
int xdir[8] = { -2,2,3,3,2,-2,-3,-3 };
int flag = 0;
int visited[100][100];

int bfs(int y, int x) {
	queue<Node>q;
	q.push({ y,x });
	visited[y][x] = 1;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w)
				continue;

			if (map[ny][nx] == 1)
				continue;

			if (visited[ny][nx])
				continue;

			map[ny][nx] = map[now.y][now.x] + 1;
			visited[ny][nx] = 1;

			if (ny == by && nx == bx) {
				flag = 1;
			}

			if (flag == 1)
				break;

			q.push({ ny,nx });
		}

	}
  
	if (flag == 1)
		return map[by][bx];
	return -1;
}

int main() {
	cin >> h >> w;
	int r, c;
	cin >> r >> c;
	cin >> by >> bx;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int y, x;
		cin >> y >> x;
		map[y][x] = 1;
	}

  
	map[r][c] = 0;
	int result = bfs(r, c);
	cout << result;
}
