// 20200813 01:56 ~ 02:05
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

int n, t, minA, minB;
int a[51], b[51];
int main() {
    cin>>t;
    while(t--) {
        ll ans = 0;
        cin>>n;
        minA = minB = 1987654321;
        for(int i=1; i<=n; i++) {
            cin>>a[i];
            minA = min(minA, a[i]);
        }
        for(int i=1; i<=n; i++) {
            cin>>b[i];
            minB = min(minB, b[i]);
        }
        for(int i=1; i<=n; i++) {
            ans += max(a[i]-minA, b[i]-minB);
        }

        cout<<ans<<endl;
    }
    return 0;
}