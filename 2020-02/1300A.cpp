// 20200219 23:29 ~ 23:32
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

int t, n, a;

int main() {
    cin>>t;
    rep(T, 0, t) {
        cin>>n;
        int sum = 0;
        int ans = 0;
        bool hasNotMinusOne = false;
        rep(i, 1, n+1) {
            cin>>a;
            if(a!=-1) hasNotMinusOne = true;
            sum += a;
            if(a==0) {
                ans++;
                sum++;
            }
        }
        if(sum==0) {
            ans++;
            if(!hasNotMinusOne) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}