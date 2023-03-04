/*
무기에서 용사 & 마왕까지의 거리를 구하는데
무기가 갖혀있는 경우, 마왕이 갖혀있는 경우 등 dist가 하나라도 0이 나올 때의 예외처리를 잘 
*/
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct Node {
	int y;
	int x;
};

int n, m;
char map[10][10];
int yy, yx, my, mx, sy, sx, ty, tx;
int dist;
queue<Node>q;
int ydir[4] = {-1,1,0,0};
int xdir[4] = {0,0,-1,1};

int bfs(int y, int x) {

	int visited[10][10] = {0,};

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

			if (visited[ny][nx] != 0)
				continue;

			if (map[ny][nx] == 'x')
				continue;

			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny, nx });
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << ' ';
		}cout << "\n";
	}*/
	
	dist += visited[yy][yx]-1;
	if (dist <= 0)
		return -1;
	dist += visited[my][mx]-1;
	if (visited[my][mx] == 0)
		return -1;
	/*if (dist == 0)
		return -1;*/
	
	return dist;
}
int T;

int main() {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n >> m;
		while (!q.empty()) {
			q.pop();
		}
		memset(map, 0, sizeof(map));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'Y') {
					yy = i;
					yx = j;
				}
				else if (map[i][j] == 'M') {
					my = i;
					mx = j;
				}
				else if (map[i][j] == 'S') {
					sy = i;
					sx = j;
				}
				else if (map[i][j] == 'T') {
					ty = i;
					tx = j;
				}
			}
		}
		int mhp;
		cin >> mhp;

		dist = 0;
		int sresult = bfs(sy, sx);
		dist = 0;
		int tresult = bfs(ty, tx);

		if (sresult <= 0 && tresult <= 0) {
			cout << '#' << t << " the world is doomed" << endl;
		}
		else if (sresult <= 0) {
			int tcnt = mhp / 2;

			if (mhp % 2 != 0)
				tcnt++;

			cout << '#' << t << ' ' << tresult+tcnt << endl;
		}
		else if (tresult <= 0) {
			int scnt = mhp / 5; 
			
			if (mhp % 5 != 0)
				scnt++;

			cout << '#' << t << ' ' << sresult + scnt << endl;

		}
		else {
			int scnt = mhp / 5;
			int tcnt = mhp / 2;

			if (mhp % 5 != 0)
				scnt++;
			if (mhp % 2 != 0)
				tcnt++;

			//cout << scnt << ' ' << tcnt << endl;
			//cout << sresult  << ' ' << tresult << endl;
			int finalresult = min(sresult + scnt, tresult + tcnt);
			cout << '#' << t << ' ' << finalresult << endl;
		}

	}
	
}
