// 20200911 23:24 ~ 23:27
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

int t, n;

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        
        map<char, int> mp;
        rep(i, 0, n) {
            string s; cin>>s;
            for(auto j: s) mp[j]++;
        }
        bool can = true;
        for(auto i: mp) {
            if(i.yy%n) can = false;
        }

        if(can) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}