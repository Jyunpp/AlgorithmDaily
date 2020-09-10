// 20200910 21:48 ~ 21:56
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

int t, n;

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        if(n<=3) {
            cout<<-1<<endl;
            continue;
        }
        
        vector<int> ans;
        vector<int> l;
        vector<int> r;
        for(int i=3; i<=n; i+=2) l.pb(i);
        for(int i=6; i<=n; i+=2) r.pb(i);
        if(l.size()) for(int i=l.size()-1; i>=0; i--) ans.pb(l[i]);
        ans.pb(1);
        ans.pb(4);
        ans.pb(2);
        if(r.size()) for(int i=0; i<=r.size()-1; i++) ans.pb(r[i]);
        for(auto i : ans) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}