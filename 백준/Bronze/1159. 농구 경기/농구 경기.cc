#include <iostream>
#include <string>
using namespace std;

int main() {

    int n;
    cin >> n;
    string str;
    int arr[130] = { 0, };
    for (int i = 0; i < n; i++) {
        cin >> str;
        arr[str[0]]++;
    }

    int flag = false;
    for (int i = 'a'; i <= 'z'; i++) {
        if (arr[i] >= 5){
            cout << (char)i;
            flag = true;
        }
    }

    if (flag == false) cout << "PREDAJA";
}