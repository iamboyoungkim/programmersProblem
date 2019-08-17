// 유형 : 스택/큐

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int> > q;
    priority_queue<int> pq;
    int size = priorities.size();
    for (int i = 0; i < size; i++) {
        q.push(make_pair(i, priorities[i])); // 순서, 중요도
        pq.push(priorities[i]);
    }
    
    while(!q.empty()) {
        // 중요도로 정렬한 순서랑 같으면
        if (q.front().second == pq.top()) {
            // location이 같으면 (정답인 경우)
            if (q.front().first == location) {
                return answer+1;
            }
            else {
                q.pop();
                pq.pop();
                answer++;
            }
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }
    return answer;
}