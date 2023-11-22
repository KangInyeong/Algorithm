#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int>v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    vector<int>comnum;
    for (int i = 0; i < n; i++) {
        int num = v[i];
        if (i == 0) {
            for (int j = 1; j <= v[i]; j++) {
                if (num % j == 0) comnum.push_back(j);
            }
        }
        else {
            vector<int>tmpnum;
            for (int j = 0; j < comnum.size(); j++) {
                int tmp = comnum[j];
                if (tmp > num) break;
                if (num % tmp == 0) tmpnum.push_back(tmp);
            }
            comnum.clear();
            for (int j = 0; j < tmpnum.size(); j++) {
                comnum.push_back(tmpnum[j]);
            }
        }
    }

    for (int j = 0; j < comnum.size(); j++) {
        cout << comnum[j] << '\n';
    }


}