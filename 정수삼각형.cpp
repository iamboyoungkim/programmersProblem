#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    vector<vector<int>> dp(size, vector<int>(size));
	dp[0][0] = triangle[0][0];
    
    for (int i = 1; i<size; i++) {
        for (int j = 0; j<=i; j++) {
            // 왼쪽 끝
            if (j == 0) dp[i][j] = dp[i-1][j] + triangle[i][j];
            // 오른쪽 끝
            else if (j == i) dp[i][j] += dp[i-1][j-1] + triangle[i][j];
            // 기타
            else dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            
            // 최댓값 구하기
            if (i == triangle.size() - 1) answer = max(answer, dp[i][j]);
        }
    }
    return answer;
}