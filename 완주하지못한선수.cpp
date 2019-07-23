#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	unordered_map<string, int> participants;
	for (string name: participant) {
		++participants[name];
	}
	for (string name: completion) {
		--participants[name];
	}
	for (auto person: participants) {
		if (person.second > 0) return person.first;
	}
}

// #include <string>
// #include <algorithm>
// #include <vector>

// using namespace std;

// string solution(vector<string> participant, vector<string> completion) {
//     sort(participant.begin(), participant.end());
//     sort(completion.begin(), completion.end());
	
//     for(int i = 0; i < completion.size(); i++) {
//         if(participant[i] != completion[i]) 
//             return participant[i];
//     }
	
//     return participant[participant.size() - 1];
// }