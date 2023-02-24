/*
���� �浹 �� ������ ���� �� �Ҹ�
���� ���� ��ġ -> [x, y]
���� �̵� ���� -> �����¿� 
�� �� �̻��� ���ڰ� ���ÿ� �浹 �� ��� �浹�� ���ڵ��� ��� ������ �������� �����ϰ� �Ҹ�

�����̵�
���� ��� 1�̵� -> ������ 1�Ҹ�
���1)
���� �ٸ� ���ڸ� ������
	 ������ �������� ����
���2)
�ƹ��͵� ������ ������ ������ �����ϰ� �ش� ���� �״�� ť�� �ٽ� ����

MAP�� ũ��!? -1000���� 1000�� ��ġ�� ���� �� �ִµ� ���� MAP�� DATó�� ����Ϸ��� ��� �ε����� ����������ұ�...
*/

#include <iostream>
#include <queue>
using namespace std;

struct Atom {
	int y;
	int x;
	int direction;
	int energy;
};

int N;
int MAP[10000][10000];
int ydir[] = { -1,1,0,0 };
int xdir[] = { 0,0,-1,1 };

queue<Atom>atoms;

int main() {

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		cin >> N;
		int x, y, d, k;
		int totalEnergy = 0;
		for (int i = 0; i < N; i++) {
			cin >> x >> y >> d >> k;
			atoms.push({ y,x,d,k});
			//MAP[y+2000][x+2000] = k;
		}

		while (!atoms.empty()) {
			Atom atom = atoms.front();
			atoms.pop();

			//�̹� �Ҹ�� ���̶� �ʿ� ����
			if (MAP[atom.y][atom.x] == 0)
				continue;

			//�������� 1�� �ֵ��� �׳� �Ҹ�
			if (atom.energy == 1)
				MAP[atom.y][atom.x] = 0;

			int ny = atom.y + ydir[atom.y];
			int nx = atom.x + xdir[atom.x];

			if (MAP[ny][nx] != 0) {
				//�ٸ� ���ڸ� ����
				//���� ���� ������ & �ٸ� ���� ������ �ջ�
				totalEnergy += atom.energy;
				totalEnergy += MAP[ny][nx];
				//�� ������ ���� map & �̵��� ���� ������ ���ֱ�
				MAP[atom.y][atom.x] = 0;
				MAP[ny][nx] = 0;
			}
			else {
				//���ͳ����� �̵��� �ڸ� ����ϰ� �׳� �ٽ� �־��ֱ�
				if (atom.energy != 1) {
					MAP[ny][nx] = atom.energy - 1;
					MAP[y][x] = 0;
					atom.energy--;
					atoms.push(atom);
				}
			}

		}

		cout << "#" << tc << " " << totalEnergy << '\n';
	}
}