/*
원자 충돌 시 에너지 방출 후 소멸
원자 최초 위치 -> [x, y]
원자 이동 방향 -> 상하좌우 
두 개 이상의 원자가 동시에 충돌 할 경우 충돌한 원자들은 모두 보유한 에너지를 방출하고 소멸

원자이동
방향 대로 1이동 -> 에너지 1소모
경우1)
만약 다른 원자를 만나면
	 가지는 에너지를 방출
경우2)
아무것도 없으면 에너지 정보만 갱신하고 해당 방향 그대로 큐에 다시 넣음

MAP의 크기!? -1000부터 1000의 위치가 들어올 수 있는데 과연 MAP을 DAT처럼 사용하려면 어떻게 인덱스를 변경해줘야할까...
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

			//이미 소멸된 아이라서 맵에 없음
			if (MAP[atom.y][atom.x] == 0)
				continue;

			//에너지가 1인 애들은 그냥 소멸
			if (atom.energy == 1)
				MAP[atom.y][atom.x] = 0;

			int ny = atom.y + ydir[atom.y];
			int nx = atom.x + xdir[atom.x];

			if (MAP[ny][nx] != 0) {
				//다른 원자를 만났
				//현재 원자 에너지 & 다른 원자 에너지 합산
				totalEnergy += atom.energy;
				totalEnergy += MAP[ny][nx];
				//현 원자의 원래 map & 이동한 곳의 에너지 없애기
				MAP[atom.y][atom.x] = 0;
				MAP[ny][nx] = 0;
			}
			else {
				//안터녔으니 이동한 자리 기록하고 그냥 다시 넣어주기
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