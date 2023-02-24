#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int id;
	int coding;
	int interview;
};

vector<Node>v;
int N;

bool cmp1(Node left, Node right) {
	if (left.coding < right.coding)
		return true;
	if (left.coding > right.coding)
		return false;
	return false;
}

int main() {
	cin >> N;
	int id, coding, interview;
	for (int i = 0; i < N; i++) {
		cin >> coding >> interview;
		v.push_back({ i, coding, interview });
	}

	sort(v.begin(), v.end(), cmp1);

	int cnt = 0;
	int min = v[0].interview;
	for (int i = 1; i < N; i++) {
		Node now = v[i];
		if (now.interview > min) {
			cnt++;
		}
		if (now.interview < min)
			min = now.interview;
	}

	cout << N - cnt;
}

/*비교 아이디어
	정렬 후에 비교하면서 내려가는데 min 을 갱신해주면서 새롭게 비교
	그 와중에 1이 나오게 되면 그 아래에 있는 녀석들은 전부 비교했을 때 큰 애들이므로 그 개수만큼 추가해주는 방법도 존재
*/