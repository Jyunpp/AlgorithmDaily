// 20190610 
// problem : https://www.welcomekakao.com/learn/courses/30/lessons/42890
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<string>> rel;
int r, c;
vector<int> v;

bool check(int select) {
    vector<int> idxs;
    int i=0;
    while(select) {
        if(select&1) idxs.push_back(i);
        i++;
        select >>=1;
    }
    bool ret = true;
    for(int i=0; i<rel.size(); i++) {
        for(int j=i+1; j<rel.size(); j++) {
            string strI = "";
            string strJ = "";
            for(auto k : idxs) strI += rel[i][k];
            for(auto k : idxs) strJ += rel[j][k];
            if(strI == strJ) {
                ret = false;
                break;
            }
        }
        if(!ret) break;
    }
    return ret;
}

void recur(int currIdx, bool currSelect, int totalSelectUntilLast) {
    int totalSelectUntilCurr = (totalSelectUntilLast<<1) + currSelect;
    if(currIdx == c) {
        if(check(totalSelectUntilCurr)) v.push_back(totalSelectUntilCurr);
        return;
    } else {
        recur(currIdx+1, true, totalSelectUntilCurr);
        recur(currIdx+1, false, totalSelectUntilCurr);
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    rel = relation;
    r = rel.size();
    c = rel[0].size();
    recur(0, 0, 0);
    int duple = 0;
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(((v[i]&v[j]) == v[i]) || ((v[i]&v[j]) == v[j])) {
                duple++;
                break;
            }
        }
    }
    answer = v.size() - duple;
    return answer;
}

// for test
int main() {
    vector<vector<string>> relation{{"100","ryan","music","2"},
                                    {"200","apeach","math","2"},
                                    {"300","tube","computer","3"},
                                    {"400","con","computer","4"},
                                    {"500","muzi","music","3"},
                                    {"600","apeach","music","2"}};
    cout<<"result : "<<solution(relation)<<endl;
    return 0;
}