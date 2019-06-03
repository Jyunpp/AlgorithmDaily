// 20190603 23:05 ~ 23:33
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

int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		map<ll, int> mp;
		vector<ll> d;
		ll curr;
		rep(i, 1, n+1) {
			cin>>curr;
			d.pb(curr);
		}
		sort(d.begin(), d.end());
		int front = 0;
		int back = d.size()-1;
		while(front<=back) {
			ll multiple = d[front]*d[back];
			mp[multiple]++;
			front++;
			back--;
		}
		if(mp.size()!=1) cout<<-1<<endl;
		else {
			ll ret = mp.begin()->xx;
			int ceil = pow(ret, 0.5);
			int cnt = 0;
			rep(i, 2, ceil+1) {
				if(ret%i == 0) {
					cnt++;
					if( ((ll)(i))*((ll)(i)) != ret) cnt++;
				}
			}
			if(cnt != n) cout<<-1<<endl;
			else cout<<ret<<endl;
		}
	}
	return 0;
}