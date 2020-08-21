// 20200822 03:27 ~ 03:38
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
#include <set>
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

int n, k;
vector<int> arr[3];

int main() {
    cin>>n>>k;
    
    rep(i, 1, n+1) {
        int a, b, c;
        cin>>a>>b>>c;
        if (b|c) arr[(b+c*2)%3].pb(a);
    }

    rep(i, 1, 3) sort(arr[i].begin(), arr[i].end());
    int minLen = min(arr[1].size(), arr[2].size());
    rep(i, 0, minLen) {
        arr[0].pb(arr[1][i] + arr[2][i]);
    }

    sort(arr[0].begin(), arr[0].end());

    int ans = 0;
    if (arr[0].size() >= k) rep(i, 0, k) ans += arr[0][i];
    else ans = -1;
    cout<<ans<<endl;

    return 0;
}