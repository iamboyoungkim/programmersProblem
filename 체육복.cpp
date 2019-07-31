#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n+1);
    
    // 처음엔 모두 1개 가지고 있음
    for (int i = 0; i<student.size(); i++) {
        student[i] = 1;
    }
    
    // 여벌옷 가진 사람
    for (auto r: reserve) {
        student[r] = 2;
    }

    // 잃어버린 사람
    for (auto l: lost) {
        student[l]--;
    }
    
    //  빌려주기
    for (int i = 1; i<n+1; i++) {
        if (student[i] == 0 && student[i-1] == 2) {
            student[i-1] = 1;
            student[i] = 1;
        }
        else if (student[i] == 0 && student[i+1] == 2 && i < n) {
            student[i+1] = 1;
            student[i] = 1;
        }
    }
    
//     for (int i = 1; i<student.size(); i++) {
//         cout << student[i];;
//     }
    
    for (auto s: student) {
        if (s > 0) answer++;
    }
    
    return answer-1;
}