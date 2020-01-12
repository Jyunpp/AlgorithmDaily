// 20200112
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

int n;
int dp[101][101][101][2];
int arr[101];

int recur(int pos, int zero, int one, int last) {
    if (one < 0 || zero < 0) return 1e9;
    if (pos == n+1) return 0;
    
    int &ret = dp[pos][zero][one][last];
    if (ret != -1) return ret;

    ret = 1e9;
    if (arr[pos]) {
        ret = recur(pos+1, zero, one, arr[pos]&1) + (last != (arr[pos]&1));
    } else {
        ret = min(recur(pos+1, zero-1, one, 0) + (last == 1), recur(pos+1, zero, one-1, 1) + (last == 0));
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin>>n;
    rep(i, 1, n+1) cin>>arr[i];

    int zero = n/2;
    int one = n-zero;
    rep(i, 1, n+1) {
        if(arr[i]) {
            if(arr[i]&1) one--;
            else zero--;
        }
    }
    int ans = min(recur(1, zero, one, 0), recur(1, zero, one, 1));
    cout<<ans<<endl;
    return 0;
}