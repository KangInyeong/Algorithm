#include <iostream>
#include <vector>
using namespace std;

int main() {

    int m, n;
    cin >> m >> n;

    vector<int>sosoo;
    for (int i = m; i <= n; i++) {
        //i�� �Ҽ����� Ȯ��
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
            //�Է� ���ڰ� 1�� ��� �Ҽ��� �������� ����
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