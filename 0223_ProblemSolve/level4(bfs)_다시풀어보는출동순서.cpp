#include <iostream>
#include <queue>
using namespace std;

int n;
char hero[4] = { 'B', 'I', 'A', 'H' };
queue<char> q;
int used[4];

int main() {
	cin >> n;

	int cnt = 0;
	int totalchk = 0;
	while (true) {
		for (int i = 0; i < 4; i++) {
			if (used[i] == 1)
				continue;
			cnt++;
			if (cnt == n) {
				cnt = 0;
				used[i] = 1;
				cout << hero[i] << " ";
				totalchk++;
			}
		}
		//�� ���Դٰ� �������� ���� while ����������!
		if (totalchk == 4) {
			return 0;
		}
	}

}