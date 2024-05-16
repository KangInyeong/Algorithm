#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr[1001][1001] = { 0, };
int visited[1001] = { 0, };

void dfs(int start) {

    cout << start << ' ';

    for (int i = 1; i < 1001; i++) {
        if (arr[start][i] == 1 && visited[i] == 0) {
            visited[i] = 1;
            dfs(i);
        }
    }

}

void bfs(int start) {
    queue<int>q;

    q.push(start);
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << ' ';
        
        for (int i = 1; i < 1001; i++) {
            if (arr[now][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }

}
int main() {
    
    //정점, 간선, 시작노드
    int n, m, v;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    visited[v] = 1;
    dfs(v);
    memset(visited, 0, sizeof(visited));
    cout << endl;
    visited[v] = 1;
    bfs(v);


    return 0;
}
