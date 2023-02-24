///*
//N X N 크기 게임판 -> 정사각형 블록5, 4가지 형태 삼각형 블록1234, 웜홀678910, 블랙홀-1
//핀볼 하나 -> 상하좌우 중 한 방향
//수직면 - 방향 바꿔 반대 방향
//경사면 - 진행 방향 직각으로 꺾임
//벽 - 반대 방향
//웜홀 - 동일한 숫자의 반대편 웜홀로 나오며, 진행방향 유지
//블랙홀 - 게임 종료
//출발 위치 - 종료
//!! 점수 !! 벽 OR 블록 부딪힌 횟수
//
//*/
//
//#include <iostream>
//using namespace std;
//
//int N;
//int MAP[100][100];
//
//int ydir[] = { -1,1,0,0 };
//int xdir[] = { 0,0,-1,1 };
//int block[6][4] = {
//	{0,0,0,0},
//	{1,3,0,2}, //1번 
//	{3,0,1,2}, //2번 
//	{2,0,3,1}, //3번 
//	{1,2,3,0}, //4번
//	{1,0,4,3}  //5번
//};
//int redir[] = { 1,0,4,3 }; //반대
//
//int result;
//int visited[100][100];
//
//int go(int y, int x, int dir) {
//	int score = 0;
//
//	int ny, nx, ndir;
//
//	while (true) {
//		ny = y + ydir[dir];
//		nx = x + xdir[dir];
//
//		//빈칸
//		if (MAP[ny][nx] == 0) {
//			if (ny == y && nx == x)
//				return score;
//		}
//		//벽
//		else if (ny < 0 || nx < 0 || ny >= N || nx >= N) {
//			ndir = redir[dir];
//			score++;
//		}
//		//블록
//		else if (MAP[ny][nx] >= 1 && MAP[ny][nx] <= 5) {
//			ndir = block[MAP[ny][nx]][dir];
//			score++;
//		}
//		//블랙홀
//		else if (MAP[nx][ny] == -1) {
//			return score;
//		}
//		//웜홀
//		else {
//			bool shook = false;
//			//짝꿍웜홀찾기
//			for (int i = 0; i < N; i++) {
//				for (int j = 0; j < N; j++) {
//					if ((MAP[i][j] == MAP[ny][nx]) && !(nx == i && ny == j)) {
//						nx = i, ny = j;
//						shook = true;
//						break;
//					}
//				}
//				if (shook) {
//					break;
//				}
//			}
//		}
//
//	}
//
//
//}
//
//int main() {
//	int T;
//	cin >> T;
//
//	for (int tc = 1; tc <= T; tc++) {
//
//		cin >> N;
//
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				cin >> MAP[i][j];
//			}
//		}
//
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				//일반적으로 아무것도 없는 칸이면 하나의 방향을 선택해서 직진
//				if (MAP[i][j] == 0) {
//					for (int d = 0; d < 4; d++) {
//						if (go(i, j, d) > result) {
//							result = go(i, j, d);
//						}
//					}
//				}
//					
//			}
//		}
//
//		cout << "#" << tc << " " << result << '\n';
//	}
//
//}