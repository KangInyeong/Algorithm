#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int>v;
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            v.push_back(a);
        }
        
        int dp[1001];
        int maxnum = INT_MIN;
        for (int k = 0; k < n; k++) {
            dp[k] = max(0, dp[k - 1]) + v[k];
            maxnum = max(maxnum, dp[k]);
        }
        cout << maxnum << endl;
    }

    return 0;
}