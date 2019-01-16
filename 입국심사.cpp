#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(int n, vector<int> times) {
    long long left = 1;
    long long right = 100000000000000;

    while (left <= right) {
        long long sum = 0;
        long long mid = (left + right) / 2;
        for (int i = 0; i < times.size(); i++) {
            sum += mid / times[i];
        }
        if (sum >= n) right = mid - 1;
        else left = mid + 1;
    }
    return left;
}