// for문법 
// for(int element : arr)
#include <iostream>
using namespace std;

char alpabets[26];
int main() {
	for (char tmp = 'A'; tmp <= 'Z'; tmp++)
	{
		int temp = tmp - 'A';
		alpabets[temp] = tmp;
	}

	for (char l : alpabets)
		cout << l << ' ';
}
