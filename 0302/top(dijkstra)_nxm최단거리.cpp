#include <iostream>
#include <queue>
using namespace std;

struct Edge {
	int y;
	int x;
	int cost;

	bool operator < (Edge next) const {
		if (cost < next.cost)
			return false;
		if (cost > next.cost)
			return true;
		return false;
	}
};

int n, m;
int map[100][100];
int diry[4] = {-1, 1, 0, 0};
int dirx[4] = {0,0,-1,1};

void dijkstra(int sy, int sx) {

	priority_queue<Edge>pq;
	pq.push({ sy, sx, map[sy][sx]});

	int dist[100][100] = { 0, };
	int MAX = 21e8;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = MAX;
		}
	}
	dist[sy][sx] = map[sy][sx];
	
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (dist[now.y][now.x] < now.cost)
			continue;

		for (int i = 0; i < 4; i++) {

			int ny = now.y + diry[i];
			int nx = now.x + dirx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			Edge next = { ny, nx, map[ny][nx] };
			int ncost = dist[now.y][now.x] + next.cost;
			if (dist[next.y][next.x] <= ncost)
				continue;
			dist[next.y][next.x] = ncost;
			pq.push({ next.y, next.x, ncost });
		}
	}

	cout << dist[n - 1][m - 1];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	dijkstra(0, 0);
}
