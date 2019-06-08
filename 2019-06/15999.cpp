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

#define mod 1000000007

int n, m;
ll ret;
char arr[2001][2001];
int fix[2001][2001];

int main() {
	cin>>n>>m;
	rep(i, 1, n+1) rep(j, 1, m+1) cin>>arr[i][j];
	rep(i, 1, n+1) {
		rep(j, 1, m) {
			if(arr[i][j] != arr[i][j+1]) {
				fix[i][j] = fix[i][j+1] = 1;
			}
		}
	}
	rep(i, 1, n) {
		rep(j, 1, m+1) {
			if(arr[i][j] != arr[i+1][j]) {
				fix[i][j] = fix[i+1][j] = 1;
			}
		}
	}
	ret = 1;
	rep(i, 1, n+1) {
		rep(j, 1, m+1) {
			if(!fix[i][j]) {
				ret *= 2;
				ret = ret % mod;
			}
		}
	}
	cout<<ret<<endl;
	return 0;
}