// 20200209 02:50 ~ 02:54
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

int t, n, hasOdd, hasEven;

int main() {
    cin>>t;
    for(int i=1; i<=t; i++) {
        cin>>n;
        hasEven = hasOdd = 0;
        for(int j=1; j<=n; j++) {
            int a; cin>>a;
            if(a&1) hasOdd = 1;
            else hasEven = 1;
        }
        
        if((hasEven && hasOdd) || (n&1 && !hasEven)) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}