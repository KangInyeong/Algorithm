#include <iostream>
#include <string>
using namespace std;

void checkStr(string str) {
    int single = 0;
    bool flag = true;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') single++;

        if (single > 0 && str[i] == ')') single--;
        else if(single <= 0 && str[i] == ')') {
            flag = false;
            break;
        }
    }

    if (single != 0) flag = false;
    
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
};

int main() {

    int n;
    cin >> n;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        checkStr(s);
    }

    return 0;
}