// 20200909 20:50 ~ 21:15
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

int t, n, m;

string getBinary(ll number, int len) {
    stack<int> s;
    while(number>0) {
        s.push(number%2);
        number/=2;
    }

    string ret = "";
    while(!s.empty()) {
        ret += (s.top() ? '1' : '0');
        s.pop();
    }
    int rLen = len - ret.length();
    if(rLen) {
        ret = string(rLen, '0') + ret;
    }

    return ret;
}

ll getNumber(string binary) {
    ll ret = 0;

    int len = binary.size();
    ll digit = 1;
    for(int i=len-1; i>=0; i--) {
        if(binary[i]=='1') ret += digit;
        digit*=2;
    }

    return ret;
}

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>m;

        ll mid = getNumber(string(m, '1'))/2;
        int l = 0;
        int r = 0;
        map<ll, int> mp;        
        vector<ll> v;
        for(int i=1; i<=n; i++) {
            string s; cin>>s;
            ll curr = getNumber(s);
            v.pb(curr);
            mp[curr]++;
            if(curr<=mid) l++;
            else  r++;
        }
        
        int mini = min(l, r);
        l-=mini;
        r-=mini;
        while(true) {
            if(mp[mid]) mid--;
            else break;
        }
        if(r) {
            int cnt = r/2;
            while(cnt--) {
                while(true) {
                    mid--;
                    if(!mp[mid]) break;
                }
            }
        } else if(l) {
            int cnt = l/2 + l%2;
            while(cnt--) {
                while(true) {
                    mid++;
                    if(!mp[mid]) break;
                }
            }
        }
        ll ans = mid;

        cout<<getBinary(ans, m)<<endl;
    }
    return 0;
}