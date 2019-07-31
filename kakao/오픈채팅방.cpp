#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 석호님 코드 참고해서 고쳤습니당

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> userInfo; // uid, nickname
    vector<pair<string, string>> log;
    
    for(int i = 0; i < record.size(); i++) {
        string uid, nickname;
 
        if(record[i].find("Enter") == 0) {
            uid = record[i].substr(6, record[i].substr(6).find(" "));
            nickname = record[i].substr(6).substr((record[i].substr(6)).find(" ")+1);
            userInfo[uid] = nickname;
            log.push_back({uid, "님이 들어왔습니다."});
        }

        else if(record[i].find("Leave") == 0) {
            uid = record[i].substr(6, record[i].substr(6).find(" "));
            log.push_back({uid, "님이 나갔습니다."});
        }
        else if(record[i].find("Change") == 0) {
            uid = record[i].substr(7, record[i].substr(7).find(" "));
            nickname = record[i].substr(7).substr((record[i].substr(7)).find(" ")+1);
            userInfo[uid] = nickname;
        }
    }
    
    for (int i = 0; i<log.size(); i++) {
        answer.push_back(userInfo[log[i].first] + log[i].second);
    }
    return answer;
}