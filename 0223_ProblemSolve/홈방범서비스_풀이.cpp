//�ٽ� ����!
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N;//������ ũ��
int M;//�� �ϳ��� ������ ���
int MAP[20][20];//����
//����迭
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 0 };

struct Node {
	int y;
	int x;
};

int calculate(int servicearea, int homecnt) {
	//1. ����
	int K = servicearea;
	int expense = K * K + (K - 1) * (K - 1);

	//2. ���� = ���� ���� * �� �� �ִ� ��
	int income = homecnt * M;

	//3. ���� = ���� - ����
	return income - expense;
}


int bfs(int y, int x) {
	//queue ����
	queue<Node>q;
	q.push({ y,x });
	//visited ����
	int visited[20][20] = { 0, };
	visited[y][x] = 1;

	//���� ���� ����
	//���� �ִ� ��ġ�� �̹� ���񽺸� ����
	int K = 1;

	int cnt = 0;//���� ����

	int temp = 0;//�߰� ���� -> ���� ���� (y,x)���� ���񽺸� �������� ��, ���� ó���� ������ �� �ִ� ���� �� 

	//���� ���� ���� ���񽺸� �����ϴ� ��ġ�� ���̶��, ī��Ʈ ����
	if (MAP[y][x] == 1)
		cnt++;

	//ff�ڵ�
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			//����迭 ��� �ÿ� ������ üũ�ؾ��ϴ� ����
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (visited[ny][nx] == 1)
				continue;
			//���� ���� ��ġ�� ���̶��
			if (MAP[ny][nx] == 1)
				cnt++;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}

		//�ϳ��� �ܰ��� ���񽺰� ����Ǿ��� ��,
		//(1) ���ظ� ���� �ʾҴ°� 
		//(2) �� ���� ���� ó���� �� �־��°�
		if (calculate(K, cnt) >= 0) {
			if (cnt > temp)
				temp = cnt;
		}
	}

	//���� �� (y,x)��ġ���� ���� ���� ó���� ������ ���� �� ����
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
		//���� ���� �Է�
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> MAP[i][j];

		//solve ->��� ��ġ���� �׳� �ϴ� �÷����� ������
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				int temp = bfs(i, j);
				//���� ���� ����
				if (ans < temp)
					ans = temp;
			}
		}

		//outout
		cout << "#" << tc << " " << ans << '\n';
	}
}