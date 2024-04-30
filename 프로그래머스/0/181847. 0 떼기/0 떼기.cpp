#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    string answer = "";
    
    bool flag = false;
    for(int i=0; i<n_str.length(); i++){
        if(n_str[i] == '0' && flag == false) continue;
        else{
            answer += n_str[i];
            flag = true;
        }
    }
    
    return answer;
}