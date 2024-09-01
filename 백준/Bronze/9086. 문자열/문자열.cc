#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;
        cout << str[0] << str[str.length() - 1] << endl;
    }

}