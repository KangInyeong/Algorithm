#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

struct Node {
	int y;
	int x;
};

string map[20];
queue<Node> q;
queue<Node> nq;
int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };
int my, mx;
int minresult = 21e8;
int visited[20][20] = { 0, };

void bfs(int y, int x) {
	
	q.push({ y,x });
	visited[y][x] = 1;
	
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + diry[i];
			int nx = now.x + dirx[i];

			if (ny < 0 || nx < 0 || ny >= 8 || nx >= 9)
				continue;

			if (visited[ny][nx] != 0)
				continue;
			
			if (map[ny][nx] == '_') {
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

			if (ny < 0 || nx < 0 || ny >= 8 || nx >= 9)
				continue;

			if (visited[ny][nx] != 0)
				continue;

			if (map[ny][nx] == '#') {
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

int main() {
	
	for (int i = 0; i < 8; i++) {
		cin >> map[i];	
	}

	bfs(7, 0);
	bfs2();

	cout << minresult-1;
}
