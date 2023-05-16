/***상어 중학교
N x N 격자 - 검은색(-1), 무지개(0), 일반(1~M)
블록그룹 == 연결된 블록의 집합(일반 블록 적어도 하나 & 동일 색상, 검은색블록 X, 무지개블록 가능)
기준 블록 -> 무지개블록 X. 행의 번호 가장 작고 열의 번호 작은 블록
1. 크기가 가장 큰 블록 그룹 찾기
	만약, 여러 개일 경우에는 무지개 블록 수가 가장 많은 그룹 -> 행 크고 열 큰 것
2. 1의 블록 그룹 제거 -> B^2점 획득
3. 중력(검은색 블록 제외한 모든 블록 행 번호가 큰 칸으로 이동) 작동
4. 90도 반시계 방향 회전
5. 중력
***/
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N, M;
int MAP[21][21];
int visited[21][21];
int maxMap[21][21];
int tmpMap[21][21];
struct Node {
	int y;
	int x;
};

int diry[4] = { -1,1,0,0 };
int dirx[4] = { 0,0,-1,1 };

int findGroup(int y, int x) {

	int visited[21][21] = {0,};
	//memset(visited, 0, sizeof(visited));

	int cnt = 0;
	queue<Node> q;
	Node first = { y, x };
	q.push(first);
	visited[y][x] = MAP[y][x];

	while (!q.empty()) {
		Node node = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {

			int ny = node.y + diry[i];
			int nx = node.x + dirx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (visited[ny][nx] != 0)
				continue;
			if (MAP[ny][nx] != 0 && MAP[ny][nx] != MAP[first.y][first.x])
				continue;
			q.push({ ny, nx });
			visited[ny][nx] = MAP[first.y][first.x];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//cout << visited[i][j] << ' ';
			if (visited[i][j] == visited[first.y][first.x])
				cnt++;
		}//cout << endl;
	}
	//cout << endl;

	memcpy(visited, tmpMap, sizeof(visited));
	return cnt;
}

void boomMaxGroup() {
	
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}

	int visited[21][21];
	//int m = 1;
	int maxCnt = -21e8;
	int maxNumy, maxNumx;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j] != 0 && MAP[i][j] != -1) {
				int m = MAP[i][j];
				
				int cnt = findGroup(i, j); 
				cout << endl;
				if (cnt > maxCnt) {
					maxCnt = cnt;
					maxNumy = i;
					maxNumx = j;
					memcpy(maxMap, tmpMap, sizeof(maxMap));
					for (int i = 0; i < N; i++) {
						for (int j = 0; j < N; j++) {
							cout << maxMap[i][j] << ' ';
						}cout << endl;
					}
				}
				cout << maxCnt << endl;
				
			}
		}
	}

}
