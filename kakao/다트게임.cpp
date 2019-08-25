#include <string>
#include <iostream>
#include <vector>

using namespace std;

int num[3];
int bonus[3];

int solution(string dartResult) {
    int answer = 0;
    int idx = 0;
    
    for (int i = 0; i<3; i++) {
        bonus[i] = 1;
    }
    
    for (int i = 0; i<dartResult.size(); i++) {
        if (dartResult[i] - '0' >= 0 && dartResult[i] - '0' < 10) {
            if (num[idx] == 0) num[idx] = dartResult[i] - '0';
            else num[idx] = 10;
        }
        
        else if(dartResult[i] == 'S'){
            idx++;
        }
        
        else if(dartResult[i] == 'D'){
            num[idx] *= num[idx];
            idx++;
        }
        
        else if(dartResult[i] == 'T'){
            num[idx] = num[idx]*num[idx]*num[idx];
            idx++;
        }
        
        else if(dartResult[i] == '#'){
             bonus[idx-1] *= -1;
        }
        
        else if(dartResult[i] == '*'){
             bonus[idx-1] *= 2;
             bonus[idx-2] *= 2;
        }
    }
    
    for (int i = 0; i<3; i++) {
        answer += num[i] * bonus[i];
    }
    
    return answer;
}