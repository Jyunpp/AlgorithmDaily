// 20190405 23:17 ~ 23:20
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
map<string, int> mp;

int main() {
    cin>>n;
    string s; cin>>s;
    rep(i, 0, n-1) {
        string curr = s.substr(i, 2);
        mp[curr]++;
    }
    int ret = 0;
    string retS = "";
    for(auto i : mp) {
        if(i.yy>ret) {
            retS = i.xx;
            ret = i.yy;
        }
    }
    cout<<retS<<endl;
    return 0;
}