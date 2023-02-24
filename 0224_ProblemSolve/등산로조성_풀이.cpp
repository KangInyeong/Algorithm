//다시보자!
#include <cstring> //memset사용
#include <iostream>
#include <vector>
using namespace std;

struct node {
	int y;
	int x;
	int canbreak; //깎을 수 있는 노드인가?
};
int n; //한 변의 길이
int k; //최대 공사 가능 높이
int map[10][10];
vector<node>v; //가장 높은 봉우리의 위치를 담을 벡터

int ydir[] = {-1,1,0,0};
int xdir[] = {0,0,-1,1};
int visited[10][10];
int cnt = 0; //총 몇 개의 칸을 이동했는지 확인할 정답 후보
int ans = -21e8;

void dfs(node now) {
	//기저조건(option)
	//어느 순간 now까지 왔을 때, ans보다 더 많은 길을 왔다
	if (cnt > ans) {
		ans = cnt;
		//여기서 기저조건처럼 return 시키면 안 됨. 왜냐하면 깊게 들어갈 수 있는데 멈출 이유가 없음. 자연히 종료가 될 때까지 돌게 두기.
	} 	

	//재귀구성
	//상하좌우 방향으로 갈 수 있는데까지 가봄
	for (int i = 0; i < 4; i++) {
		int ny = now.y + ydir[i];
		int nx = now.x + xdir[i];

		//범위체크
		if (ny < 0 || nx < 0||nx>=n||nx>=n)
			continue;
		if (visited[ny][nx] == 1)
			continue;

		//무작정 깊게 들어가는 것 x
		//#1. 만약 다음 가려는 위치가 지금 내 위치를 기준으로 
		// 더 높거나 같다 -> 깍아보고 갈 수 있으면 간다
		if (map[ny][nx] >= map[now.y][now].x) {
			//#1) 아직 깎아볼 수 있으면
			if (now.canbreak == 1) {
				//만약 다음 위치를 최대 k만큼 깎았을 때, 지금 내 위치보다 작아질 수만 있다면,
				//우리는 이 다음 위치를 (내위치-1)로 깎을 수 있다. -> (내위치 - 1) : 최대한 많이 흘러들어갈 수 있도록 만들기 위함.
				if (map[ny][nx] - k < map[now.y][now.x]) {
					//여기는 갈 수 있게 됨

					//본래의 map[ny][nx] 값을 저장해두고,,,
					int temp = map[ny][nx];

					//실제로 깎은 것을 맵에도 반영해줘야 함
					map[ny][nx] = map[now.y][now.x] - 1;
					visited[ny][nx] = 1;
					//이미 깎았으니까 더는 깎을 수 없는 상태로 진입
					cnt++;
					dfs({ ny, nx,0 });
					cnt--;
					visited[ny][nx] = 0;
					//들어갈 때에 넣었으니 나올 때 복구해야하는데
					//map[ny][nx] = map[now.y][now.x] + 1; //이렇게 복구할 수 있을까? 얼마나 깎았을지 모름. 원본의 상태로 돌려야함.
					map[ny][nx] = temp; //나올 때 복구,,,
				 }
			}
			//#2) 내가 이미 깎은 상태로 여기 왔으니 무조건 못가는 것 (아무것도 안하면 됨)
		}
		//#2. 지금 내가 가려고 하는 곳이 지금 내 위치를 기준으로
		// 더 낮다면 -> 그냥 가면 됨
		else {
			visited[ny][nx] = 1;
			//지금 내가 어떤 상태로 여기까지 왔는가?를 기준으로 canbreak 전달
			cnt++;
			dfs({ ny, nx , now.canbreak});
			visited[ny][nx] = 0;
			cnt--;
		}
	}
}
int main() {
	int t;
	for (int tc = 1; tc <= t; tc++) {
		//reset
		memset(map, 0, sizeof(map));
		v.clear();
		int max = -21e8;

		//input
		cin >> n >> k;
		//등산로 정보 입력
		//#방법1. 최대값만 찾아 놓고 나중에 다시 빙 돌면서 -> 최대값 위치일 때, dfs
		//(선택)#방법2. 모든 가장 높은 봉우리의 위치 저장 -> 그 위치들을 돌면서 dfs
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin << map[i][j];
				//이제 이 봉우리가 가장 높은 봉우리라면,
				//새로운 가장 높은 봉우리를 찾았다!
				if (map[i][j] > max) {
					//새로운 가장 높은 봉우리를 찾으면, 기존의 저장되었던 봉우리의 위치들을 쓸모가 없어지므로
					v.clear();
					v.push_back({ i, j });
					max = map[i][j];
				}
				//만약 지금 가장 높은 봉우리와 같은 높이의 봉우리를 찾았다면, 그냥 넣어주기
				else if (map[i][j] == max) {
					v.push_back({ i,j });
				}
			}

			//solve
			//2. 모든 가장 높은 봉우리에서의 dfs
			for (int i = 0; i < v.size(); i++) {
				// * 특수하게 reset해야 하는 경우
				memset(visited, 0, sizeof(visited));
				//내가 지금 들어가는 곳 방문 체크하고 시작
				cnt = 1; //초기화. 내가 지금 시작하는 것도 포함
				visited[v[i].y][v[i].x] = 1;
				dfs(v[i]);
			} 

			//output
			cout << "#" << tc << " " << ans << '\n';
		}
	}
}