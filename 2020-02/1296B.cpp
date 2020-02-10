// 20200210 22:10 ~ 22:15
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

int t, s;

int main() {
    cin>>t;
    for(int T=1; T<=t; T++) {
        cin>>s;
        ll ans = 0;
        while(s/10) {
            ans += (s/10)*10;
            s = (s/10 + s%10);
        }
        cout<<ans+s<<endl;
    }
    return 0;
}