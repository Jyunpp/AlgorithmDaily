// 20200928 17:08 ~ 17:15
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

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>m;
        bool can = false;
        for(int i=1; i<=n; i++) {
            int a, b, c, d;
            cin>>a>>b>>c>>d;
            if( b==c) can = true;
        }
        if(can && ((m%2)==0)) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
        
    }

    return 0;
}