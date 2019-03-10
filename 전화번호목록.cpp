#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 1; i<phone_book.size(); i++){
        int prevSize = phone_book[i-1].size();
        if (phone_book[i-1] == phone_book[i].substr(0, prevSize)){
            answer = false;
            break;
        }
    }
    return answer;
}