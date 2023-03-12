#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Node {
    int to;
    int cost;
};

int n, a, b;
int visited[100001];
vector<Node> v[100001];
int min_fee = 21e8;
int max_dist = -21e8;
int sum;

void dfs(int now) {
    if (now == b) {
        min_fee = sum - max_dist;
        return;
    }

    for (int i = 0; i < v[now].size(); i++) {
        int next = v[now][i].to;
        int cost = v[now][i].cost;

        if (visited[next])
            continue;

        // 두 로봇이 만나게 하기 위한 비용은 sum으로 계산 됨.
        // 그런데 그 두 로봇이 하나의 통로를 두고서 앞 뒤로 서있을 때에 비용을 최소로 하려면
        // 가장 비싼 거리인 통로를 지나지 않은 채 서있으면 됨.
        int tmp = max_dist; 
        sum += cost;
        visited[next] = 1;
        if (cost > max_dist)
            max_dist = cost;

        dfs(next);

        max_dist = tmp; //최대값 복구 주의
        sum -= cost;
        visited[next] = 0;
    }
}

int main() {
    cin >> n >> a >> b;

    for (int i = 0; i < n - 1; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        v[l].push_back({ r, c });
        v[r].push_back({ l, c });
    }

    visited[a] = 1;
    dfs(a);

    if (min_fee == 21e8)
        cout << 0;
    else cout << min_fee;

}
