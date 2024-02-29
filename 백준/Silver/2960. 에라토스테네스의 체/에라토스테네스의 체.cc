#include <iostream>
using namespace std;

int arr[1001] = { 0, };
void check(int start, int finish, int cnt, int times) {
    
    int newstart = -1;
    bool flag = false;
    for (int i = start; i <= finish; i++) {
        if (arr[i] != 1 && i%start==0) {
            arr[i] = 1;
            cnt++;
        }
        
        if (arr[i] != 1 && i % start != 0 && newstart == -1) {
            newstart = i;
        }

        if (cnt == times) {
            cout << i;
            flag = true;
            break;
        }
    }

    if (flag) {
        return;
    }
    else {
        check(newstart, finish, cnt, times);
    }

};

int main() {

    int n, k;
    cin >> n >> k;

    check(2, n, 0, k);

    return 0;
}