//�ٽ� ����!
#include <iostream>
#include <queue>
using namespace std;

int N; //���� ũ��
int M; //���� ũ��
int R; //��Ȧ�� ���� ��ġ(y)
int C; //��Ȧ�� ���� ��ġ
int L; //�ҿ�ð�
int MAP[50][50];

int pipedir[][4] = {
	//�����¿�
	//�� �� ������ 1, �ƴϸ� 0
	{0,0,0,0},
	{1,1,1,1},
	{1,1,0,0},
	{0,0,1,1},
	{1,0,0,1},
	{0,1,0,1},
	{0,1,1,0},
	{1,0,1,0}
};

struct Node {
	int y;
	int x;
};
// 1. ������ flood fill
// 2. �߰��ؾ� �Ǵ� ����
	//1) ������ -> ���� ���� ���������� ���� �������� �� �� �ִ°�
	//2) L��ŭ�� �ð����� ������ -> �ܰ躰 flood fill

int bfs(int y, int x) {
	queue<Node>q;
	q.push({ y,x });

	//visited�غ�
	int visited[50][50] = { 0, };
	visited[y][x] = 1;

	//���� �迭
	int ydir[] = {-1,1,0,0};
	int xdir[] = {0,0,-1,1};

	int time = 0;
	int cnt = 0; //���� �湮�� �������� ����

	while (!q.empty()) {
		//��� ���� ���� L�� �ð� ��ŭ ���� ���� ���ϱ� �� ���� ����
		if (time == L)
			break;

		//���� ���ƿ���, �ϳ��� �ܰ谡 �Ϸ�Ǿ� 1�ð��� ������ ����
		time++;

		//�ϴ�, �ܰ躰�� ���� queue�� ��� �ִ� ��ŭ�� ���ư����� ����
		int cursize = q.size();
		for (int j = 0; j < cursize; j++) {
			
			//now : ���� ���� ������ ������
			// now ���� ���� �� �� �ִ� ������
			// now�� ���Դٴ� �� = ���� �� �� �ִ� �������� �ϳ� �þ���!
			Node now = q.front();
			q.pop();
			
			cnt++;

			for (int i = 0; i < 4; i++) {
				int ny = now.y + ydir[i];
				int nx = now.x + xdir[i];

				if (ny < 0 || nx < 0 || ny >= N || nx >= M)
					continue;
				if (visited[ny][nx] == 1)
					continue;

				//�� �� �ִ��� �Ǵ�
				//#1. ���� �� �������� i�� �������� �� �� �ִ°�?
				int curpipe = MAP[now.y][now.x]; //���� �� ������ ��ȣ
				//���� ���� �� ���������� i��° �������� �����ٸ� ������
				if (pipedir[curpipe][i] == 0)
					continue;
				//#2. ���̸� �� ��
				if (MAP[ny][nx] == 0)
					continue;
				//#3. ���� ���� (ny,nx) �������� �����µ� ������� �Դٴ� �� ���� ĭ�� ���� �ƴ� ����.
				//   ���� ���� �� �������� �� �� �����ٵ� ���ϴ� ���⿡�� ���� ��, �� �� �ִ°�?
				int nextpipe = MAP[ny][nx];
				//���� �������� ���� ���������� ���� ������ �ݴ� ������ �շ��ִ°�?
				//���� ���� ���� i������ �ݴ� ������ Ȯ��
				int nextdir = -1;
				if (i % 2 == 0)
					nextdir = i + 1;
				else
					nextdir = i - 1;
				if (pipedir[nextdir][nextdir] == 0)
					continue;

				visited[ny][nx] = 1;
				q.push({ ny,nx });
			}

		}
	}
	return cnt;
}

int main() {

	int T;
	for (int tc = 0; tc <= T; tc++) {

		//reset
		memset(MAP, 0, sizeof(MAP));

		//input
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> MAP[i][j];
			}
		}

		//solve
		int ans = bfs(R, C);

		//output
		cout << "#" << tc << " " << ans << '\n';

	}
}