// 20190603 02:55 ~ 03:10
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
string s, ret;

int main() {
	cin>>n>>s;
	int iter = 0;
	while(iter+1 < n) {
		if(s[iter] != s[iter+1]) {
			ret += s[iter];
			ret += s[iter+1];
			iter+=2;
		} else {
			iter++;
		}
	}
	cout<<n - ret.size()<<endl<<ret<<endl;
	return 0;
}