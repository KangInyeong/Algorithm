/*
2종류의 미생물 존재.
A,B타입 미생물 -> 각각 몇개가 존재? 가장 큰 개체의 크기는?
*/
#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y;
	int x;
};

int n, m;
char MAP[200][200];
queue<Node> q;
int visited[200][200];
int acnt, bcnt;
int bigcell = -21e8;

int ydir[4] = { -1,1,0,0 };
int xdir[4] = { 0,0,-1,1 };

void bfs(int y, int x) {
	int cellsize = 1;
	q.push({ y, x });
	visited[y][x] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (visited[ny][nx] == 1)
				continue;

			if (MAP[ny][nx] != MAP[now.y][now.x])
				continue;

			cellsize++;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
	
	if (cellsize > bigcell)
		bigcell = cellsize;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (MAP[i][j] != '_')
			{
				if (visited[i][j] == 1)
					continue;
				bfs(i, j);
				if (MAP[i][j] == 'A')
					acnt++;
				else if (MAP[i][j] == 'B')
					bcnt++;
			}
		}
	}

	cout << acnt << ' ' << bcnt << endl;
	cout << bigcell;
}
