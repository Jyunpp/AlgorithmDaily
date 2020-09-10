// 20200910 20:30 ~ 20:33
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

int t;
int n;

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        vector<int> ans;
        int d = 1;
        while(n) {
            int curr = n%10;
            if(curr) ans.pb(curr*d);
            n/=10;
            d*=10;
        }
        cout<<ans.size()<<endl;
        for(auto i : ans) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}