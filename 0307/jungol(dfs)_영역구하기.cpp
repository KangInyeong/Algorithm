/*
괜히 어렵게 푼 것 같다..!
dfs로는 어떻게 하는 것인지도 잘 모르겠는데 우선 flood fill 개념으로 풀었다.
항상 전체 데이터의 마지막 값을 잘 고려해야 한다. map, visited 크기 그리고 for문 종료 조건도 확인하자.
*/
#include <iostream>
#include <queue>
using namespace std;

int m, n, k;
int MAP[101][101];
struct Node {
	int y;
	int x;
};
queue<Node>q;

int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };
int visited[101][101];
int cnt;
int DAT[101];
priority_queue<int, vector<int>, greater<int>> pq;

void bfs(int y, int x) {
	q.push({ y,x });

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + diry[i];
			int nx = now.x + dirx[i];

			if (ny < 0 || nx < 0 || ny >= m || nx >= n)
				continue;

			if (visited[ny][nx] != 0)
				continue;

			if (MAP[ny][nx] == 1)
				continue;

			visited[ny][nx] = cnt;
			q.push({ ny, nx });
		}
	}
}

int main() {
	cin >> m >> n >> k;

	int ly, lx, ry, rx;
	for (int i = 0; i < k; i++) 
	{
		cin >> lx >> ly >> rx>> ry;
		for (int a = ly; a < ry; a++)
		{
			for (int b = lx; b < rx;b++) 
			{
				MAP[a][b] = 1;
			}
		}
	}

	for (int a = 0; a < m; a++)
	{
		for (int b = 0; b < n; b++)
		{
			if (MAP[a][b] == 0 && visited[a][b]==0) {
				cnt++;
				visited[a][b] = cnt;
				bfs(a,b);
			}
		}
	}

	for (int a = 0; a < m; a++)
	{
		for (int b = 0; b < n; b++)
		{
			DAT[visited[a][b]]++;
		}
	}

	cout << cnt << '\n';
	for (int a = 0; a < 101; a++)
	{
		if (a != 0 && DAT[a] > 0)
			pq.push(DAT[a]);
	}
	while(!pq.empty()){
		cout << pq.top() << ' ';
		pq.pop();
	}

}
