#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    long long arr[81];
    arr[0] = 1;
    arr[1] = 1;
    
    for (int i = 2; i<N; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    answer = arr[N-1] * 4 + arr[N-2] * 2;
    return answer;
}
