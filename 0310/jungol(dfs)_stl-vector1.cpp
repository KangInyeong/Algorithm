/*
- 배열 정적 선언
int arr[ 1010 ]; /// 숫자 배열
char name[ 510 ][ 30 ]; /// 1차원 문자열 배열 (또는 2차원 문자 배열, 해석하기 나름)
Data list[ 110 ]; ///struct를 통해 만든 Data형 배열

- 배열 동적 선언
int n;
int* arr;
scanf("%d",&n);
arr = new int[n+5];

=> 쓰기 조금 더 편하게 만들어놓은 배열이 바로 벡터
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v[100000];
int steps[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num, a;
        cin >> num;
        for (int j = 0; j < num; j++) {
            cin >> a;
            v[i].push_back(a);
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> steps[i];
    }

        for (int i = 0; i < n; i++) {

            int s = v[steps[i]].size();

            for (int x = 0; x < s; x++) {
                cout << v[steps[i]][x] << ' ';
            }cout << endl;

        }

}
