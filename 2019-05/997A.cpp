// 20190512 18:45 ~ 19:00
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

ll n, x, y, m, zeros;
string s;

int main() {
    cin>>n>>x>>y>>s;
    m = min(x, y);
    for(int i=1; i<n; i++) zeros += (s[i] == '1' && s[i-1] == '0');
    zeros += (s[n-1] == '0');
    if(!zeros) cout<<0<<endl;
    else cout<<(zeros-1)*m + y<<endl;
    return 0;
}