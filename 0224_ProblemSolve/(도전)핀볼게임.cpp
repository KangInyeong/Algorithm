///*
//N X N ũ�� ������ -> ���簢�� ���5, 4���� ���� �ﰢ�� ���1234, ��Ȧ678910, ��Ȧ-1
//�ɺ� �ϳ� -> �����¿� �� �� ����
//������ - ���� �ٲ� �ݴ� ����
//���� - ���� ���� �������� ����
//�� - �ݴ� ����
//��Ȧ - ������ ������ �ݴ��� ��Ȧ�� ������, ������� ����
//��Ȧ - ���� ����
//��� ��ġ - ����
//!! ���� !! �� OR ��� �ε��� Ƚ��
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
//	{1,3,0,2}, //1�� 
//	{3,0,1,2}, //2�� 
//	{2,0,3,1}, //3�� 
//	{1,2,3,0}, //4��
//	{1,0,4,3}  //5��
//};
//int redir[] = { 1,0,4,3 }; //�ݴ�
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
//		//��ĭ
//		if (MAP[ny][nx] == 0) {
//			if (ny == y && nx == x)
//				return score;
//		}
//		//��
//		else if (ny < 0 || nx < 0 || ny >= N || nx >= N) {
//			ndir = redir[dir];
//			score++;
//		}
//		//���
//		else if (MAP[ny][nx] >= 1 && MAP[ny][nx] <= 5) {
//			ndir = block[MAP[ny][nx]][dir];
//			score++;
//		}
//		//��Ȧ
//		else if (MAP[nx][ny] == -1) {
//			return score;
//		}
//		//��Ȧ
//		else {
//			bool shook = false;
//			//¦���Ȧã��
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
//				//�Ϲ������� �ƹ��͵� ���� ĭ�̸� �ϳ��� ������ �����ؼ� ����
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