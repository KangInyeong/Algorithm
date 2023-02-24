#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Person {
	int num;
	string name;
	int score;
};

bool cmp(Person left, Person right) {
	if (left.score > right.score)
		return true;
	if (left.score < right.score)
		return false;
	if (left.num > right.num)
		return true;
	if (left.num < right.num)
		return false;
	return false;
}
vector<Person> v;

int n;
int main() {
	cin >> n;

	string name;
	int score;
	for (int i = 0; i < n; i++) {
		cin >> name >> score;
		v.push_back({ i, name, score });
		sort(v.begin(), v.end(), cmp);
		for (int j = 0; j < v.size(); j++) {
			if (j == 3) break;
			cout << v[j].name << " ";
		}cout << endl;
	}
}
