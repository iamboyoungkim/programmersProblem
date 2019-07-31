#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int size = people.size();
    sort(people.begin(), people.end());
    
    int lpos = 0;
    int rpos = size - 1;
    
    while(lpos < rpos) {
        if (people[lpos] + people[rpos] <= limit) {
            answer++;
            lpos++;
            rpos--;
        }
        else rpos--;
    }
    return size - answer;
}