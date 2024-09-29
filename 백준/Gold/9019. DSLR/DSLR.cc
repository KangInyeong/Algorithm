#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int visited[10000] = { 0, };

int doD(int num) {
    int result = num * 2;
    if (result > 9999) result %= 10000;
    return result;
}

int doS(int num) {
    int result = num - 1;
    if (result == -1) result = 9999;
    return result;
}

int doL(int num) {
    int first = num / 1000;
    int result = (num % 1000) * 10 + first;
    return result;
}

int doR(int num) {
    int last = num % 10;
    int result = (last * 1000) + (num / 10);
    return result;
}
 
void transfer(int a, int b) {

    queue<pair<int, string>> q;

    q.push({ a, ""});
    visited[a] = 1;
    
    while (!q.empty()) {

        int num = q.front().first;
        string history = q.front().second;

        q.pop();

        if (num == b) {
            cout << history << endl;
            return;
        }

        int result = doD(num);
        if (visited[result] == 0) {
            visited[result] = 1;
            string newhis = history + "D";
            q.push({ result, newhis });
        }
        
        result = doS(num);
        if (visited[result] == 0) {
            visited[result] = 1;
            string newhis = history + "S";
            q.push({ result, newhis });
        }

        result = doL(num);
        if (visited[result] == 0) {
            visited[result] = 1; 
            string newhis = history + "L";
            q.push({ result, newhis });
        }

        result = doR(num);
        if (visited[result] == 0) {
            visited[result] = 1;
            string newhis = history + "R";
            q.push({ result, newhis });
        }

    }
}

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        transfer(a, b);
        memset(visited, 0, sizeof(visited));

    }

    return 0;
}