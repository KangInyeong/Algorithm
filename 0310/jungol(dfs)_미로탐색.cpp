#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v[100001];//크기 주의
int used[100001];
vector<int>path;

void dfs(int now) {
	if (path.size() == n) { //조건 주의
		//sort(path.begin(), path.end());
		for (int i = 0; i < path.size(); i++)
			cout << path[i] << " ";
		return;
	}
	
	sort(v[now].begin(), v[now].end());
	for (int i = 0; i < v[now].size(); i++) {
		int to = v[now][i];
		if (used[to] == 1) continue;

		//cout << now << "에서" << to << "로 갑니다\n";
		used[to] = 1;
		path.push_back(to);
		dfs(to);
	}
	
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	path.push_back(1);
	used[1] = 1;
	dfs(1);
}
