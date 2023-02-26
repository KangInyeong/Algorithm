#include <iostream>
#include<string.h>    // 배열 초기화를 위한 string.h 필요
using namespace std;

int n, k;
int arr[11][11];
int visited[11];

void preorder(int now) {
    visited[now] = 1;
    // node 들어가면서 출력
    cout << now << " ";              
    for (int i = n; i >= 1; i--) {
        // 방문한  node는 pass
        if (visited[i] == 1)
            continue;
        // 갈 수 없는 node는 pass
        if (arr[now][i] == 0) 
            continue;
        preorder(i);
    }
}

void postorder(int now) {
    visited[now] = 1;
    for (int i = n; i >= 1; i--) {
        // 방문한  node는 pass
        if (visited[i] == 1) 
            continue;  
        // 갈 수 없는 node는 pass
        if (arr[now][i] == 0) continue; 
        postorder(i);                
    }
        // node 나오면서 출력
    cout << now << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // input
    cin >> n >> k;
    int start;
    cin >> start;
    // 인접행렬
    for (int i = 0; i < k; i++) {
        int from, to;
        cin >> from >> to;
        arr[from][to] = 1;                
    }
    preorder(start);
    // visited 초기화
    memset(visited, 0, sizeof(visited)); 
    cout << '\n';
    postorder(start);
}
