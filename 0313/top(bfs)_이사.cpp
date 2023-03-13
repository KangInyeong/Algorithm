/*
visited를 1로 갱신하는 것이 아닌 visited[now]에 1을 더해서 갱신.
단, visited가 0보다 이미 클 경우에는 방문한 곳이므로 continue하는 조건이 들어간다는 점을 기억하자.
*/
#include <iostream>
#include <queue>
using namespace std; 

int n, m; 
int visited[11]; 
int mat[11][11];
int r, k; 
int cnt; 

void bfs(int node) {
	queue<int>q;
	q.push(node);

	visited[node] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (visited[now] - 1 <= k)
			cnt++; 

		if (visited[now] - 1 > k)
			break; 

		for (int i = 1; i <= n; i++) {
			if (mat[now][i] == 0)
				continue;
			if (visited[i] > 0)
				continue;
			visited[i] = visited[now] + 1; 
			q.push(i); 
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		mat[from][to] = 1;
		mat[to][from] = 1; 
	}
	cin >> r >> k; 
	bfs(r); 
	cout << cnt;
}
