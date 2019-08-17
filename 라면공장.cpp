// 유형 : 힙

#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int> > pq;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int day = 0;
    
    for (int i = 0; i<k; i++) {
        if (i == dates[day]) {
            pq.push(supplies[day]);
            if (day != supplies.size() - 1) day++;
        }
        if (stock == 0) {
            answer++;
            stock += pq.top();
            pq.pop();
        }
        stock--;
    }
    return answer;
}