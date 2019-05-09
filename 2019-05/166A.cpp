// 20190509 23:35 ~ 23:40
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

int n, k, ret;
vector<P> v;

int main() {
    cin>>n>>k;
    rep(i, 1, n+1){
        int a, b;
        cin>>a>>b;
        v.pb({a, b});
    }
    sort(v.begin(), v.end(), [](P a, P b){return a.xx!=b.xx ? a.xx>b.xx : a.yy<b.yy;});
    
    P p = v[k-1];
    for(auto i : v) {
        ret += i.xx == p.xx && i.yy == p.yy;
    }
    cout<<ret<<endl;
    return 0;
}