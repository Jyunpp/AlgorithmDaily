// 20200910 21:16 ~ 21:47
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
        vector<int> mp(n+1, 0);
        vector<int> ps;
        ps.pb(0);
        // map<int, int> mp;
        int curr = 0;
        rep(i, 0, n) {
            int a;cin>>a;
            // v.pb(a);
            // mp[a]++;
            mp[a]++;
            curr+=a;
            ps.pb(curr);
        }
        
        int ans = 0;
        for(int i=2; i<=n; i++) {
            for(int j=0; j<=i-2; j++) {
                if(ps[i]-ps[j]>n) continue;
                else {
                    ans += mp[ps[i]-ps[j]];
                    mp[ps[i]-ps[j]] = 0;
                }
            }
        }
 
        cout<<ans<<endl;
    }
    return 0;
}