#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void moveOne(vector<vector<int>> &v, int from, int to) {
    vector<int> tmp;
    tmp.push_back(from);
    tmp.push_back(to);
    v.push_back(tmp);
}

void move(vector<vector<int>> &v, int n, int from, int to, int by) {
    // 원판이 1개일 경우, 하나만 움직이면 끝
    if (n == 1) moveOne(v, from, to);
    // 원판이 여러개일 경우
    else {
        move(v, n - 1, from, by, to); // n-1개 1에서 2로
        moveOne(v, from, to); // 1개 1에서 3으로
        move(v, n - 1, by, to, from); // n-1개 2에서 3으로
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    move(answer, n, 1, 3, 2); // from to by
    return answer;
}