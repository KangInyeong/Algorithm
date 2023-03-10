#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Node {
	int y;
	int x;
};
int n, m;
int MAP[100][100];
queue<Node>q;
int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };
int cheeseCnt;
int visited[100][100];

void bfs(int y, int x) {
	q.push({ y, x });
	visited[y][x] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + diry[i];
			int nx = now.x + dirx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (visited[ny][nx] != 0)
				continue;

			if (MAP[ny][nx] == 0) {
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
			else {
				MAP[ny][nx] = 0;
				visited[ny][nx] = 1;
				cheeseCnt--;
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 1) 
				cheeseCnt++;
		}
	}
	int day = 0;
	int answer = cheeseCnt;
	while (cheeseCnt != 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (MAP[i][j] == 0) {
					
					bfs(i, j);
          
					if (cheeseCnt == 0)
						break;
					answer = cheeseCnt;
					break;
				}
			}
		}
		day++;
		while (!q.empty()) q.pop();
		memset(visited, 0, sizeof(visited));
	}

	cout << day << '\n';
	cout << answer;

}
