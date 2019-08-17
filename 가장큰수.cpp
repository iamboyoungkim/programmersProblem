// 유형 : 정렬

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b) {
    if (a+b > b+a) return true;
    else return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp;
    int zero = 0;
    
    for (int i = 0; i<numbers.size(); i++){
        if (numbers[i] == 0) zero++;
        tmp.push_back(to_string(numbers[i]));
    }
    if (zero == numbers.size()) return "0";
    sort(tmp.begin(), tmp.end(), compare);
    
    for (int i = 0; i<tmp.size(); i++){
        answer += tmp[i];
    }
    return answer;
}