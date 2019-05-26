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

#define MAX_N 100001

int arr[2][MAX_N];
int dp[2][MAX_N];
int tc, n;

int main() {
    cin>>tc;
    while(tc--) {
        cin>>n;
        rep(i, 0, 2) rep(j, 1, n+1) cin>>arr[i][j];
        
        dp[0][1] = arr[0][1];
        dp[1][1] = arr[1][1];
        dp[0][2] = dp[1][1] + arr[0][2];
        dp[1][2] = dp[0][1] + arr[1][2];
        rep(i, 3, n+1) {
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + arr[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + arr[1][i];
        }
        cout<<max(dp[0][n], dp[1][n])<<endl;
    }
    return 0;
}