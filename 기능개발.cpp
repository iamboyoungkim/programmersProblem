#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> q;
    
    int size = progresses.size();
    for (int i = 0; i<size; i++) {
        int needDay = 1;
        while(progresses[i] < 100) {
            progresses[i] += speeds[i];
            needDay++;
        }
        q.push_back(needDay);
    }
    
    int prev = q[0];
    int cnt = 1;
    for (int i = 1; i<q.size(); i++){
        if (prev >= q[i]) cnt++;
        else {
            answer.push_back(cnt);
            cnt = 1;
            prev = q[i];
        }
    }
    answer.push_back(cnt);
    return answer;
}