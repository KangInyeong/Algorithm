#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    cin >> n;
    int cnt = 0;

    int chknum = n;
    int right;
    int newnum;

    while(1) {

        if (n < 10) {
            right = n;
            newnum = n;
        }
        else {
            right = n % 10;
            newnum = n / 10 + right;
        }

        n = (right * 10) + (newnum % 10);

        if (chknum == n)break;
        
        cnt++;
    }

    cout << cnt + 1;

}