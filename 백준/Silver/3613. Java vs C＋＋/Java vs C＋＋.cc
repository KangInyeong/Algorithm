#include <iostream>
#include <string>
using namespace std;

int main() {

    string str;
    cin >> str;

    if (str[str.length() - 1] == '_' || str[0] == '_' || (str[0] >= 65&&str[0]<=90)) {
        cout << "Error!";
        return 0;
    }

    string newstr = "";
    newstr += str[0];
    if (str.find('_') != string::npos) {
        //c++
        bool flag = false;
        for (int i = 1; i < str.length(); i++) {
            if (str[i] >= 65 && str[i] <= 90) {
                //대문자가 등장하는 경우
                cout << "Error!";
                return 0;
            }
            if (str[i] == '_') {
                if (flag == true) {
                    // 연속으로 _ 등장하는 경우
                    cout << "Error!";
                    return 0;
                }
                flag = true;
                continue;
            }
            if (flag == true) {
                newstr += (str[i] - 32);
                flag = false;
            }
            else {
                newstr += str[i];
            }
        }
    }
    else {
        //java
        for (int i = 1; i < str.length(); i++) {
            if (str[i] >= 65 && str[i] <= 90) {
                newstr += '_';
                newstr += (str[i] + 32);
            }else {
                newstr += str[i];
            }
        }
    }

    cout << newstr;
}