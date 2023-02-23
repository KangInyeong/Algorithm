//뭔가 엄청 비효율적으로 만든 코드 같다!
#include <iostream>
#include <string>
using namespace std;

string str1, str2, str3;
int main() {

    cin >> str1 >> str2 >> str3;

    int len1 = str1.length();
    int len2 = str2.length();
    int len3 = str3.length();

    if (len1 > len2 && len1 > len3) {
        cout << str1;
        return 0;
    }
    else if (len2 > len1 && len2 > len3) {
        cout << str2;
        return 0;
    }
    else if (len3 > len1 && len3 > len2) {
        cout << str3;
        return 0;
    }
    else if (len1 == len2 && len2 == len3 && len1 == len3) {
        int i = 0;
        while (str1[i] == str2[i] && str1[i] == str3[i] && str2[i] == str3[i]) {
            i++;
        }

        if (str1[i]=='1' && str2[i] == '1') {
            int j = 0;
            while (str1[j] == str2[j]) {
                j++;
            }
            if (str1[j] == '1') {
                cout << str1;
                return 0;
            }
            else {
                cout << str2;
                return 0;
            }
        }
        else if (str2[i] == '1' && str3[i]=='1') {
            int j = 0;
            while (str2[j] == str3[j]) {
                j++;
            }
            if (str2[j] == '1') {
                cout << str2;
                return 0;
            }
            else {
                cout << str3;
                return 0;
            }
        }
        else if (str1[i] == '1' && str3[i] == '1') {
            int j = 0;
            while (str1[j] == str3[j]) {
                j++;
            }
            if (str1[j] == '1') {
                cout << str1;
                return 0;
            }
            else {
                cout << str3;
                return 0;
            }
        }
        
    }
    else if (len1 == len2 && len1 > len3) {
        int j = 0;
        while (str1[j] == str2[j]) {
            j++;
        }
        if (str1[j] == '1') {
            cout << str1;
            return 0;
        }
        else {
            cout << str2;
            return 0;
        }
    }
    else if (len1 == len3 && len1 > len2) {
        int j = 0;
        while (str1[j] == str3[j]) {
            j++;
        }
        if (str1[j] == '1') {
            cout << str1;
            return 0;
        }
        else {
            cout << str3;
            return 0;
        }
    }
    else if (len2 == len3 && len2 > len1) {
        int j = 0;
        while (str2[j] == str3[j]) {
            j++;
        }
        if (str2[j] == '1') {
            cout << str2;
            return 0;
        }
        else {
            cout << str3;
            return 0;
        }
    }

    cout << "dpd" << endl;
    return 0;


}
