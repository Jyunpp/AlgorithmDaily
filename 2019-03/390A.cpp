// 20190321 23:15 ~ 23:18
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

map<int, int> mp[2];

int main() {
    int n; cin>>n;
    rep(i, 1, n+1){
        int a, b;
        cin>>a>>b;
        mp[0][a]++;
        mp[1][b]++;
    }
    cout<<min(mp[0].size(), mp[1].size())<<endl;
    return 0;
}