// 20191211 01:00 ~ 01:55
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <map>
#include <set>
using namespace std;
 
#define sd(x) scanf(" %d", &x);
#define slld(x) scanf(" %lld", &x);
#define pb push_back
#define xx first
#define yy second
#define rep(i, l, r) for(int i=l; i<r; i++)
#define sortV(v, lambda) sort(v.begin(), v.end(), lambda)
#define powll(a, b) (ll) pow(a, b)
 
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
 
int n;
int a, b;
int edge[301][301];
int parent[301];
vector<int> edgeV[301];
int h[301];
int bfsVisited[301];
vector<int> order;
vector<int> ans;

int getLca(int a, int b) {
    // set h[a] <= h[b]
    if(h[a]>h[b]) {
        int temp = a;
        a = b;
        b = temp;
    }
    int pa = parent[a];
    int pb = parent[b];
    while(h[pa] != h[pb]) {
        pb = parent[pb];
    }
    while(pa != pb) {
        pa = parent[pa];
        pb = parent[pb];
    }
    // cout<<"geLca("<<a<<", "<<b<<") : "<<pa<<endl;
    return pa;
}

int main() {
    cin>>n;
    rep(i, 1, n+1) {
        edgeV[i] = vector<int>();
    }
    rep(i, 1, n) {
        cin>>a>>b;
        edge[a][b] = edge[b][a] = 1;
        edgeV[a].pb(b);
        edgeV[b].pb(a);
    }

    // set height
    queue<int> q;
    q.push(1);
    // int prev = -1;
    bfsVisited[1] = 1;
    int height = 1;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int curr = q.front();
            q.pop();
            h[curr] = height;
            for(int i : edgeV[curr]) {
                if (!bfsVisited[i]) {
                    bfsVisited[i] = 1;
                    q.push(i);
                }
            }
        }
        height++;
    }
    // rep(i, 1, n+1){
    //     cout<<"h["<<i<<"] : "<<h[i]<<endl;
    // }

    // set parent
    set<int> notLeaf;
    rep(i, 1, n+1) {
        for(int j : edgeV[i]) {
            if(h[i]-1 == h[j]) {
                parent[i] = j;
                notLeaf.insert(j);
                // cout<<"notLeaf : "<<j<<"///"<<"parent["<<i<<"] : "<<j<<endl;
            }
        }
    }

    int leafCnt = n - notLeaf.size();
    // cout<<"leafCnt : "<<leafCnt<<endl;
    int temp;
    rep(i, 1, leafCnt+1) {
        cin>>temp;
        order.pb(temp);
    }

    vector<int> order0ToRootExcludeOrder0;
    int ttemp = order[0];
    while(true) {
        ttemp = parent[ttemp];
        order0ToRootExcludeOrder0.pb(ttemp);
        if(ttemp == 1) break;
    }
    for(int i=order0ToRootExcludeOrder0.size()-1; i>=0; i--) {
        ans.pb(order0ToRootExcludeOrder0[i]);
    }

    int curr = order[0];
    // cout<<"nowcurr: "<<curr<<endl;
    for(int i = 1;  i <= order.size()-1; i++) {
        int next = order[i];
        int lca = getLca(curr, next);
        ans.pb(curr);
        while(true) {
            // cout<<"parent[curr] : "<<parent[curr]<<endl;
            curr = parent[curr];
            ans.pb(curr);
            // cout<<"curr : "<<curr<<endl;
            // cout<<"lca : "<<lca<<endl;
            // cin>>n;

            if(curr == lca) break;
        }
        vector<int> nextToLcaExcludeNext;
        int temp = next;
        while(true) {
            int p = parent[temp];
            nextToLcaExcludeNext.pb(p);
            if(p == lca) break;
            temp = p;
        }
        for(int j=nextToLcaExcludeNext.size()-1; j>=0; j--) {
            if (j == nextToLcaExcludeNext.size()-1) continue;
            ans.pb(nextToLcaExcludeNext[j]);
        }
        curr = next;
    }
    ans.pb(order[order.size()-1]);
    
    vector<int> orderLastToRootExcludeOrderLast;
    ttemp = order[order.size()-1];
    while(true) {
        ttemp = parent[ttemp];
        ans.pb(ttemp);
        if(ttemp == 1) break;
    }

    if(ans.size() != 2*n-1) {
        cout<<-1<<endl;
        return 0;
    }
    for(int i: ans) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}