#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct ResSet {
    int num;
    double rate;
};

// 실패율 큰것부터 정렬
bool comp(ResSet a, ResSet b) {
    return a.rate < b.rate;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> pass(N);
    vector<int> fail(N);
    vector<ResSet> res;

    sort(stages.begin(), stages.end());
    
    for (int i = 0; i<stages.size(); i++) {
        // 통과한 경우
        if (stages[i] > N) {
            for (int j = 0; j<N; j++) {
                pass[j]++;
            }
        }
        // 실패한 경우
        else {
            for (int j = 0; j<stages[i]; j++) {
                pass[j]++;
            }
            fail[stages[i] - 1]++;
        }
    }
    
    for (int i = 0; i<N; i++) {
        res.push_back({i+1, (double)pass[i]/fail[i]});
    }
    stable_sort(res.begin(), res.end(), comp); //sort와 다르게 순서를 유지하면서 정렬
    
    for (int i = 0; i<N; i++) {
        answer.push_back(res[i].num);
    }
    return answer;
}