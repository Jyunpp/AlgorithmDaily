// 20190517 23:22 ~ 23:27
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

int arr[51];
int n,h,m,l,r,x,ans;

int main() {
    cin>>n>>h>>m;
    rep(i, 1, n+1) arr[i] = h;
    rep(i, 0, m) {
        cin>>l>>r>>x;
        rep(j, l, r+1) arr[j] = min(arr[j], x);
    }
    rep(i, 1, n+1) ans += arr[i]*arr[i];
    cout<<ans<<endl;
    return 0;
}