#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>>v(101);

    for (int a = 0; a < m; a++) {
        int i, j, k;
        cin >> i >> j >> k;
        for (int b = i; b <= j; b++) {
            if (!v[b].empty()) {
                v[b].clear();
            }
            v[b].push_back(k);
        }
    }

    for (int a = 1; a <= n; a++) {
        if (v[a].empty()) cout << 0 << ' ';
        else cout << v[a][0] << ' ';
    }

    return 0;
}
