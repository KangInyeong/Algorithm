//다시 보자!
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N;//도시의 크기
int M;//집 하나가 지불할 비용
int MAP[20][20];//도시
//방향배열
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 0 };

struct Node {
	int y;
	int x;
};

int calculate(int servicearea, int homecnt) {
	//1. 지출
	int K = servicearea;
	int expense = K * K + (K - 1) * (K - 1);

	//2. 매출 = 집의 개수 * 집 당 주는 값
	int income = homecnt * M;

	//3. 수익 = 매출 - 지출
	return income - expense;
}


int bfs(int y, int x) {
	//queue 세팅
	queue<Node>q;
	q.push({ y,x });
	//visited 세팅
	int visited[20][20] = { 0, };
	visited[y][x] = 1;

	//현재 서비스 영역
	//지금 있는 위치는 이미 서비스를 개시
	int K = 1;

	int cnt = 0;//집의 개수

	int temp = 0;//중간 정답 -> 내가 지금 (y,x)에서 서비스를 시작했을 때, 가장 처리를 많이할 수 있는 집의 수 

	//만약 내가 지금 서비스를 시작하는 위치가 집이라면, 카운트 증가
	if (MAP[y][x] == 1)
		cnt++;

	//ff코드
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			//방향배열 사용 시에 무조건 체크해야하는 범위
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (visited[ny][nx] == 1)
				continue;
			//만약 다음 위치가 집이라면
			if (MAP[ny][nx] == 1)
				cnt++;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}

		//하나의 단계적 서비스가 종료되었을 때,
		//(1) 손해를 보지 않았는가 
		//(2) 더 많은 집을 처리할 수 있었는가
		if (calculate(K, cnt) >= 0) {
			if (cnt > temp)
				temp = cnt;
		}
	}

	//지금 이 (y,x)위치에서 가장 많이 처리가 가능한 집의 수 리턴
	return temp;
}
int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		//reset
		memset(MAP, 0, sizeof(MAP));
		int ans = -1;

		//input
		cin >> N >> M;
		//도시 정보 입력
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> MAP[i][j];

		//solve ->모든 위치에서 그냥 일단 플러드필 돌리기
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				int temp = bfs(i, j);
				//최종 정답 갱신
				if (ans < temp)
					ans = temp;
			}
		}

		//outout
		cout << "#" << tc << " " << ans << '\n';
	}
}