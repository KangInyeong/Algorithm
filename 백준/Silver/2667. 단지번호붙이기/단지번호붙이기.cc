#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int MAP[26][26] = { 0, };
int visited[26][26] = { 0, };
int num = 0;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 }; 
vector<int> result;

int dfs(int y, int x) {

    int cnt = 1;
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 <= ny && ny < n && 0 <= nx && nx < n) {
            if (visited[ny][nx] != 1 && MAP[ny][nx] == 1) {
                int tmp = dfs(ny, nx);
                cnt += tmp;
            }
        }
    }

    return cnt;
}

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char input;
            cin >> input;
            MAP[i][j] = input - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (MAP[i][j] == 1 && visited[i][j] == 0) {
                // 집이 있는 곳 && 방문한적이 없는 곳
                int counting = dfs(i, j);
                result.push_back(counting);
            }
        }
    }

    sort(result.begin(), result.end());
    int result_cnt = result.size();
    cout << result_cnt << endl;
    for (int i = 0; i < result_cnt; i++) {
        cout << result[i] << endl;
    }

    return 0;

}