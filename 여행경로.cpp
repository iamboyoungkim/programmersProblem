#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visit[10001];
vector<string> answer;

void dfs(string start, vector<vector<string>> tickets) {
    answer.push_back(start);
    for (int i = 0; i<tickets.size(); i++){
        if (tickets[i][0] == start && visit[i] == false) {
            visit[i] = true;
            dfs(tickets[i][1], tickets);
            return;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets);
    return answer;
}