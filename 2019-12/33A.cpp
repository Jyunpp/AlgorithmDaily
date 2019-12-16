// 20191216 22:04 ~ 22:12
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

int n, m, k, ans;
int arr[1001];

int main() {
    cin>>n>>m>>k;
    rep(i, 1, m+1) arr[i] = 1000001;
    rep(i, 1, n+1) {
        int r, a; cin>>r>>a;
        arr[r] = min(a, arr[r]);
    }
    rep(i, 1, n+1) {
        if(arr[i] != 1000001) ans += arr[i];
    }
    if(ans >= k) ans = k;
    cout<<ans<<endl;
    return 0;
}