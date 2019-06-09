// 20190609 18:20 ~ 18:40
// problem : https://www.welcomekakao.com/learn/courses/30/lessons/42889
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int, int> stageToFailUsers;
    vector<pair<int, double>> stageToFailureRate;
    
    for(int i=1; i<=N; i++) stageToFailUsers[i] = 0;
    for(auto i : stages) stageToFailUsers[i]++;
    
    int remainUsers = stages.size();
    for(auto i : stageToFailUsers) {
        int currentStage = i.first;
        if(currentStage > N) continue;
        int currentStageUsers = i.second;
        
        double failureRate;
        if(remainUsers == 0) {
            failureRate = 0;
        } else {
            failureRate = ((double)currentStageUsers)/((double)(remainUsers));
        }
        stageToFailureRate.push_back({currentStage, failureRate});

        remainUsers -= currentStageUsers;
    }
    sort(stageToFailureRate.begin(), stageToFailureRate.end(), [](pair<int, double> a, pair<int, double> b){
        return a.second != b.second ? a.second > b.second : a.first < b.first;
    });
    for(auto i : stageToFailureRate) {
        answer.push_back(i.first);
    }
    return answer;
}

// for test
// int main() {
//     vector<int> stagesEx1{2, 1, 2, 6, 2, 4, 3, 3};
//     vector<int> stagesEx2{4, 4, 4, 4, 4};
//     vector<int> result;
    
//     result = solution(5, stagesEx1);
//     for(auto i : result) cout<<i<<" ";
//     cout<<endl;
    
//     result = solution(4, stagesEx2);
//     for(auto i : result) cout<<i<<" ";
//     cout<<endl;

//     return 0;
// }