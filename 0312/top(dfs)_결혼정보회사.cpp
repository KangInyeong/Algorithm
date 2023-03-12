#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, t;
vector<int>v[101];
int visited[101];
int co, partner;
bool flag = false;

void dfs(int now) {
	
	if (now == partner) {
		flag = true;
		return;
	}

	for (int i = 0; i < v[now].size(); i++) {
		int to = v[now][i];

		if (visited[to])
			continue;

		visited[to] = 1;
		dfs(to);
	}

}


int main() {
	cin >> n >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cin >> co >> partner;

	dfs(co);
	if (flag == true)
		cout << "YES";
	else
		cout << "NO";
}
