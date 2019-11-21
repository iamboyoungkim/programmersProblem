#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> answer;
vector<string> tmp;

bool dfs(string start, vector<vector<string>> & tickets, vector<bool> &isVisit, int idx) {

    tmp.push_back(start);
    
    // 정답인 경우
    if (idx == tickets.size()) {
        answer = tmp;
        return true;
    }
    
    // 다음 단계 탐색
    for (int i = 0; i<tickets.size(); i++) {
        if (tickets[i][0] == start && !isVisit[i]) {
            isVisit[i] = true;
            if (dfs(tickets[i][1], tickets, isVisit, idx+1)) return true;
            isVisit[i] = false;
        }
    }
    tmp.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<bool> isVisit(tickets.size(), false);
    
    // 알파벳 순서대로 정렬
    sort(tickets.begin(), tickets.end());
    
    // 탐색 시작
    dfs("ICN", tickets, isVisit, 0);
    
    return answer;
}