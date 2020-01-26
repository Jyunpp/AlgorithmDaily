// 20200126 16:33 ~ 16:37
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
 
int t, a, b, c, n;

int main() {
    cin>>t;
    rep(i, 0, t) {
        scanf(" %d %d %d %d", &a, &b, &c, &n);
        int mx = max(max(a, b), c);
        int needSame = mx-a + mx-b + mx-c;
        if(needSame > n || (n-needSame)%3 ) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}