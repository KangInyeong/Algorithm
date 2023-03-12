#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, x;
vector<int>pre[100001];
vector<int>post[100001];
int visited[100001];
int precnt, postcnt;

void predfs(int now) {

	for (int i = 0; i < pre[now].size(); i++) {
		int to = pre[now][i];

		if (visited[to])
			continue;

		precnt++;
		visited[to] = 1;
		predfs(to);

	}
}

void postdfs(int now) {

	for (int i = 0; i < post[now].size(); i++) {
		int to = post[now][i];

		if (visited[to])
			continue;

		postcnt++;
		visited[to] = 1;
		postdfs(to);

	}
}

int main() {
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		pre[a].push_back(b);
		post[b].push_back(a);
	}

	predfs(x);
	memset(visited, 0, sizeof(visited));
	postdfs(x);

	cout << postcnt + 1 << ' ' << n - precnt;
}
