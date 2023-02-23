#include <iostream>
using namespace std;

int vect[5];
int cnt;

void run(int level, int sum)
{
	if (level == 5) {
		if (sum >= 10 && sum <= 20) {
			cnt++;
		}
		return;
	}

	run(level + 1, sum + vect[level]);
	run(level + 1, sum + 0);
}

int main()
{
	for (int i = 0; i < 5; i++) {
		cin >> vect[i];
	}

	run(0, 0);

	cout << cnt;

	return 0;
}