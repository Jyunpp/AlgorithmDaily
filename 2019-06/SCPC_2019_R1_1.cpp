// 20190621 18:15 ~ 18:26
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

ll dp[1000001];
ll ps[1000001];

ll fillDp(int idx) {
	ll &ret = dp[idx];
	if(dp[idx] != -1) return ret;
	if(idx%2 == 0) return ret = 1 + fillDp(idx/2);
	return ret = 1 + fillDp(idx+1);
}

int main(int argc, char** argv) {
	int T, test_case;
	rep(i, 1, 1000001) {
		dp[i] = -1;
		ps[i] = 0;
	}
	dp[1] = 0;
	rep(i, 1, 1000001) fillDp(i);
	ll curr = 0;
	rep(i, 1, 1000001) {
		curr += dp[i];
		ps[i] = curr;
	}
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++) {
		int a, b;
		cin>>a>>b;
		printf("Case #%d\n%lld\n", test_case+1, ps[b] - ps[a-1]);
	}

	return 0;
}