//괜히 더 복잡하게 푼 느낌
#include <iostream>
#include <string>
using namespace std;

string str1, str2;
int main() {

	cin >> str1 >> str2;

	if (str1 == str2) {
		cout << str2;
		return 0;
	}

	int len1, len2;
	if (str1.length() < str2.length()) {
		len1 = str1.length();
		len2 = str2.length();
	}
	else {
		len1 = str2.length();
		len2 = str2.length();
	}
	
	string maxWord;
	int maxLen = -3;
	for (int i = 0; i < len1; i++) {
		for (int j = len1-i; j >= 1; j--) {
			string word = str1.substr(i, j);
			//cout << "조합: " << word << endl;
			if (str2.find(word) != string::npos) {
				//cout << "찾음-" << word << endl;
				int wl = word.length();
				if (maxLen < wl) {
					maxLen = word.length();
					maxWord = word;
				}
			}
		}
	}

	for (int i = len1; i >=1; i--) {
		for (int j = 0; j <i; j++) {
			string word = str1.substr(j,i);
			if (str2.find(word) != string::npos) {
				int wl = word.length();
				if (maxLen < wl) {
					maxLen = word.length();
					maxWord = word;
				}
			}
		}
	}
	
	cout << maxWord;

}
