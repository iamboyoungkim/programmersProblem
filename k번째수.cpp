// 유형 : 정렬

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int> > commands) {
    vector<int> answer;
    
    for(auto x: commands){
        int start = x[0];
        int end = x[1];
        int pick = x[2];
        
        vector<int> tmp;
        for(int i = start-1; i<end; i++){
            tmp.push_back(array[i]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[pick-1]);
    }
    return answer;
}