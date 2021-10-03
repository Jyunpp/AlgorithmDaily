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
        
        auto cmp = [](P a, P b){return a.yy<b.yy;};
        priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);
        for(int i=1; i<=n; i++) {
            int a; cin>>a;
            if (a>0) pq.push({i, a});
        }

        vector<P> ans;
        while(pq.size()>=2) {
            P a = pq.top(); pq.pop();
            P b = pq.top(); pq.pop();
            ans.pb({a.xx, b.xx});
            a.yy--;
            b.yy--;
            if(a.yy>0) pq.push(a);
            if(b.yy>0) pq.push(b);
        }
        
        cout<<ans.size()<<endl;
        for(auto i: ans) {
            cout<<i.xx<<" "<<i.yy<<endl;
        }
    }
}