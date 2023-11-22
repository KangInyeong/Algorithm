#include <iostream>
#include <vector>
using namespace std;

int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {

        int a, b;
        cin >> a >> b;

        int cnt = 1;
        if (a > b) {
            while (1) {
                if (a * cnt % b == 0) {
                    cout << a * cnt << endl;
                    break;
                }
                cnt++;
            }
        }
        else {
            while (1) {
                if (b * cnt % a == 0) {
                    cout << b * cnt << endl;
                    break;
                }
                cnt++;
            }
        }

    }
}