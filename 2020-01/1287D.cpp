// 20200113 
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
 
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
 
vector<int> child[2001];
int root;
 
int n;
int c[2001];
int ans[2001];
  
vector<int> dfs(int now) {
    vector<int> ret;
    for(int x : child[now]) {
        vector<int> fromX = dfs(x);
        for(int y : fromX) {
            ret.pb(y);
        }
    }

    if(c[now] > ret.size()) {
        cout<<"NO"<<endl;
        exit(0);
    }
    ret.insert(ret.begin() + c[now], now);
    return ret;
}
 
int main() {
    cin>>n;
    
    rep(i, 1, n+1) {
        int p;
        cin>>p>>c[i];
        if(p==0) root = i;
        else child[p].pb(i);
    }
    
    vector<int> order = dfs(root);
    rep(i, 0, order.size()) ans[order[i]] = i+1;
    cout<<"YES"<<endl;
    rep(i, 1, n) cout<<ans[i]<<" ";
    cout<<ans[n]<<endl;
    return 0;
}
