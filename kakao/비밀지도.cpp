#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer(n);
    
	for (int i = 0; i < n; i++) {
        answer[i].assign(" ", n);
		int tmp = arr1[i] | arr2[i];
        
        for (int j = n-1; j>=0; j--) {
            if (tmp % 2 == 1) answer[i][j] = '#';
            else answer[i][j] = ' ';
            tmp /= 2;
        }
	}
	return answer;
}