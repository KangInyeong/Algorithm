// 손님 도착지 데려다 주면 연료 충전, 연료 바닥나면 업무 끝
// M명의 승객 태우기 N X N 격자 택시 상하좌우 이동 최단거리
// 한 승객을 태워 목적지로 이동시키는 일을 M번 반복
//승객 : 스스로 이동X 출발지에서만 택시 탑승 가능 목적지에서만 택시 하차 가능
//태울 승객 -> 현재 위치에서 최단거리가 가장 짧은 승객 (행번호-열번호)
//택시와 승객이 같은 위치 = 승객까지의 최단거리 0
// 승객 목적지 이동 완료 -> 소모한 연료 양의 두 배 충전
// 연료가 바닥나면 이동 실패 & 업무 종료 (동시에 소진 시 성공으로 간주)

//1. 택시와 각 승객 사이의 거리 중 최단 거리 승객 찾기
//2. 승객을 목적지로 이동
//3. 소진연료x2의 연료 채우기
//4. 다시  1번부터 시작

// 손님 도착지 데려다 주면 연료 충전, 연료 바닥나면 업무 끝
// M명의 승객 태우기 N X N 격자 택시 상하좌우 이동 최단거리
// 한 승객을 태워 목적지로 이동시키는 일을 M번 반복
//승객 : 스스로 이동X 출발지에서만 택시 탑승 가능 목적지에서만 택시 하차 가능
//태울 승객 -> 현재 위치에서 최단거리가 가장 짧은 승객 (행번호-열번호)
//택시와 승객이 같은 위치 = 승객까지의 최단거리 0
// 승객 목적지 이동 완료 -> 소모한 연료 양의 두 배 충전
// 연료가 바닥나면 이동 실패 & 업무 종료 (동시에 소진 시 성공으로 간주)

//1. 택시와 각 승객 사이의 거리 중 최단 거리 승객 찾기
//2. 승객을 목적지로 이동
//3. 소진연료x2의 연료 채우기
//4. 다시  1번부터 시작

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N, M, F;
int MAP[21][21];
int sr, sc;
struct passenger {
	int sy;
	int sx;
	int dy;
	int dx;
};
struct Block {
	int y;
	int x;
};
vector<passenger>v;
int finishedPassen[401];

int visited[21][21];
int diry[4] = { 0,0,-1,1 };
int dirx[4] = { -1,1,0,0 };
void makeVisited() {

	queue<Block>q;
	q.push({ sr, sc });
	visited[sr][sc] = 1;
	while (!q.empty()) {
		Block now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + diry[i];
			int nx = now.x + dirx[i];

			if (MAP[ny][nx] == 1)
				continue;
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;

			if (visited[ny][nx] != 0)
				continue;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny, nx });
		}
	}

}

void findPath(int sy, int sx) {

	queue<Block>q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	while (!q.empty()) {
		Block now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + diry[i];
			int nx = now.x + dirx[i];

			if (MAP[ny][nx] == 1)
				continue;
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (visited[ny][nx] != 0)
				continue;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny, nx });
		}
	}

}

int main() {
	cin >> N >> M >> F;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
	int a, b;
	cin >> a >> b;
	sr = a - 1;
	sc = b - 1;
	for (int i = 0; i < M; i++) {
		int sy, sx, dy, dx;
		cin >> sy >> sx >> dy >> dx;
		v.push_back({ sy - 1, sx - 1, dy - 1, dx - 1 });
	}
	for (int t = 0; t < M; t++) {
		memset(visited, 0, sizeof(visited));
		//1. 승객과 택시의 거리 구하기
		makeVisited();
		int shortDis = 1000;
		int shortPassen;

		if (!v.empty()) {
			for (int i = 0; i < v.size(); i++) {
				int flag = 0;
				for (int j = 0; j < t; j++) {
					if (finishedPassen[j] - 1 == i) {
						flag = 1;
						break;
					}
				}

				if (flag == 1)
					continue;

				int distance = visited[v[i].sy][v[i].sx];
				if (distance == 0)
					continue;
				if (shortDis > distance) {
					shortDis = distance;
					shortPassen = i;
				}
				else if (shortDis == distance) {
					if (v[shortPassen].sy > v[i].sy)
						shortPassen = i;
					else if (v[shortPassen].sy == v[i].sy && v[shortPassen].sx > v[i].sx)
						shortPassen = i;
				}
			}
		}
		
		if (shortDis == 1000)
		{
			cout << -1;
			return 0;
		}

		memset(visited, 0, sizeof(visited));
		F -= (shortDis - 1);

		//2. 승객을 목적지로 이동
		passenger p = v[shortPassen];
		findPath(p.sy, p.sx);
		if (visited[p.dy][p.dx] == 0)
		{
			cout << -1;
			return 0;
		}
		int needFuel = visited[p.dy][p.dx] - 1;
		
		if (needFuel <= F) {
			F -= needFuel;
			F += (needFuel * 2);
			finishedPassen[t] = shortPassen + 1;
			sr = p.dy;
			sc = p.dx;
		}
		else {
			cout << -1;
			return 0;
		}

	}

	if (finishedPassen[0] == 0)
		cout << -1;
	else
		cout << F;

	return 0;

}
