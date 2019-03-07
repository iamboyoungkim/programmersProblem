#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    int strike = 0;
    int ball = 0;
    bool flag = true;
    
    for (int i = 123; i<=987; i++){
        string num = to_string(i);
        if (num[0] == num[1] || num[1] == num[2] || num[0] == num[2])
            continue;
        if (num[0] == '0' || num[1] == '0' || num[2] == '0')
            continue;
        flag = true;
        for (int j = 0; j<baseball.size(); j++){
            strike = 0;
            ball = 0;
            for (int x = 0; x<3; x++){
                for (int y = 0; y<3; y++){
                    string num2 = to_string(baseball[j][0]);
                    if (x == y && num[x] == num2[y]) {
                        strike++;
                        continue;
                    }
                    if (x != y && num[x] == num2[y]) {
                        ball++;
                        continue;
                    }
                }
            }
            if (strike != baseball[j][1] || ball != baseball[j][2]){
                flag = false;
                break;
            }
        }
        if (flag == true) answer++;
    }
    return answer;
}