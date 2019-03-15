#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int isPrime[100000000];

void eratoesthenes() {
    for (int i = 2; i<=9999999; i++){
        isPrime[i] = 1;
    }
    for (int i = 2; i<=sqrt(9999999); i++){
        if (isPrime[i]) {
            for (int j = i+i; j<=9999999; j+=i){
                isPrime[j] = 0;
            }
        }
    }
}

int solution(string numbers){
    eratoesthenes();
    int answer = 0;
    int size = numbers.size();
    vector<int> v(size);
    for (int i = 0; i<size; i++){
        v[i] = 1;
        sort(numbers.begin(), numbers.end());
        do {
            int tmp = 0;
            int j = 1;
            for (int k = 0; k<size; k++){
                if (v[k] == 1){
                    tmp += (numbers[k] - '0') * j;
                    j *= 10;
                }
            }
            if (isPrime[tmp] == 1){
                cout << tmp << '\n';
                isPrime[tmp] = 2;
                answer++;
            }
        } while(next_permutation(numbers.begin(), numbers.end()));
    }
    return answer;
}