// 20200824 23:22 ~ 23:28
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

int t, n, k;

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>k;
        int ans = 0;
        vector<int> v[2];
        rep(i, 0, 2) {
            rep(j, 1, n+1) {
                int curr; cin>>curr;
                v[i].pb(curr);
                if (!i) ans+= curr;
            }
        }
        sort(v[0].begin(), v[0].end());
        sort(v[1].begin(), v[1].end(), greater<>());
        rep(i, 0, k) {
            if(v[0][i]<v[1][i]) ans += (v[1][i] - v[0][i]);
            else break;
        }
        cout<<ans<<endl;
    }

    return 0;
}