// 유형 : dfs
#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int idx, int target, vector<int> numbers) {
    // 정답인 경우
    if (numbers.size() == idx) {
        int sum = 0;
        for (auto n : numbers) {
            sum += n;
        }
        if (sum == target) answer++;
        return;
    }
    // 다음 단계 탐색
    numbers[idx] *= 1;
    dfs(idx+1, target, numbers);
    numbers[idx] *= -1;
    dfs(idx+1, target, numbers);
}

int solution(vector<int> numbers, int target) {
    dfs(0, target, numbers);
    return answer;
}