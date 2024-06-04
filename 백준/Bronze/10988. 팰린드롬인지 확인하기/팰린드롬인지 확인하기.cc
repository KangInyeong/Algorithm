#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string s;
    cin >> s;

    int flag = 1;
    int len = s.length();

    for (int i = 0; i < len; i++) {
        char a = s[i];
        char b = s[len -1 - i];
        if (a != b) {
            flag = 0;
            break;
        }
    }

    cout << flag;

    return 0;
}
