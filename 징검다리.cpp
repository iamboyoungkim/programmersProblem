#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());

    int lo = 0, hi = distance;
    for(int i = 0; i<100; i++){
        int mid = (lo + hi) / 2;
        int cnt = 0;
        int limit = rocks[0];
        for (int j = 1; j<rocks.size(); j++){
            if (rocks[j] - limit < mid) cnt++;
            else limit = rocks[j];
        }
        if (cnt > n) hi = mid;
        else lo = mid;
    }
    return lo;
}
