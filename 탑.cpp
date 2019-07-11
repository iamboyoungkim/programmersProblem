#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    // 처음 탑은 무조건 0
    answer.push_back(0);
    // 두번째 탑부터 순회하면서 확인
    for (int i = 1; i<heights.size(); i++){
        int compare = heights[i];
        int pos = i;
        for (int j = i-1; j>=0; j--) {
            if (heights[j] > compare) {
                compare = heights[j];
                pos = j+1;
                break;
            }
        }
        if (compare != heights[i]) answer.push_back(pos);
        else answer.push_back(0);    
    }
    return answer;
}