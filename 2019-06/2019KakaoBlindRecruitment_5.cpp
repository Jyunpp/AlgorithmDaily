// 20190613 01:20 ~ 
// problem : https://www.welcomekakao.com/learn/courses/30/lessons/42892
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define pb push_back
#define xx first
#define yy second
#define rep(i, l, r) for(int i=l; i<r; i++)

int edge[2][10001]; // i==0 : left, i==1: right // edge[i][j] : (node j)'s edges to left(or right) child // j in (0~9999)
vector<int> ret[2];

void preOrder(int idx) {
    ret[0].pb(idx+1);
    if(edge[0][idx] != -1) preOrder(edge[0][idx]);
    if(edge[1][idx] != -1) preOrder(edge[1][idx]);
}

void postOrder(int idx) {
    if(edge[0][idx] != -1) postOrder(edge[0][idx]);
    if(edge[1][idx] != -1) postOrder(edge[1][idx]);
    ret[1].pb(idx+1);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    pair<int, int> childBoundary[10001]; // (node i)'s child's x cordinate is in (childBoundary[i].xx ~ childBoundary[i].yy) // i in (0~9999)
    vector<int> nodesInH[10001]; // nodesInH[i] : node idxs at height i // H is compressed to 1~10000
    // int parent[10001]; // parent[i] : (node i)'s parent node idx // i, idx in (0~9999)
    vector<pair<int, pair<int, int>>> v; // {idx , {x, y}}
    
    // prepare {idx, {x, y}} order by y desc order by x asc
    rep(i, 0, nodeinfo.size()) {
        v.pb({i, {nodeinfo[i][0], nodeinfo[i][1]}});
    }
    sort(v.begin(), v.end(), [](pair<int, pair<int, int>>a, pair<int, pair<int, int>>b){
        return a.yy.yy != b.yy.yy ? a.yy.yy > b.yy.yy : a.yy.xx < b.yy.xx;
    });
    // fiil nodesInH
    int previous = -1;
    int currH = 0;
    for(auto i : v) {
        if(previous != i.yy.yy) {
            currH++;
            previous = i.yy.yy;
        }
        nodesInH[currH].pb(i.xx); // filled nodesInH[currH] order by x asc
    }
    int h = currH;
    
    rep(i, 0, 2) rep(j, 0, 10000) edge[i][j] = -1;

    childBoundary[nodesInH[1][0]] = {-1, 100001}; // root node has infinite boundary
    rep(k, 1, h) {
        for(auto i : nodesInH[k]) {
            for(auto j : nodesInH[k+1]) {
                if(childBoundary[i].xx < nodeinfo[j][0] && nodeinfo[j][0] < nodeinfo[i][0]) {
                    edge[0][i] = j;
                    childBoundary[j].xx = childBoundary[i].xx;
                    childBoundary[j].yy = nodeinfo[i][0];
                }
                if(nodeinfo[i][0] < nodeinfo[j][0] && nodeinfo[j][0] < childBoundary[i].yy) {
                    edge[1][i] = j;
                    childBoundary[j].xx = nodeinfo[i][0];
                    childBoundary[j].yy = childBoundary[i].yy;
                }
            }
        }
    }
    preOrder(nodesInH[1][0]);
    postOrder(nodesInH[1][0]);
    answer.pb(ret[0]);
    answer.pb(ret[1]);
    return answer;
}

// for test
int main() {
    vector<vector<int>> nodeinfo;
    nodeinfo.pb(vector<int>{5,3});
    nodeinfo.pb(vector<int>{11,5});
    nodeinfo.pb(vector<int>{13,3});
    nodeinfo.pb(vector<int>{3,5});
    nodeinfo.pb(vector<int>{6,1});
    nodeinfo.pb(vector<int>{1,3});
    nodeinfo.pb(vector<int>{8,6});
    nodeinfo.pb(vector<int>{7,2});
    nodeinfo.pb(vector<int>{2,2});
    for(auto i : solution(nodeinfo)) {
        for(auto j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}