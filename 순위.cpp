#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> graph(n+1, vector<int>());
    
    for (int i = 0; i<results.size(); i++) {
        graph[results[i][0]][results[i][1]]++; // 이기면 +1
        graph[results[i][1]][results[i][0]]--; // 지면 -1
    }
    
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) {
            if ()
        }
    }
    
    
    return answer;
}