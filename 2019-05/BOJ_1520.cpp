// 20190529 22:13 ~ 22:19
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

int n, m;
int arr[501][501];
int dp[501][501];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int dfs(int y, int x) {
	int &ret = dp[y][x];
	if(dp[y][x] != -1) return ret;
	if(y==n && x==m) return 1;

	ret = 0;
	rep(i, 0, 4) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny*nx==0 || ny>n || nx>m) continue;
		if(arr[ny][nx] < arr[y][x]) {
			ret += dfs(ny, nx);
		}
	}
	return ret;
}

int main() {
	cin>>n>>m;
	rep(i, 1, n+1) rep(j, 1, m+1) dp[i][j] = -1, cin>>arr[i][j];
	cout<<dfs(1, 1)<<endl;
	return 0;
}