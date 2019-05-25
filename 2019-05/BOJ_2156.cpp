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

#define MAX_N 10001

int wine[MAX_N], dp[MAX_N];
int n, ans;

int main() {
    cin>>n;
    rep(i, 1, n+1) cin>>wine[i];
    
    dp[1] = dp[2] = wine[1];
    dp[2]+= wine[2];
    ans = max(dp[1], dp[2]);
    rep(i, 3, n+1) {
        dp[i] = wine[i] + max(dp[i-2], dp[i-3] + wine[i-1]);
        dp[i] = max(dp[i], dp[i-1]);
    }
    
    cout<<dp[n]<<endl;
    return 0;
}