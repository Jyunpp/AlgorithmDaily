// 20200903 20:36 ~ 20:40
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
        vector<int> v;
        rep(i, 1, n+1) {
            int a; cin>>a;
            v.pb(a);
        }

        int ans = 987654321;
        sort(v.begin(), v.end());
        for(int i=1; i<n; i++) {
            int diff = v[i]-v[i-1];
            ans = min(ans, diff);
        }
        
        cout<<ans<<endl;

    }
    return 0;
}