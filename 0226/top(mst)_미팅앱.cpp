#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct Node {
	int a;
	int b;
	bool ok;
	int cost;
};

int n, m;

char worm[1001];
int parents[2001];
vector<Node> vec;

bool cmp(Node left, Node right) {
	if (left.cost < right.cost)
		return true;
	if (left.cost > right.cost)
		return false;
	return false;
}

int Find(int now) {
	if (parents[now] == now)
		return now;
	return parents[now] = Find(parents[now]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb)
		return;

	parents[pb] = pa;
}

int kruskal() {

	sort(vec.begin(), vec.end(), cmp);
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < vec.size(); i++) {
		Node now = vec[i];

		if (now.ok == false)
			continue;

		if (Find(now.a) == Find(now.b))
			continue;

		sum += vec[i].cost;
		cnt++;
		Union(now.a, now.b);
	}

	if (cnt == n - 1)
		return sum;
	return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> worm[i];
	}
	int u,v,d;
	bool ok;
	for (int i = 0; i < m; i++) {
		cin >> u>>v>>d;
		if (worm[u] != worm[v])
			ok = true;
		else ok = false;
		vec.push_back({ u, v, ok, d});
	}

	for (int i = 0; i < n; i++) {
		parents[i] = i;
	}

	cout << kruskal();
}
