// 20200510
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

int t, n, k, p;
int ps[51][31]; // N, K
ll dp[51][1501]; // N, x

int main() {
    cin>>t;
    
    rep(T, 1, t+1) {
        cin>>n>>k>>p;

        rep(i, 1, n+1) {
            rep(j, 1, k+1) {
                cin>>ps[i][j];
                ps[i][j] += ps[i][j-1];
            }
        }

        rep(i, 1, n+1) {
            rep(j, 0, p+1) {
                dp[i][j] = 0;
                rep(x, 0, min(j, k)+1) {
                    dp[i][j] = max(dp[i][j], ps[i][x] + dp[i-1][j-x]);
                }
            }
        }

        cout<<"Case #"<<T<<": "<<dp[n][p]<<endl;
    }

    return 0;
}