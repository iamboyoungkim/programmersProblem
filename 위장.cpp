#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> um;

    for(auto c : clothes) {
        auto it = um.find(c[1]);
        if(it == um.end()) um.emplace(c[1], 1);
        else ++it->second;
    }
    for(auto u : um) {
        answer *= u.second + 1;
    }
    answer -= 1;
    return answer;
}