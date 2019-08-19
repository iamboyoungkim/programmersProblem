#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 소문자로 만들기
void makeLowerCase(string &str) {
    for (int i = 0; i<str.length(); i++) {
        str[i] = tolower(str[i]);
    }
}

// 특수문자, 숫자 필터링
bool filter (string &str) {
    for (int i = 0; i<str.length(); i++)
        if (str[i] < 'a' || str[i] > 'z') return false;
    return true;
}

// 두글자씩 끊어서 벡터에 넣기
vector<string> divideStr(string &str) {
    vector<string> tmpV;
    for (int i = 0; i<str.length() - 1; i++) {
        string tmp = str.substr(i, 2);
        if (filter(tmp)) tmpV.push_back(tmp);
    }
    return tmpV;
}

int solution(string str1, string str2) {
    // 소문자로 변경
    makeLowerCase(str1);
    makeLowerCase(str2);

    // 두글자씩 끊기
    vector<string> str1V = divideStr(str1);
    vector<string> str2V = divideStr(str2);
    
    int sameCnt = 0;
    int allCnt = str1V.size() + str2V.size();
    
    for (int i = 0; i < str1V.size(); i++){
        for (int j = 0; j < str2V.size(); j++){
            if (str1V.at(i).compare(str2V.at(j)) == 0){
                sameCnt++;
                str2V.erase(str2V.begin() + j);
                break;
            }
        }
    }
    float interCnt = allCnt - sameCnt;
    float answer = 65536;
    
    if (sameCnt == 0) {
        if (allCnt == 0) answer = 65536;
        else answer = 0;
    }
    else if (sameCnt > 0){
        float f = (float)sameCnt / interCnt;
        answer = f * 65536;
    }
    
    return (int)answer;
}