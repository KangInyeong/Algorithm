#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[5];
int used[5];
vector<int>v;

int cnt = 0;

int eachCnt = 1;
void find(int level) {
	if (level == eachCnt) {
		int comsum = 0;
		for (int i = 0; i < v.size(); i++)
			comsum += v[i];

		if (comsum >= 10 && comsum <= 20) {
			cnt++;
		}

		return;
	}

	for (int i = 0; i < 5; i++) {

		if (used[i] == 1) continue;

		if (level > 0 && arr[i] < v[level - 1])
			continue;

		used[i] = 1;
		v.push_back(arr[i]);
		find(level + 1);
		used[i] = 0;
		v.pop_back();
	}

}
int main() {
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + 5);

	for (eachCnt = 1; eachCnt <= 5; eachCnt++) {

		find(0);
	}

	cout << cnt;
}