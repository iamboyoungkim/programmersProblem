#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int num;
bool visit[101];
vector<pair<int, int> > path[101];

int prim(int start){
    visit[start] = true;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for (int i = 0; i < path[start].size(); i++){
        int next = path[start][i].first;
        int nextCost = path[start][i].second;
        pq.push(pair<int, int>(nextCost, next));
    }
    
    int answer = 0;
    while (!pq.empty()){
        int cur = pq.top().second;
        int curCost = pq.top().first;

        pq.pop();

        if (visit[cur]) continue;

        visit[cur] = true;
        answer += curCost;

        for (int i = 0; i < path[cur].size(); i++){
            int tmp = path[cur][i].first;
            int tmpCost = path[cur][i].second;
            pq.push(pair<int, int>(tmpCost, tmp));
        }
    }
    return answer;
}

int solution(int n, vector<vector<int> > costs) {
    int answer = 0;
    num = n;

    for(int i=0; i<(int)costs.size(); i++){
        int from = costs[i][0];
        int to = costs[i][1];
        int value = costs[i][2];
        path[from].push_back(pair<int, int>(to, value));
        path[to].push_back(pair<int, int>(from, value));
    }
    
    return prim(0);
}
