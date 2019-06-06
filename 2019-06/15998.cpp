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
ll a[300001], b[300001];
ll ret = -1;

ll gcd(ll a, ll b) {
    return a ? gcd(b%a, a) : b;
}

int main() {
	cin>>n;
	rep(i, 1, n+1) {
		cin>>a[i]>>b[i];
		if(a[i]<0 && b[i-1] + a[i] < 0) {
			ll temp = b[i] - a[i] - b[i-1];
			if(ret == -1) ret = temp;
			else if(ret > temp) ret = gcd(temp, ret);
			else ret = gcd(ret, temp);
		}
	}
	if(ret == -1) ret = 1;
	rep(i, 1, n+1) {
		if((a[i]<0 && b[i-1] + a[i] < 0 && b[i] >= ret)
		|| (a[i]<0 && b[i-1] + a[i] >= 0 && b[i-1] + a[i] != b[i])
		|| (a[i]>=0 && b[i-1] + a[i] != b[i])) {
			ret = -1;
			break;
		}
	}
	cout<<ret<<endl;
	return 0;
}