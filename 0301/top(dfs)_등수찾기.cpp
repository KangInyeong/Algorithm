#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int n, m, x;
vector<int>pre[100000];
vector<int>post[100000];
int precnt , postcnt ;
int used[100000];

void predfs(int now) {

	if (used[now] == 1)
		return;

	used[now] = 1;
	precnt++;

	for (int next : pre[now]) {

		predfs(next);
	}
}

void postdfs(int now) {
	
	if (used[now] == 1)
		return;

	used[now] = 1;
	postcnt++;

	for (int next : post[now]){
		postdfs(next);
	}
}

int main() {
	cin >> n >> m >> x;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		pre[a].push_back(b);
		post[b].push_back(a);
	}

	predfs(x);
	memset(used, 0, sizeof(used));
	postdfs(x);
	cout << postcnt << '\n' << n - precnt +1;
	
}
