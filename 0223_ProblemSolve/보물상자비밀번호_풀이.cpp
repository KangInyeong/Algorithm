//�ٽú���
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N; // �� ������ ����(����)
int K; // K��° ū ����
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
		//�������� �� �� �ֵ��� s �ڿ� s�� �߰�
		s += s;

		//solve -> sliding window�� ����
		//�����̵� ������ : two pointer�� ���� -> ������ ������ ù ��° ����!
		//Step1. ������ ����
		int start = 0; //���� ������
		int end = N/4 - 1; //���� ũ�� ������

		//Step2. ���� ���� ����
		string temp = "";
		for (int i = start; i < end; i++) {
			temp += s[i];
		}

		//Step3. sliding window ����
		//s�� ���̰� 2��� �þ���Ƿ� while(end<N*2)
		while(end<N+N/4-1){
		//while (end < N) {
			//#1. ���� �ϼ� -> end�� ����Ű�� ���� ����
			temp += s[end];

			//#2. ���� -> �ϼ��� ����(16����)�� 10���� ��ȯ
			long long num = hextodec(temp);
			// -> �ߺ��� �ƴ϶�� (2�� �Ѱ� ���ϱ� DATó�� �Ұ���. MAP����)
			if (um.find(num) == um.end()) {
				//�� 10 ������ ������ ������ ���Ӱ� ã������ ���
				um[num] = 1;
				// -> �ĺ� ���
				v.push_back(num);
			}


			//#3. ���� ���� ���� �ϼ� ex) "1B3" -> "B3"
			/*string newstr = "";
			for (int i = 1; i < temp.length(); i++)
				newstr += temp[i];
			temp = newstr;*/ // => substr������� ����
			temp = temp.substr(1, temp.length());

			// -> ���� ���� ���� �ϼ��� �������� ù ��° ���� ����

			//#4. ������ �̵�
			start++;
			end++;
		}

		//�ĺ����� �� �ִ� vector�� ����
		//ū �ź��� �������� �� K��°
		//ū �� �켱���� ����
		sort(v.begin(), v.end(), cmp);
		
		//output
		cout << "#" << tc << " " << v[K-1] << '\n';
	}
}