#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

int answer = 0;

void dfs(int target, vector<int> numbers, int idx){
    // 정답인 경우
    if (idx == numbers.size()){
        int sum = 0;
        for (int i = 0; i<numbers.size(); i++){
            sum += numbers[i];
        }
        if (sum == target) answer++;
        return;
    }
    // 다음 스텝
    numbers[idx] *= 1; //더함
    dfs(target, numbers, idx+1);
    numbers[idx] *= -1; //뺌
    dfs(target, numbers, idx+1);
}

int solution(vector<int> numbers, int target) {
    dfs(target, numbers, 0);
    return answer;
}
