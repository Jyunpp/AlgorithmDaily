// 20190622 04:12 ~ 04:23
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

int main(int argc, char** argv) {
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++) {
		cin>>n;
		vector<double> ans(n);
		vector<P> v;
		rep(i, 0, n) {
			int r; cin>>r;
			v.pb({r, i});
		}
		sort(v.begin(), v.end(), [](P a, P b){return a.xx < b.xx;});
		ans[v[n-1].yy] = 0.0;
		double lastR = 0.0;
		double lastX = 0.0;
		rep(i, 0, v.size()-1) {
			double firstR = (double)(v[n-1].xx);
			double currR = (double)(v[i].xx);
			if(lastR == 0.0) {
				ans[v[i].yy] = 2*sqrt(firstR*currR);
			} else {
				ans[v[i].yy] = max(2*sqrt(firstR*currR), 2*sqrt(lastR*currR) + lastX);
			}
			lastR = currR;
			lastX = ans[v[i].yy];
		}

		printf("Case #%d\n", test_case+1);
		rep(i, 0, n) {
			for(auto j : v) {
				if(i==j.yy) {
					printf("%.11f\n", ans[j.yy]);
				}
			}
		}
	}
	return 0;
}