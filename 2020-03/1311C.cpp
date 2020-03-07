// 20200307 20:40 ~ 
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
int ans [int('z')-int('a')+1];

int main() {
    cin>>t;
    rep(T, 0, t) {
        rep(i, 0, int('z')-int('a')+1) ans[i] = 0;
        
        cin>>n>>m;
        string s; cin>>s;
        vector<int> v;
        rep(i, 0, m) {
            int a; cin>>a;
            v.pb(a);
        }
        sort(v.begin(), v.end());
        
        rep(i, 1, n+1) {
            char ch = s[i-1];
            int sz = 1;
            int lbIdx =lower_bound(v.begin(), v.end(), i) - v.begin();
            sz += (v.size() - lbIdx);
            
            ans[ch-'a'] += sz;
        }

        rep(i, 0, int('z')-int('a')+1) cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}