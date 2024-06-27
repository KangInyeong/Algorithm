#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    int a, b;
    cin >> a >> b ;

    int arr_a[3], arr_b[3];
    int newa = 0;
    int newb = 0;

    for (int j = 2; j >= 0; j--) {
        int t = pow(10, j);
        arr_a[2 - j] = a / t;
        arr_b[2 - j] = b / t;
        a %= t;
        b %= t;
    }

    for (int i = 2; i >= 0; i--) {
        newa += arr_a[i] * pow(10, i);
        newb += arr_b[i] * pow(10, i);
    }
    
    for (int i = 2; i >= 0; i--) {
        if (arr_a[i] > arr_b[i]) {
            cout << newa;
            return 0;
        }
        else if (arr_a[i] < arr_b[i]) {
            cout << newb;
            return 0;
        }
        
        continue;
    }


    return 0;
}
