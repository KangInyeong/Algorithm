#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int>v[100001];
queue<int>q;
int people;
int num;

void bfs(int start) {
	q.push(start);

	int visited[100001] = { 0, };
	visited[start] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			if (visited[v[now][i]] == 1)
				continue;
			people++;
			visited[v[now][i]] = 1;
			q.push(v[now][i]);
		}
	}
}
int main() {

	cin >> n >> m;

	int from, to;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from); //양방향연결 주
	}

	cin >> num;

	bfs(num);
	cout << people;

}
