#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool flag = false;
    
    while(!flag) {
        vector<vector<int>> visit(m, vector<int>(n));
        flag = true;
        for (int i = 0; i<m-1; i++) {
            for (int j = 0; j<n-1; j++) {
                if (board[i][j] == 0) continue;
                // 2x2 형태 확인
                else if ( (board[i][j] == board[i+1][j]) && (board[i][j] == board[i][j+1]) && (board[i][j] == board[i+1][j+1])) {
                    visit[i][j] = 1;
                    visit[i+1][j] = 1;
                    visit[i][j+1] = 1;
                    visit[i+1][j+1] = 1;
                    flag = false;
                }
            }
        }
        // 지우기
        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                // 지워질 부분이면
                if (visit[i][j] == 1) {
                    answer++;
                    for (int k = i-1; k>=0; k--) {
                        board[k+1][j] = board[k][j];
                        board[k][j] = 0;
                    }
                }
            }
        }
    }
    return answer;
}