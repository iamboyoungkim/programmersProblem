#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const string &a, const string &b){
    if (b+a < a+b) return true;
    else return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    int zeroCnt = 0;
    vector<string> tmp;
    
    for (int i = 0; i<numbers.size(); i++) {
        if (numbers[i] == 0) zeroCnt++;
        tmp.push_back(to_string(numbers[i]));
    }
    
    if (zeroCnt == numbers.size()) return "0";
    sort(tmp.begin(), tmp.end(), comp);
    
    for (int i = 0; i<tmp.size(); i++){
        answer += tmp[i];
    }
    return answer;
}