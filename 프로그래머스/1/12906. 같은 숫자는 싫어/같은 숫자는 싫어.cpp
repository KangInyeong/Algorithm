#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int startNum = arr[0];
    answer.push_back(startNum);
    for(int i=1; i<arr.size(); i++){
        if(arr[i] == startNum) continue;
        else{
            answer.push_back(arr[i]);
            startNum = arr[i];
        }
    }

    return answer;
}