// 20190319 11:05 ~ 11:12
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

int n, p, k;

int main() {
    cin>>n>>p>>k;
    if(p-k > 1) {
        cout<<"<< ";
    } 
    for(int i=max(p-k, 1); i<p; i++) {
        cout<<i<<" ";
    }
    cout<<"("<<p<<") ";
    for(int i=p+1; i<=min(p+k, n); i++) {
        cout<<i<<" ";
    }
    if(p+k < n) {
        cout<<">>";
    }
    return 0;
}