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

int main() {
    cin>>n;
    vector<ll> ps(n+1, 0);
    for(int i=1; i<=n; i++) {
        ll a; cin>>a;
        ps[i] = a + ps[i-1];
    }

    int ret = 0;
    map<int, int> mp;
    mp[0] = 1;
    for(int i=1; i<=n; i++) {
        if(mp[ps[i]]) {
            ret++;
            mp.clear();
            mp[0] = 1;
        }
        mp[ps[i]] = 1;
    }

    cout<<ret<<endl;
    return 0;
}