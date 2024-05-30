#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    
    int t;
    cin >> t;

    int jx, jy, bx, by, jr, br;
    for (int i = 0; i < t; i++) {
        cin >> jx >> jy >> jr >> bx >> by >> br;

        if (jr > br) {
            swap(jx, bx);
            swap(jy, by);
            swap(jr, br);
        }

        double distance = sqrt(pow(abs(jx - bx), 2) + pow(abs(jy - by), 2));

        if (distance == 0 && jr == br) cout << -1 << endl;
        else if (distance > jr + br || distance < br - jr) cout << 0 << endl;
        else if (distance == jr + br || distance == br - jr) cout << 1 << endl;
        else cout << 2 << endl;
    
    }

    return 0;
}
