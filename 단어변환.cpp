#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<bool> visit;
vector<int> value;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool check = false;

    for (int i = 0; i<words.size(); i++) {
        if (target == words[o]) {
            check = true;
            break;
        }
    }
    
    if (!check) return 0;
    
    queue<pair<string, int>> q;
    
    visit.resize(words.size(), false);
    q.push({begin, 0}); // 초기 값 넣기
    
    while (!q.empty()) {
        string cur = q.front().first;
        int num = q.front().second;
        q.pop();
        
        // 정답일 경우
        if (cur.compare(target) == 0) {
            answer = num;
            break;
        }
        
        // 다음 경우 탐색
        for (int i = 0; i < words.size(); i++) {
            if (visit[i]) continue;
            int same = 0;
            
            // 알파벳 몇 개 바꿔야 하는지 갯수 세기
            for (int j = 0; j < cur.size(); j++) {
                if (cur[j] != words[i][j]) same++;
            }
            
            // 한번에 하나의 알파벳만 바꿀 수 있음 -> 큐에 넣기
            if (same == 1) {
                visit[i] = true;
                q.push({words[i], num+1});
            }
        }
    }
    
    return answer;
}