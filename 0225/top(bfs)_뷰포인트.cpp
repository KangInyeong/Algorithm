/*
코딩던전과 유사한 문제. 
energy를 dist 배열에 0부터 추가하는 방식으로도 생각해 볼 수 있음.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct point {
	int to;
	int energy;
};

int n, m, k;
vector<point> v[100000];
int cnt;
queue<point>q;
int dist[100000];
int visited[100000] = { 0, };

void bfs(int start) {
	q.push({start,k});

	
	visited[start];
	dist[start] = 0;

	while (!q.empty()) {
		point now = q.front();
		q.pop();

		for (int i= 0; i < v[now.to].size(); i++) {

			if (visited[v[now.to][i].to] == 1)
				continue;
			if (now.energy - v[now.to][i].energy < 0)
				continue;
			cnt++;
			
			visited[v[now.to][i].to] = 1;
			q.push({ v[now.to][i].to ,now.energy - v[now.to][i].energy});
		}


	}

}

int main() {
	cin >> n >> m >> k;
	int from, to, power;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> power;
		v[from].push_back({ to,power });
	}
	visited[1] = 1;
	bfs(1);
	cout << cnt;
}
