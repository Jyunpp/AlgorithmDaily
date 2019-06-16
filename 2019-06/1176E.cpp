// 20190616 18:47 ~ 19:23
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

int t, n, m;

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>m;
        vector<int> ansV;
        vector<vector<int>> v(n+1);
        vector<bool> visited(n+1);
        rep(i, 1, n+1) visited[i] = false;
        rep(i, 0, m) {
            int a, b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }

        queue<int> q;
        bool finished = false;
        rep(ii, 1, n+1) {
            if(finished) break;
            if(visited[ii]) continue;
            q.push(ii);
            ansV.pb(ii);
            visited[ii] = true;
            for(auto i : v[ii]) visited[i] = true;
            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                for(auto i : v[curr]) {
                    for(auto j : v[i]) {
                        if(!visited[j]) {
                            q.push(j);
                            ansV.pb(j);
                            visited[j] = true;
                            for(auto k : v[j]) visited[k] = true;
                        }
                    }
                }
            }
            if(ansV.size() <= n/2) {
                cout<<ansV.size()<<endl;
                for(auto i : ansV) cout<<i<<" ";
                cout<<endl;
                finished = true;
            } else {
                ansV.clear();
                rep(i, 1, n+1) visited[i] = false;
            }
        }
    }
    return 0;
}