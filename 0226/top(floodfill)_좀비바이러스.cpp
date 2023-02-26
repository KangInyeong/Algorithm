#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
    int y;
    int x;
};

int w, h;
string map[100];
int ydir[4] = { -1,1,0,0 };
int xdir[4] = { 0,0,-1,1 };

int visited[100][100];
int difusion[100][100];

void bfs(int y, int x) {
    queue<Node>q;
    q.push({ y,x });
    visited[y][x] = 1;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            if (nx < 0 || ny < 0 || ny >= h || nx >= w)
                continue;

            if (visited[ny][nx] == 1 && difusion[ny][nx] > 0)
                continue;

            if (map[ny][nx] == '0')
                continue;

            visited[ny][nx] = 1;
            difusion[ny][nx] = difusion[now.y][now.x] + 1;
            q.push({ ny,nx });
        }
    }

    int zombie = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (map[i][j] == '1')
                zombie++;
        }
    }

    int hilled = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            hilled += visited[i][j];
        }
    }
    int maxtime = -21e8;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (maxtime < difusion[i][j]) {
                maxtime = difusion[i][j];
            }
            //cout << difusion[i][j];
        }//cout << endl;
    }

    cout << maxtime << endl;
    cout << zombie - hilled << endl;

}

int main() {
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        cin >> map[i];
    }

    int y, x;
    cin >> x >> y; //입력 순서 주의
    //시작좌표 (1,1)
    y--; 
    x--;
    difusion[y][x] = 3; //백신 치유에 3초가 걸림
    bfs(y, x);

}
