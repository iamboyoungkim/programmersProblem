#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> per1 {1,2,3,4,5};
    vector<int> per2 {2,1,2,3,2,4,2,5};
    vector<int> per3 {3,3,1,1,2,2,4,4,5,5};
    
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    
    for (int i = 0; i<answers.size(); i++){
        if (answers[i] == per1[i%5]) cnt1++;
        if (answers[i] == per2[i%8]) cnt2++;
        if (answers[i] == per3[i%10]) cnt3++;
    }
    
    int maxCnt = max(cnt1, max(cnt2, cnt3));
    
    if (maxCnt == cnt1) answer.push_back(1);
    if (maxCnt == cnt2) answer.push_back(2);
    if (maxCnt == cnt3) answer.push_back(3);
    
    return answer;
}