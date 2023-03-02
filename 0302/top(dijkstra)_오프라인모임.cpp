#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
	int to;
	int cost;

	bool operator < (Edge next) const {
		if (cost < next.cost)
			return false;
		if (cost > next.cost)
			return true; 
		return false;
	}
};

int n, m, p;
vector<Edge>al[10001];
int tmp;

void dijkstra(int start, int final) {

	priority_queue<Edge> pq;
	pq.push({start, 0});

	int dist[1001] = { 0, };
	int MAX = 21e8;
	for (int i = 0; i <= n; i++) {
		dist[i] = MAX;
	}
	dist[start] = 0;

	int visited[1001] = { 0, };

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (visited[now.to] == 1)
			continue;
		visited[now.to] = 1;

		for (int i = 0; i < al[now.to].size(); i++) {
			Edge next = al[now.to][i];

			int ncost = dist[now.to] + next.cost;
			if (dist[next.to] <= ncost)
				continue;

			dist[next.to] = ncost;
			pq.push({ next.to, ncost });
		}
	}

	tmp += dist[final];
}

int main() {
	cin >> n >> m >> p;
	int from, to, cost;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
		al[from].push_back({ to, cost });
	}

	int ans = -21e8;
	for (int i = 1; i <= n; i++) {
		dijkstra(i, p);
		dijkstra(p, i);
		ans = max(ans, tmp);
		tmp = 0;
	}
	cout << ans;

}
