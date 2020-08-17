// 20200817 02:55 ~ 21:45 ~ 22:53
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

vector<int> w, cnt;
vector<vector<P>> g;
int t, n;
ll s;

ll getDiff(int i) {
    return w[i] * 1ll * cnt[i] - (w[i] / 2) * 1ll * cnt[i];
}

void dfs(int v, int prev = -1) {
    if(g[v].size() == 1 && prev != -1) cnt[prev] = 1;
    for(auto i : g[v]) {
        int to = i.xx;
        int idx = i.yy;
        if(idx == prev) continue;
        dfs(to, idx);
        if(prev != -1) cnt[prev] += cnt[idx];
    }
}

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>s;
        w = cnt = vector<int>(n-1);
        g = vector<vector<P>>(n);
        rep(i, 0, n-1) {
            int x, y;
            cin>>x>>y>>w[i];
            --x, --y;
            g[x].pb({y, i});
            g[y].pb({x, i});
        }

        dfs(0);
        set<pair<ll, int>> st;
        ll curr = 0;
        rep(i, 0, n-1) {
            st.insert({getDiff(i), i});
            curr += w[i] * 1ll * cnt[i];
        }

        int ans = 0;
        while(curr > s) {
            int idx = st.rbegin()->yy;
            st.erase(prev(st.end()));
            curr -= getDiff(idx);
            w[idx] /= 2;
            st.insert({getDiff(idx), idx});
            ans++;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}