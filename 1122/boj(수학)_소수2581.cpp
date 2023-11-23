#include <iostream>
#include <vector>
using namespace std;

int main() {

    int m, n;
    cin >> m >> n;

    vector<int>sosoo;
    for (int i = m; i <= n; i++) {
        //i가 소수인지 확인
        int flag = false;

        if (i > 1) {
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    flag = true;
                    break;
                }
            }
        }
        else {
            //입력 숫자가 1일 경우 소수에 포함하지 않음
            flag = true;
        }

        if (flag == false) {
            sosoo.push_back(i);
        }
    }

    if (sosoo.size() == 0) {
        cout << -1;
    }
    else {
        int sum = 0;
        int minsosoo = n + 1;
        for (int i = 0; i < sosoo.size(); i++) {
            sum += sosoo[i];
            if (sosoo[i] < minsosoo) minsosoo = sosoo[i];
        }
        cout << sum << '\n' << minsosoo;
    }
}