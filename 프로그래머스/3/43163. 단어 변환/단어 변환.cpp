#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <iostream>
using namespace std;

int visited[51] = {0,};
int answer = INT_MAX;

void dfs(string str, int sum, vector<string> words, string target){
    
    if(sum>words.size()) return;
    
    int flag = 0;
    for(int j=0; j<str.length(); j++){
        if(target[j]!=str[j]) flag++;
    }
    if(flag == 1) {
        if(sum < answer) answer = ++sum;
        cout << "최종:" << target;
        cout << endl;
        return;
    }
    
    for(int i=0; i<words.size(); i++){
        if(visited[i]!=0) continue;
        string checkWord = words[i];
        int chk = 0;
        for(int j=0; j<checkWord.length(); j++){
            if(checkWord[j]!=str[j]) chk++;
        }
        if(chk==1) {
            visited[i] = 1;
            cout << checkWord << " - ";
            dfs(checkWord, sum+1, words, target);
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
            
    int existChk = 0;
    for(int i=0; i<words.size(); i++){
        if(words[i]==target) existChk++;
    }
    if(existChk==0) return 0;
    
    for(int i=0; i<words.size(); i++){
        string checkWord = words[i];
        int flag = 0;
        for(int j=0; j<checkWord.length(); j++){
            if(checkWord[j]!=begin[j]) flag++;
        }
        if(flag==1) {
            if(checkWord == target) return 1;
            visited[i] = 1;
            cout << checkWord << " - ";
            dfs(checkWord, 1, words, target);
            memset(visited, 0, sizeof(visited));
        }
    }
    
    if(answer == INT_MAX) return 0;
    
    return answer;
}