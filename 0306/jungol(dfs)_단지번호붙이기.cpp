/*bfs -> floodfill로 */
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
	int y;
	int x;
};
int n;
string MAP[26];
queue<Node> q;
int visited[26][26];
int cnt;
int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };
priority_queue<int, vector<int>, greater<int>>pq;

void bfs(int y, int x) {
	q.push({ y, x });
	visited[y][x] = cnt;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + diry[i];
			int nx = now.x + dirx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;

			if (visited[ny][nx] != 0)
				continue;

			if (MAP[ny][nx] == '0')
				continue;

			visited[ny][nx] = cnt;
			q.push({ ny, nx });
		}
	}
}

int DAT[100];
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> MAP[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (MAP[i][j] == '1' && visited[i][j]==0) {
				cnt++;
				bfs(i, j);
			}				
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			DAT[visited[i][j]]++;
		}
	}

	cout << cnt << '\n';
	for (int i = 0; i < 100; i++) {
		if (DAT[i] != 0 && i !=0) 
			pq.push(DAT[i]);
	}
	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();
		cout << now << '\n';
	}
}
