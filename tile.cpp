#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

long long solution(int n){
    
    long long answer = 0;
    
    long long arr[81];
    arr[0] = 1;
    arr[1] = 1;
    
    for (int i = 2; i<80; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    if (n == 1) answer = 4;
    else answer = arr[n-1]*4 + arr[n-2]*2;
    
    return answer;
}