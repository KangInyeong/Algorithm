#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int to;
    int cost;
};

int n, m, k;

vector<Node> v[10];
vector<int> ans;

void bfs(int start) {

    queue<Node>q;
    q.push({ start ,k});

    int visited[10] = { 0, };
    visited[start] = 1;

    while (!q.empty()) {
        Node now = q.front(); 
        q.pop();
        int power = now.cost;

        //cout << now.to << " ";

        for (int i = 0; i < v[now.to].size(); i++) {

            if (power - v[now.to][i].cost < 0)
                continue;

            if (visited[v[now.to][i].to] == 1)
                continue;

            ans.push_back(v[now.to][i].to);

            q.push({ v[now.to][i].to,power - v[now.to][i].cost });
            
            visited[v[now.to][i].to] = 1;
        }
    }
}

int main() {

	cin >> n >> m >> k;
    int from, to, cost;
	for (int i = 0; i < m; i++) {
        cin >> from >> to >> cost;
        v[from].push_back({to, cost});
	}

	bfs(0);

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
 
}
