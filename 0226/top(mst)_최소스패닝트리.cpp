
/*
1. Edge(a,b,cost)를 가지는 vector 입력 받기
2. parent배열 초기화 후에 kruskal 작동
3. kruskal -> 정렬 후에 v.size()만큼 for문 돌리면서 Find가 동일하면 지나치지만 아니라면 sum 추가하고 Union 시킴
4. Find와 Union함수 정의
5. sort에 들어가는 cmp 함수도 vector 이므로 정의
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int a;
	int b;
	int cost;
};

bool cmp(Node left, Node right) {
	if (left.cost < right.cost)
		return true;
	if (left.cost > right.cost)
		return false;
	return false;
}

int v, e;
vector<Node>vec;
int parent[10000];

int Find(int now) {
	if (now == parent[now])
		return now;
	return parent[now] = Find(parent[now]);
}

void Union(int a, int b) {
	int pa = parent[a];
	int pb = parent[b];

	if (pa == pb)
		return;

	parent[pb] = pa;
}

int kruskal() {

	sort(vec.begin(), vec.end(),cmp);

	int sum = 0;

	for (int i = 0; i < vec.size(); i++) {
		Node now = vec[i];
		if (Find(now.a) == Find(now.b))
			continue;

		sum += now.cost;

		Union(now.a, now.b);
	}
	return sum;
}
int main() {
	cin >> v >> e;
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		vec.push_back({ a,b,c });
	}

	for (int i = 0; i < v; i++) {
		parent[i] = i;
	}

	cout << kruskal();
}
