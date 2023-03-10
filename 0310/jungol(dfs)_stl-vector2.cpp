/*
- 벡터 선언 방법
vector<char> arr;
vector<int> arr(10);

1. pop_back() -> arr.pop_back()
2. resize() -> (벡터이름).resize(크기) // arr.resize(8,1)
3. front(), back() : 맨 앞, 맨 뒤의 원소 반환
4.empty()
5. 정렬 sort(arr.begin(),arr.end());
+. reverse(arr.begin(),arr.end());
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x;
vector<int>v;

int main() {
	cin >> n >> x;
	v.resize(n, x);

	char cmd;
	while (1) {

		cin >> cmd;

		if (cmd == 'r') {
			if (!v.empty()) {
				v.pop_back();
			}
		}
		else if (cmd == 'i') {
			int num;
			cin >> num;
			v.push_back(num);
		}
		else if (cmd == 't') {
			if (v.size()>=2) {
				int first = v.front();
				int last = v.back();
				v.erase(v.begin());
				v.pop_back();
				v.insert(v.begin(), last);
				v.push_back(first);
			}
		}
		else if (cmd == 's') {
			if(!v.empty())
				sort(v.begin(), v.end());
		}
		else if (cmd == 'e') {
			break;
		}
	}
		
	for (int j = 0; j < v.size(); j++) {
		cout << v[j] << ' ';
	}

}
