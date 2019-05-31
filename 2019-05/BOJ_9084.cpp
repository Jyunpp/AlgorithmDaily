// 20190531 01:26 ~ 
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

int t, n, m;
int arr[21];
int dp[10001];

int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		rep(i, 1, n+1) cin>>arr[i];
		cin>>m;
		
		rep(i, 1, 10001) dp[i] = 0;
		dp[0] = 1;
		rep(i, 1, n+1) {
			for(int j=arr[i]; j<=m; j++){
				dp[j] += dp[j-arr[i]];
			}
		}
		cout<<dp[m]<<endl;
	}
	return 0;
}