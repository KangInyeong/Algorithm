#include<vector>
#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int y;
    int x;
};

int MAP[101][101] = {0,};
int visited[101][101] = {0, };
int move(int ny, int nx, int ty, int tx){
    
    int dy[4] = {0,0,-1,1};
    int dx[4] = {-1,1,0,0};
    
    queue<Node> q;
    q.push({ny, nx});
    visited[ny][nx] = 1;
    
    while(!q.empty()){
        
        Node now = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int cy = now.y + dy[i];
            int cx = now.x + dx[i];
            
            if(cy<0||cx<0||cy>ty||cx>tx) continue;
            if(MAP[cy][cx]==0) continue;
            if(visited[cy][cx]!=0) continue;
            
            q.push({cy, cx});
            visited[cy][cx] = visited[now.y][now.x]+1;
            
        }   
    }
    
    return visited[ty][tx];
    
}

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    
    int ny = 1;
    int nx = 1;
    int ty = maps.size();
    int tx = maps[0].size();
    
    for(int i=0; i<ty; i++){
        for(int j=0; j<tx; j++){
            MAP[i][j] = maps[i][j];
        }
    }
    
    int result = move(ny-1, nx-1, ty-1, tx-1);
    if(result != 0) answer = result;
    
    return answer;
}