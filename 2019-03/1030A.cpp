// 20190326 23:21 ~ 23:23
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

const int MAXINT = 9E8;
const int MININT = -9E8;
const long long MAXLL = 9E18;
const long long MINLL = -9E18;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;

int n, ret;

int main() {
    cin>>n;
    rep(i, 1, n+1) {
        int a; cin>>a;
        ret |=a;
    }
    if(ret) cout<<"HARD";
    else cout<<"EASY";
    return 0;
}