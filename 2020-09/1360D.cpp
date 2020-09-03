// 20200903 20:46 ~ 20:55 ~ 21:05
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

int t;
ll n, k;

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>k;
        
        vector<int> divs;
        for(int i=1; i*i<=n; i++) {
            if(n%i==0) {
                if (i<=k) divs.pb(i);
                if (n/i <= k) divs.pb(n/i);
            }
        }
        sort(divs.begin(), divs.end());
        
        ll ans;
        if (divs.size() == 0) ans = n;
        else {
            ans = n/divs[divs.size()-1];
        }
        cout<<ans<<endl;
    }
    return 0;
}