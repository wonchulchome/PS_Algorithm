#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> map;
    for(auto elem : completion) {
        if(map.end() == map.find(elem))
            map.insert(make_pair(elem, 1));
        else
            map[elem]++;
    }
    
    for(auto elem : participant){
        if(map.end() == map.find(elem)){
            answer = elem;
            break;
        } else {
            map[elem]--;
            if(map[elem] < 0) {
                answer = elem;
                break;
            }
        }
    }
    
    return answer;
}
