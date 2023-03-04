/*
돌다리 
천사 & 악마 하나씩 건너야 함
한 칸씩 전진 필수
모두 밟아야 해
-> 모르겠어서 인터넷 dp 코드 가져옴.
=> dp[현재 돌다리 상의 위치][다리 종류(천사or악마)][지금까지 밟은 문자열 개수]
*/

#include <iostream>
#include <cstring>

using namespace std;

int dp[101][2][21];
string pattern, bridge[2];

int solve(int now_idx, int b_idx, int pa_idx) {
    if (pa_idx == pattern.size()) return 1;

    int& ret = dp[now_idx][b_idx][pa_idx];
    if (ret != -1) return ret;

    ret = 0;

    for (int i = now_idx; i < bridge[0].size(); i++) {
        if (bridge[b_idx][i] == pattern[pa_idx]) {
            ret += solve(i + 1, !b_idx, pa_idx + 1);
        }
    }

    return ret;
}

int main() {
    int result = 0;
    cin >> pattern >> bridge[0] >> bridge[1];

    memset(dp, -1, sizeof(dp));

    result += solve(0, 0, 0);   // 악마 먼저
    result += solve(0, 1, 0);   // 천사 먼저

    cout << result;

    return 0;
}
