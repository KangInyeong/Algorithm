#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int n;
char type;
int price;
int maze[1001][1001] = { 0, };
int cost[1001] = { 0, };
int visited[1001] = { 0, };

void nextRoom(int idx) {
    
    int num;
    while (1) {
        cin >> num;
        if (num == 0) break;
        maze[idx][num] = 1;
    }

}

int check(int start, int money) {

    visited[start] = 1;

    if (start == n) {
        return 1;
    }

    for (int next = 1; next <= n; next++) {
        if (visited[next] == 1) continue;
        if (maze[start][next] != 1) continue;

        int tmp = money + cost[next];
        if (tmp < 0) continue;

        if ((cost[next] > money) || (cost[next] < 0)) {
            int result = check(next, money + cost[next]);
            if (result == 1) return 1;
        }
        else {
            int result = check(next, money);
            if (result == 1) return 1;
        }
    }

    return 0;
}

int main() {

    while (1) {

        cin >> n;
        if (n == 0) break;

        memset(maze, 0, sizeof(maze));
        memset(cost, 0, sizeof(cost));
        memset(visited, 0, sizeof(visited));


        for (int i = 1; i <= n; i++) {
            cin >> type >> price;
            if (type == 'L') {
                cost[i] = price;
                nextRoom(i);
            }
            else if (type == 'T') {
                cost[i] = -price;
                nextRoom(i);
            }
            else {
                //type == 'E'
                nextRoom(i);
            }
        }
       
        if (check(1, 0)) {
            cout << "Yes" << endl;
        }else {
            cout << "No" << endl;
        }

    }

    return 0;
}