// 20191210 
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
 
int edge[301][301];
int deg[301];
int order[301];
int n, leaf;
int a, b;
vector<int> ans;
vector<int> path[301][301];
vector<int>::iterator iter;
 
int main() {
    cin>>n;
    rep(i, 1, n) {
        cin>>a>>b;
        edge[a][b] = edge[b][a] = 1;
        path[a][b].pb(a);
        path[a][b].pb(b);
        path[b][a].pb(b);
        path[b][a].pb(a);
        deg[a]++;
        deg[b]++;
    }
    
    rep(i, 2, n+1) leaf += (deg[i] == 1);
    rep(i, 1, leaf+1) cin>>order[i];
    order[0] = order[leaf+1] = 1;
 
    rep(k, 1, n+1) {
        rep(i, 1, n+1) {
            if (i==k) continue;
            rep(j, 1, n+1) {
                if (i==j || k==j) continue;
                if (edge[i][k] && edge[k][j] && !edge[i][j]) {
                    edge[i][j] = 1;
                    path[i][j].insert(path[i][j].end(), path[i][k].begin(), path[i][k].end());
                    path[i][j].insert(path[i][j].end(), path[k][j].begin()+1, path[k][j].end());
                }
            }
        }
    }
 
    ans.pb(1);
    rep(i, 0, leaf+1) {
        ans.insert(ans.end(), path[order[i]][order[i+1]].begin()+1, path[order[i]][order[i+1]].end());
        if (ans.size() > 2*n-1) {
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}