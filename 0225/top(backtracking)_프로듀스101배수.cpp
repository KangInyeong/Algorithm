#include <iostream>
using namespace std;

int n;
int num[100];
char sign[3] = {'*', '+', '-'};
char path[100];

void calc(char path[100]) {
	int result = num[0];
	for (int i = 1; i < n; i++) {
		if (path[i-1] == '*') {
			result *= num[i];
		}
		else if (path[i - 1] == '-') {
			result -= num[i];
		}
		else if (path[i - 1] == '+') {
			result += num[i];
		}
	}

	if (result % 101 == 0 && result != 0) {
		cout << num[0];
		for (int i = 1; i < n; i++) {
			cout << path[i - 1] << num[i];
		}cout << endl;
		//cout << "결과: " << result << endl;
	}
}

void matching(int level) {
	if (level == n-1) {
		//cout << path << endl;
		calc(path);
		return;
	}

	for (int i = 0; i < 3; i++) {
		path[level] = sign[i];
		matching(level + 1);
		path[level] = 0;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	matching(0);

}
