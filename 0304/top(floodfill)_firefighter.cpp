/*
초기화 항상 주의하기
*/
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

struct Node {
	int y;
	int x;
};

int n;
string map[20];
queue<Node> q;
queue<Node> ex;
int firey, firex;
int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };
int my, mx;
int minresult = 21e8;

int visited[20][20] = { 0, };

int bfs(int y, int x, int dy, int dx, int flag) {
	
	q.push({ y,x });
	visited[y][x] = 1;
	
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + diry[i];
			int nx = now.x + dirx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;
			if (visited[ny][nx] != 0)
				continue;
			if (flag == 0) {
				if (map[ny][nx] == '#' || map[ny][nx] == '$' || ((dy!=ny || dx!=nx)&&map[ny][nx] == 'A'))
					continue;
			}
			else {
				if (map[ny][nx] == '#')
					continue;
			}

			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny, nx });

		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << visited[i][j] << ' ';
		}cout << "\n";
	}cout << "\n";*/

	return visited[dy][dx] -1;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'A')
				ex.push({ i, j });
			else if (map[i][j] == '$') {
				firey = i;
				firex = j;
			}
		}		
	}

	cin >> my >> mx;

	while (!ex.empty()) {
		Node exting = ex.front();
		ex.pop();

		int re2 = bfs(my, mx, exting.y, exting.x, 0);
		if (re2 <= 0)
			re2 = 21e8;
		memset(visited, 0, sizeof(visited));
		int re1 = bfs(exting.y, exting.x, firey, firex, 1);
		int result = re1 + re2;
		if (result < minresult)
			minresult = result;
		memset(visited, 0, sizeof(visited));
	}

	cout << minresult;

}
