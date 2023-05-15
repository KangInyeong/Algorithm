/*
꿀을 채취할 수 있는 벌통의 수 M
1. 가로로 연속되도록 M개의 벌통 선택 -> 꿀 채취 (단, 두 일꾼이 선택한 벌통 서로 겹치면 X)
2. 선택한 벌통에서 꿀 채취하여 용기에 담기(단, 꿀이 섞이지 않도록 하나의 벌통에서 채취한 꿀은 하나의 용기에 담기)
	일부분만 채취 X 벌통에 모든 꿀 한번에 채취
	두 일꾼이 채취할 수 있는 꿀의 최대 양 C -> 넘을 경우 2개의 벌통 중 하나 선택해서 채취
3. 채취한 꿀 팔기 -> 한 용기에 있는 꿀의 양이 많을수록 상품가치 UP. 각 용기에 있는 꿀의 양 제곱만큼 수익
두 일꾼이 꿀을 채취하여 얻을 수 있는 수익의 합이 최대가 되는 경우를 찾고, 그 때의 최대 수익 출력
*/
#include <iostream>
using namespace std;

int n;
int N, M, C;
int honeyMAP[11][11];
int one[11][11];
int two[11][11];

void selectBee(int now) {
	for (int i = 0; i < 4; i++) {
		selectBee(now + 1);
	}
}

int sellHoney() {

	int money = 

	return money;
}

int main() {
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> C;
		for (int i = 0; i < N; i++) 
			for(int j=0; j<N; j++)
				cin >> honeyMAP[i][j];

		//1. 벌통 선택


		//2. 꿀 채취 
		// C이내가 아니라면 둘 중 하나의 벌통 선택

		int money = sellHoney();

		//3. 수익 비교
		int maxMoney = -21e8;
		if (money > maxMoney)
			maxMoney = money;
	}
	
}
