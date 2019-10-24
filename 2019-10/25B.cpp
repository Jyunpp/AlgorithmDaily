// 20191025 02:06 ~ 02:20
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

int n, sz;
string s;

int main() {
    cin>>n>>s;
    while(n) {
        sz = n%2 ? 3 : 2;
        cout<<s.substr(0, sz);
        s = s.substr(sz);
        n-=sz;
        if(n) cout<<"-";
    }
    cout<<endl;
    return 0;
}