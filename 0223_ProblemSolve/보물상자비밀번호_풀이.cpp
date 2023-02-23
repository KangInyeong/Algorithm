//다시보자
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N; // 총 문자의 개수(길이)
int K; // K번째 큰 숫자
string s;

bool cmp(long long left, long long right) {
	if (left > right)
		return true;
	if (left < right)
		return false;
	return false;
}

long long hextodec(string s) {
	long long res = 0;
	for (int i = 0; i < s.length(); i++) {
		int now = s[i];
		int temp = 0;
		//0~9
		if (now >= '0' && now <= '9')
			temp = now - '0';
		//alphabet capital A~f
		else
			temp = now - 55; 

	}
}

int main() {
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		//reset
		unordered_map<long long, int>um;
		vector<long long>v;
		//input
		cin >> N >> K;
		cin >> s;
		//원형으로 돌 수 있도록 s 뒤에 s를 추가
		s += s;

		//solve -> sliding window로 구현
		//슬라이딩 윈도우 : two pointer의 일종 -> 포인터 셋팅이 첫 번째 순서!
		//Step1. 포인터 세팅
		int start = 0; //시작 포인터
		int end = N/4 - 1; //구간 크기 포인터

		//Step2. 공통 구간 세팅
		string temp = "";
		for (int i = start; i < end; i++) {
			temp += s[i];
		}

		//Step3. sliding window 수행
		//s의 길이가 2배로 늘어났으므로 while(end<N*2)
		while(end<N+N/4-1){
		//while (end < N) {
			//#1. 구간 완성 -> end가 가리키는 값을 더함
			temp += s[end];

			//#2. 수행 -> 완성된 구간(16진수)를 10진수 변환
			long long num = hextodec(temp);
			// -> 중복이 아니라면 (2억 넘게 가니까 DAT처리 불가능. MAP생성)
			if (um.find(num) == um.end()) {
				//이 10 진수는 기존에 없었고 새롭게 찾았으니 기록
				um[num] = 1;
				// -> 후보 등록
				v.push_back(num);
			}


			//#3. 다음 공통 구간 완성 ex) "1B3" -> "B3"
			/*string newstr = "";
			for (int i = 1; i < temp.length(); i++)
				newstr += temp[i];
			temp = newstr;*/ // => substr사용으로 변경
			temp = temp.substr(1, temp.length());

			// -> 내가 지금 만든 완성된 구간에서 첫 번째 값을 빼줌

			//#4. 포인터 이동
			start++;
			end++;
		}

		//후보들이 들어가 있는 vector를 정렬
		//큰 거부터 나열했을 때 K번째
		//큰 거 우선으로 정렬
		sort(v.begin(), v.end(), cmp);
		
		//output
		cout << "#" << tc << " " << v[K-1] << '\n';
	}
}