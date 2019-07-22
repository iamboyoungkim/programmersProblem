#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    int strike, ball;
    
    for (int i = 123; i<=987; i++) {
        string num = to_string(i);
        // 가능하지 않은 숫자 제외
        if (num[0] == num[1] || num[1] == num[2] || num[2] == num[0]) continue;
        if (num[0] == '0' || num[1] == '0' || num[2] == '0') continue;
        
        bool isMatched = true;
        for (int j = 0; j<baseball.size(); j++) {
            strike = 0;
            ball = 0;
            for (int x = 0; x<3; x++) {
                for (int y = 0; y<3; y++) {
                    string num2 = to_string(baseball[j][0]);
                    // 스트라이크
                    if (x == y && num[x] == num2[y] ) {
                        strike++;
                        continue;
                    }
                    // 볼
                    else if (x != y && num[x] == num2[y] ) {
                        ball++;
                        continue;
                    }
                }
            }
            if (strike != baseball[j][1] || ball != baseball[j][2]) 
                isMatched = false;
        }
        if (isMatched) answer++;
    }
    return answer;
}