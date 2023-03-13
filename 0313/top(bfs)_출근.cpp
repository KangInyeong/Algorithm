/*
조건 체크 주의.
문제 잘 읽어서 최단 거리를 구하는 것인지 경로들의 개수를 구하는 것인지 파악하기.
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n, m, t;
int MAP[101][101];
int visited[101];
queue<int>q;
int cnt;

void bfs(int start) {

	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {

		int now = q.front();
		q.pop();

		if (now == t)
			continue;
		
		//cout << now << ' ';
		for (int i = 1; i <= n; i++) {
			if (MAP[now][i] == 0)
				continue;
			if (visited[i] > 0)
				continue;
		
			q.push(i);

			if(i == n && visited[i] > visited[now] + 1 && visited[i] !=0)
				visited[i] = visited[now] + 1;
			else
				visited[i] = visited[now] + 1;
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		MAP[a][b] = 1;
		MAP[b][a] = 1;
	}
	cin >> t;

	bfs(1);

	cout << visited[n] - 1;
}
