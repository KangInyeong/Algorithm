#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct Node {
	int y;
	int x;
};
struct Edge {
	int a;
	int b;
	int cost;
};

int n, k;
int parents[2001];
vector<Node> vec;
vector<Edge>v;

bool cmp(Edge left, Edge right) {
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

	sort(v.begin(), v.end(), cmp);
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		Edge now = v[i];

		if (Find(now.a) == Find(now.b))
			continue;

		if (v[i].cost < k)
			continue;

		sum += v[i].cost;
		cnt++;
		Union(now.a, now.b);
	}

  //완벽한 mst가 되지 않는 
	if (cnt == n - 1)
		return sum;
	return -1;
}

int getCost(Node a, Node b) {
	int cost = pow((a.x - b.x), 2) + pow((a.y - b.y),2);
	return cost;
}

int main() {
	cin >> n >> k;
	int y, x;
	for (int i = 0; i < n; i++) {
		cin >> y >> x;
		vec.push_back({ y,x });
	}
  //지역 짝 지어서 관개 공사 진행 시 비용 산출
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			v.push_back({i, j, getCost(vec[i], vec[j])});
		}
	}

	for (int i = 0; i < n; i++) {
		parents[i] = i;
	}

	cout << kruskal();
}
