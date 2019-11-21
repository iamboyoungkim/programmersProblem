#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 오름차순
bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int solution(vector<int> food_times, long long k) {
    int answer = -1;
    int size = food_times.size();
    vector<pair<int, int> > food;
    
    for (int i = 0; i<size; i++) {
        food.push_back({food_times[i], i+1}); // 시간, 번호
    }
    sort(food.begin(), food.end());
    
    long long tmp = 0, time = 0;
    
    for (int i = 0; i<size; i++) {
        tmp = time;
        // 처음 원소
        if ((i == 0) && size * food[0].first <= k) {
            time = size * food[0].first;
            continue;
        }
        // 다음 원소들
        else if (i != 0){
            time += (size - i) * (food[i].first - food[i-1].first);
            if (time <= k) continue;
        }
        k -= tmp;
        sort(food.begin() + i, food.end(), cmp);
    
        int cnt = size - i;
        return food[i + (k%cnt)].second;
    }
    
    return answer;
}
