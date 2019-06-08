// 20190608
// problem : https://www.welcomekakao.com/learn/courses/30/lessons/42888
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> uidToName;
    
    for(auto i : record) {
        string command = i.substr(0, i.find(" "));
        string uidAndName = i.substr(i.find(" ")+1);
        string uid = uidAndName.substr(0, uidAndName.find(" "));
        string currName = uidAndName.substr(uidAndName.find(" ")+1);
        if(command == "Leave") continue;
        uidToName[uid] = currName;
    }
    for(auto i : record) {
        string command = i.substr(0, i.find(" "));
        string uidAndName = i.substr(i.find(" ")+1);
        string uid = uidAndName.substr(0, uidAndName.find(" "));
        if(command == "Change") continue;
        answer.push_back(uidToName[uid] + "님이 " + (command=="Enter"?"들어왔":"나갔") + "습니다.");
    }
    // for debug
    // for(auto i : answer) {
    //     cout<<i<<endl;
    // }
    return answer;
}

// for debug
// int main() {
//     vector<string> record{"Enter uid1234 Muzi", 
//                         "Enter uid4567 Prodo",
//                         "Leave uid1234",
//                         // "Enter uid1234 Prodo",
//                         "Change uid4567 Ryan"};
//     solution(record);
// }