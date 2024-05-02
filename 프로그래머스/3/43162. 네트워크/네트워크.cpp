#include <string>
#include <vector>
#include <iostream>
using namespace std;

int N;
int visited[201] = {0,};

void dfs(int now, vector<vector<int>> computers){
    
    visited[now] = 1;
    
    for(int j=0; j<N; j++){
        if(computers[now][j]==1 && visited[j]==0) dfs(j, computers);
    }
    
    return;
    
}

int solution(int n, vector<vector<int>> computers) {
    
    N = n;
    int answer = 0;
    for(int i=0; i<n; i++){
        if(visited[i]==0) {
            dfs(i, computers);
            answer++;
        }
    }
   
    return answer;
}