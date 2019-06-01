// 20190601 21:29 ~ 21:32
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
ll dp[10];

int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		rep(i, 0, 10) dp[i] = 1;
		rep(i, 2, n+1){
			rep(j, 0, 10) {
				ll curr = 0;
				rep(k, j, 10) curr+=dp[k];
				dp[j] = curr;
			}
		}
		ll ret = 0;
		rep(i, 0, 10) ret += dp[i];
		cout<<ret<<endl;
	}
	return 0;
}