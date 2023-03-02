/*
priority_queue 비교 함수도 깔끔.
다익스트라 함수에서 return을 받아서 갱신
*/
#include <iostream>
#include <queue>
using namespace std;

int n, m, p; 

struct Edge {
    int num, cost;
};

bool operator < (Edge a, Edge b)  {
    return a.cost > b.cost;
}

vector<Edge>v[1001];

int dijkstra(int start, int dest) {
    priority_queue<Edge>pq; 
    pq.push({ start, 0 });
    int dist[1001];
    for (int i = 0; i <= n; i++)
        dist[i] = 2134567890;
    dist[start] = 0;
    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();
        for (int i = 0; i < v[now.num].size(); i++) {
            Edge next = v[now.num][i];
            if (dist[next.num] <= dist[now.num] + next.cost)
                continue;
            dist[next.num] = dist[now.num] + next.cost; 
            pq.push({ next.num, dist[next.num] });
        }
    }
    return dist[dest]; 
}

int main() {
    cin >> n >> m >> p;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({ to, cost });
    }
    int ans = -2134567890;
    for (int i = 1; i <= n; i++) {
        int a = dijkstra(i, p);
        int b = dijkstra(p, i); 
        if (a + b > ans)
            ans = a + b; 
    }
    cout << ans; 
}
