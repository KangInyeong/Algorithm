#include <iostream>
#include <vector>
using namespace std;

int parents[1000];
int n;
int flag;

int Find(int now) {

	if (now == parents[now])
		return now;

	return parents[now] = Find(parents[now]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb) {
		flag = 1;
		return;
	}

	parents[pb] = pa;

}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++)
		parents[i] = i;

	int value;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> value;
			if (i<j&& value == 1) {
				
				/* (교수님코드) 조상이 같다면 -> 순환 회로가 있다! 
				if (Find(i) == Find(j)) {
					cout << "WARNING";
					return 0;
				}
				*/

				Union(i, j);
			}
		}
	}

	if (flag == 1)
		cout << "WARNING";
	else
		cout << "STABLE";
}
