// 20200907 22:45 ~ 
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

int n, k;
string s, t;

int main() {
    cin>>n>>k>>s>>t;
    //dp[x][i][j] : considering only left x digits, replace count i, met t[0] count j
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -987654321)));
    dp[0][0][0] = 0;
    for(int x=0; x<n; x++) {
        for(int i=0; i<=k; i++) {
            for(int j=0; j<=n; j++) {
                if(dp[x][i][j] == -987654321) continue;
                int e0 = s[x] == t[0];
                int e1 = s[x] == t[1];
                int e01 = t[0] == t[1];
                dp[x+1][i][j+e0] = max(dp[x+1][i][j+e0], dp[x][i][j] + (e1?j:0));

                if (i<k) {
                    dp[x+1][i+1][j+1] = max(dp[x+1][i+1][j+1], dp[x][i][j] + (e01?j:0));
                    dp[x+1][i+1][j+e01] = max(dp[x+1][i+1][j+e01], dp[x][i][j] + j);
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<=k; i++) {
        for(int j=0; j<=n; j++) {
            ans = max(ans, dp[n][i][j]);
        }
    }
    cout<<ans<<endl;

    return 0;
}