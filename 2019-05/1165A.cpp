// 20190531 18:33 ~ 18:41
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

int n, x, y, ret;

int main() {
    cin>>n>>x>>y;
    rep(i, 1, n+1) {
        char curr; cin>>curr;
        if(i <= (n-x)) continue;
        if(i == (n-y)) ret += curr!='1';
        else ret += curr!='0';
    }
    cout<<ret<<endl;
    return 0;
}