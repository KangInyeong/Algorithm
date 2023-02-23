#include <iostream>
using namespace std;

int main() {
	int arr[5] = { 0, };
	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	int cnt = 0;
	for (int b = 0; b < (1 << 5); b++) {
		int temp = b;
		int sum = 0;
		int idx = 0;
		while (temp) {
			if (temp & 1)
				sum += arr[idx];
			idx++;
			temp >>= 1;
		}
		if (sum >= 10 && sum <= 20)
			cnt++;
	}
	cout << cnt;
}