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

/*�� ���̵��
	���� �Ŀ� ���ϸ鼭 �������µ� min �� �������ָ鼭 ���Ӱ� ��
	�� ���߿� 1�� ������ �Ǹ� �� �Ʒ��� �ִ� �༮���� ���� ������ �� ū �ֵ��̹Ƿ� �� ������ŭ �߰����ִ� ����� ����
*/