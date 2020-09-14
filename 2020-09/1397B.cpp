// 20200913 02:12 ~ 
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
    vector<ll> v(n);
    for(auto &i: v) cin>>i;
    sort(v.begin(), v.end());

    ll ans = (ll) pow((ll) 10, 9+5);
    ll c=1; 
    while(true) {
        bool end = false;
        ll tempAns = 0;
        for(int i=0; i<n; i++) {
            ll curr = (ll) pow(c, i);
            if(curr >= (ll) pow((ll)10, 9+5)) {
                end = true;
                break;
            }
            ll currDiff = curr-v[i];
            if(currDiff<0) currDiff*=-1;
            tempAns += currDiff;
        }
        if(end) break;
        if(tempAns < ans) ans = tempAns;
        else break;
        c++;
    }
    cout<<ans<<endl;

    return 0;
}