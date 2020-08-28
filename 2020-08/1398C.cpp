// 20200828 23:15 ~ 23:55
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
string s;

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>s;
        
        map<int, int> mp;
        mp[0] = 1;
        int ps = 0;
        int i=0;
        ll ans = 0;
        for(char ch : s) {
            i++;
            ps += int(ch - '0') - 1;
            ans += mp[ps];
            mp[ps]++;
        }

        cout<<ans<<endl;
    }

    return 0;
}