#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int target, vector<int> numbers, int idx) {
    if (idx == numbers.size()){
        int sum = 0;
        for (int i = 0; i<numbers.size(); i++){
            sum += numbers[i];
        }
        if (sum == target) answer++;
        return;
    }
    numbers[idx] *= 1;
    dfs(target, numbers, idx+1);
    numbers[idx] *= -1;
    dfs(target, numbers, idx+1);
}

int solution(vector<int> numbers, int target) {
    dfs(target, numbers, 0);
    return answer;
}