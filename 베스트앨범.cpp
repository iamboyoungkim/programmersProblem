#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

/* 
- 문제 풀이 방법
1. 장르가 같은 음악들의 플레이 총 횟수 구함
2. 총 플레이 많은 순으로 sort
3. 가장 큰횟수, 2번째큰횟수 저장
 */

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<int> plays2;
    vector<string> genres2;
    vector<int> tmp;
    vector<string> tmp2;
    int tmp3;
    string tmp4;
    int max = -1;
    int max2 = -1;
    vector<int> cnt = { -1, -1 };
    
    for(int z = 0; z < plays.size(); z++){
        plays2.push_back(plays[z]);
        genres2.push_back(genres[z]);
    }
    
    for(int i = 0; i < plays.size(); i++){
        tmp.push_back(plays[i]);
        tmp2.push_back(genres[i]);
        for(int j = i+1; j<plays.size(); j++){
            if(genres[i].compare(genres[j]) == 0){
                tmp[i] += plays[j];
                plays.erase(plays.begin()+j);
                genres.erase(genres.begin()+j);
                j--;
            }
        }
    }
    
    for(int a = 0; a < tmp.size(); a++){
        for(int b = a+1; b < tmp.size(); b++){
            if(tmp[a] < tmp[b]){
                tmp3 = tmp[a];
                tmp4 = tmp2[a];
                tmp[a] = tmp[b];
                tmp2[a] = tmp2[b];
                tmp[b] = tmp3;
                tmp2[b] = tmp4;
            }
        }
    }
    
    for(int i=0; i<tmp.size(); i++){
        for(int j=0; j<plays2.size(); j++){
            if(tmp2[i].compare(genres2[j]) == 0 && max == plays2[j] && max2 < max){
                max2 = max;
                cnt[1] = j;
            }
            if(tmp2[i].compare(genres2[j]) == 0 && max < plays2[j]){
                max2 = max;
                max = plays2[j];
                cnt[1] = cnt[0];
                cnt[0] = j;
            }
            if(tmp2[i].compare(genres2[j]) == 0 && max2 < plays2[j] && max > plays2[j]){
                max2 = plays2[j];
                cnt[1] = j;
            }
        }
        if(cnt[1] == -1){
            answer.push_back(cnt[0]);
        }
        else if(cnt[1] > -1){
            answer.push_back(cnt[0]);
            answer.push_back(cnt[1]);
        }
        cnt[0] = -1;
        cnt[1] = -1;
        max = 0;
    }
    return answer;
}