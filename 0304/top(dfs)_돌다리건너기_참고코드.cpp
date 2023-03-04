#include <iostream>
#include <string>
using namespace std;

int ans = 0;
string target; 
string bridge[2];
string path; 
int cnt = 0; 

void func(int idx, int bnum) {
	// 기저 조건 -> target과 동일한 루트로 도착했다면 하나의 경우의 수를 더 찾았다
	if (path == target) {
		ans++;
		return; 
	}

	// 0번으로 왔으면 1번, 1번으로 왔으면 0번 다리를 타야 한다. 
	if (bnum == 0)
		bnum = 1;
	else
		bnum = 0; 

	// 재귀 구성 -> 지금 위치 앞의 index로부터 다음 밟아야 하는 문자를 확인 
	for (int i = idx + 1; i < bridge[0].length(); i++) {
      	
		if (bridge[bnum][i] != target[cnt])
			continue; 
		
      	// 다음 밟아야 하는 문자라면
		cnt++;
		string temp = path;
      	// path 기록 
		path += bridge[bnum][i]; 
		
      	// i번 위치로부터 계속 진행
		func(i, bnum); 
		
      	// 복구 
		path = temp; 
		cnt--;
	}
}

int main() {
	cin >> target; 
	for (int i = 0; i < 2; i++)
		cin >> bridge[i]; 

	// 0부터 시작하는 루트
	func(-1, 0);
	// 1부터 시작하는 루트
	func(-1, 1); 
	cout << ans; 
}
