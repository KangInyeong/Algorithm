#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int y;
    int x;
};

int m, n;
int MAP[1001][1001] = { 0, };

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
queue<Node>q;

void bfs() {

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
            if (MAP[ny][nx] == 0) {

                MAP[ny][nx] = MAP[now.y][now.x] + 1;
                q.push({ ny, nx });

            }
        }
    }

}

int main() {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> MAP[i][j]; 
            if (MAP[i][j] == 1) {
                q.push({ i, j });
            }
        }
    }

    bfs();

    int numOfDay = -1;
    int flag = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (MAP[i][j] > numOfDay) {
                numOfDay = MAP[i][j];
            }

            if (MAP[i][j] == 0) {
                flag = 1;
                cout << -1;
                return 0;
            }
        }
        if (flag == 1) break;
    }

    cout << numOfDay - 1;

    return 0;
}