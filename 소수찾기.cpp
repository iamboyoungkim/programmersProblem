#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

bool isPrime[100000000];

// 에라토스테네스의 체 방식 사용
void findPrimes() {
    for (int i = 2; i<=9999999; i++){
        isPrime[i] = true;
    }
    for (int i = 2; i<=sqrt(9999999); i++){
        if (isPrime[i]) {
            for (int j = i+i; j<=9999999; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

int solution(string numbers){
    findPrimes();
    sort(numbers.begin(), numbers.end());
    set<int> primes;
    do {
        for (int i = 1; i<=numbers.size(); i++) {
            string sub = numbers.substr(0, i);
            if (isPrime[stoi(sub)]) primes.insert(stoi(sub));
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    return primes.size();
}
