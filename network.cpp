#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

int networks[201][201];
bool check[201]; //방문했는지 체크하는 배열

void dfs(int x, int n){
    check[x] = true;
    for (int i = 0; i<n; i++){
        if (networks[x][i] == 1 && check[i] == false){
            dfs(i,n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (computers[i][j] == 1) networks[i][j] = 1;
        }
    }
    for (int i = 0; i<n; i++){
        if (!check[i]) {
            dfs(i,n);
            answer++;
        }
    }
    return answer;
}
