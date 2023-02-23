#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string map[4];

struct Node {
	char name;
	int y;
	int x;
};
vector<Node> v;

int dir[4][2] = {
	0,1,
	1,0,
	0,-1,
	-1,0
};

bool cmp(Node left, Node right) {
	return left.name < right.name;
}

void move(int idx, int y, int x, int t) {
	if (t >= 4) {
		t -= 4;
	}
	int ny = y + dir[t][0];
	int nx = x + dir[t][1];

	/*if (ny <0 && nx < 0 && ny >=4 && nx >= map[0].length())
		return;

	if (map[ny][nx] == '#' || (map[ny][nx] >= 'A' && map[ny][nx] <= 'Z'))
		return;*/
	if (ny >= 0 && nx >= 0 && ny < 4 && nx < map[0].length()) {
		if (map[ny][nx] == '_') {
			map[ny][nx] = map[y][x];
			map[y][x] = '_';
			v[idx] = { map[ny][nx] , ny, nx };
		}
	}

	return;
}

void find(int level) {

	if (level == 5)
		return;
	
	for (int i = 0; i < v.size(); i++) {
		Node now = v[i];
		move(i, now.y, now.x, level);		
	}

	find(level + 1);

}

int main() {

	for (int i = 0; i < 4; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < map[0].length() ;j++) {
			if (map[i][j] >= 'A' && map[i][j] <= 'Z') {
				v.push_back({ map[i][j], i, j });
			}
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	
	find(0);

	for (int i = 0; i < 4; i++) {
		cout << map[i] << endl;
	}

}