// 20200120
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
using namespace std;
 
#define sd(x) scanf(" %d", &x);
#define slld(x) scanf(" %lld", &x);
#define pb push_back
#define xx first
#define yy second
#define rep(i, l, r) for(int i=l; i<r; i++)
#define sortV(v, lambda) sort(v.begin(), v.end(), lambda)
#define powll(a, b) (ll) pow(a, b)

const int INF = 1e9;
int n;
vector<int> arr;
vector<int> ans;
vector<vector<int>> g;

void bfs(const vector<int> & start, const vector<int> &end) {
    vector<int> d(n, INF);
    queue<int> q;
    for (auto i: start) {
        d[i] = 0;
        q.push(i);
    }
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for (auto to : g[curr]) {
            if(d[to] == INF) {
                d[to] = d[curr] + 1;
                q.push(to);
            }
        }
    }
    for(auto i : end) {
        if (d[i] != INF) ans[i] = d[i];
    }
}

int main() {
    cin>>n;
    arr = vector<int>(n);
    g = vector<vector<int>>(n);
    vector<int> even, odd;
    
    rep(i, 0, n) {
        cin>>arr[i];
        if (arr[i]&1) odd.pb(i);
        else even.pb(i);
    }

    rep(i, 0, n) {
        int l = i - arr[i];
        int r = i + arr[i];
        if (l >= 0) g[l].pb(i);
        if (r < n) g[r].pb(i);
    }

    ans = vector<int>(n, -1);
    bfs(odd, even);
    bfs(even, odd);
    for(auto i : ans) cout<<i<<" ";
    cout<<endl;
    return 0;
}