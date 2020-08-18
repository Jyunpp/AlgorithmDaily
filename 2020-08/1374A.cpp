// 20200818 23:25 ~ 23:30
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

int t, x, y, n;

int main() {
    cin>>t;
    while(t--) {
        cin>>x>>y>>n;
        int ans = (n/x)*x;
        int diff = x-y;
        ans-= diff;
        if (ans<0) ans+=x;
        while(ans+x <=n) ans+=x;

        cout<<ans<<endl;
    }
    return 0;
}