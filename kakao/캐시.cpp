#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	list<string> cache;

	if (cacheSize == 0) return cities.size() * 5;
    
	for (int i = 0; i < cities.size(); i++) {
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        
        // list에 값이 있는지 검사
        // 있으면
		if (find(cache.begin(), cache.end(), cities[i]) != cache.end()) {
            // 캐시 안에 있는 값 활용시 : 제거하고 다시 뒤로 보냄
            answer++;
			cache.remove(cities[i]);
			cache.push_back(cities[i]);
		}
		else {
			answer += 5;
            // 캐시 사이즈 넘으면
			if (cache.size() >= cacheSize) cache.pop_front();
			cache.push_back(cities[i]);
		}
	}
	return answer;
} 