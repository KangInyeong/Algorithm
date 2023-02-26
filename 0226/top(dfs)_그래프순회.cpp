#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int mat[100][100];
vector<int>v[100];

int visited[100]; 

bool cmp(int left, int right) {
	if (left > right)
		return true;
	if (left < right)
		return false;
	return false;
}

void dfs(int now) {

	cout << now << ' ';
	
	sort(v[now].begin(), v[now].end(),cmp); //굳이 정렬방식이 아니라 타이밍에 맞는 출력으로 충분히 구현 가능.

	for (int i = 0; i < v[now].size(); i++) {
		if (visited[v[now][i]] == 1)
			continue;
		visited[v[now][i]] = 1;
		dfs(v[now][i]);
	}
}
int checked[100]; //이전 visited를 memset으로 초기화해서 사용할 수 있을 것

void post(int now) {

	if (v[now].size() == 0)
		return;
	sort(v[now].begin(), v[now].end(),cmp);

	for (int i = 0; i < v[now].size(); i++) {
		if (checked[v[now][i]] == 1)
			continue;
		checked[v[now][i]] = 1;
		post(v[now][i]);
		cout << v[now][i] << ' ';
	}
}

int main() {
	cin >> n >> m;
	int num;
	cin >> num;
	int from, to;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		mat[from][to] = 1;
		v[from].push_back(to);
	}

	visited[num] = 1;
	checked[num] = 1;

	dfs(num);
	cout << endl;
	post(num);
	cout << num;

}
