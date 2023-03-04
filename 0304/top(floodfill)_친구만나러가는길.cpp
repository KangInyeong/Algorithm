/*
시골쥐 - 상하좌우 이동
이동 시, 한 칸에 1의 시간 소요
치즈 먹기는 시간 소요 X
도시쥐는 움직이지 않음
인풋 - 도시쥐의 집 크기 & 집의 정보
아웃풋 - 시골쥐가 치즈 먹고 도시쥐에게 가기까지 최소 이동 시간

<설계>
1번으로 치즈 먹으러 가는 최소 이동 시간 찾기
2번으로 치즈에서 도시쥐에게 가는 최소 이동 시간 찾기
=> 치즈에서 시골쥐 & 치즈에서 도시쥐 시간의 
*/

#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y;
	int x;
};

int n, m;
char map[20][20];
int visited[20][20];
queue<Node>q;
int smy, smx, dmy, dmx, cy, cx;

int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };

int dist = 0;

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

			if (map[ny][nx] == 'x')
				continue;

			if (visited[ny][nx] != 0)
				continue;

			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny,nx });
		}

	}

	dist += visited[smy][smx]-1;
	dist += visited[dmy][dmx]-1;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				smy = i;
				smx = j;
			}
			else if (map[i][j] == 'D') {
				dmy = i;
				dmx = j;
			}
			else if (map[i][j] == 'C') {
				cy = i;
				cx = j;
			}
		}
	}

	bfs(cy, cx);

	cout << dist;
}
