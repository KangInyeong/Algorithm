#include <iostream>
using namespace std;

int a[1000001] = { 0, };

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int b, c;
    cin >> b >> c;

    long long  total = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] - b < 0) a[i] = 0;
        else a[i] -= b;
        total++;
    }

    long long sub = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        int remain = a[i] % c;
        if (remain != 0) sub += (a[i] / c + 1);
        else sub += (a[i] / c);

    }
    cout << total + sub;

    return 0;

}