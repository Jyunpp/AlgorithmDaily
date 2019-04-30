// 20190430 18:55 ~ 20:00
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

int n, a, b;

int main() {
    cin>>n;
    if(n==2) {
        cout<<1<<endl<<2<<endl;
    } else if(n==3) {
        cout<<1<<endl<<3<<endl;
    } else if(n==4) {
        cout<<2<<endl<<2<<" "<<2<<endl;
    } else if(!(n&1)){
        cout<<n/2<<endl;
        rep(i, 0, n/2) cout<<2<<" ";
        cout<<endl;
    } else {
        cout<<(n-3)/2 +1<<endl<<3<<" ";
        rep(i, 0, (n-3)/2) cout<<2<<" ";
        cout<<endl;
    }
    return 0;
}