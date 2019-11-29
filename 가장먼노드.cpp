#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> graph(n+1, vector<int>());
    vector<bool> isVisit(n+1);
    vector<int> dist(n+1);
    
    queue<int> q;
    
    for (int i = 0; i<edge.size(); i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    q.push(1);
    isVisit[1] = true;
    dist[1] = 0;
    
    while (!q.empty()) {
        int start = q.front();
        q.pop();
        
        for (int i = 0; i<graph[start].size(); i++) {
            int next = graph[start][i];
            if (!isVisit[next]) {
                isVisit[next] = true;
                q.push(next);
                dist[next] = dist[start] + 1;
            }
        }
    }
    
    sort(dist.begin(), dist.end());
    
    int max = dist[dist.size()-1];
    for (int i = 1; i<=n; i++) {
        if (dist[i] == max) answer++;
    }

    return answer;
}