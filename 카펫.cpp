// 유형 : 완전탐색

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int tmpX, tmpY;
    for (int i = 1; i<=brown; i++){
        for (int j = 1; j<=i; j++){
            if (i*j == red && ((i+2)*(j+2) - red == brown)){
                tmpX = i + 2;
                tmpY = j + 2;
                answer.push_back(tmpX);
                answer.push_back(tmpY);
                break; 
            }
        }
    }
    return answer;
}