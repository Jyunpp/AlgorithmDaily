// 20200902 22:55 ~ 23:11 ~ 23:13
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
ll arr[100001];

int main() {
    cin>>n;
    rep(i, 1, n+1) cin>>arr[i];
    
    cout<<"1 1"<<endl<<arr[1]*(-1)<<endl;
    
    if (n==1) {
        rep(i, 0, 2) cout<<"1 1"<<endl<<0<<endl;
        return 0;
    }

    cout<<2<<" "<<n<<endl;
    rep(i, 2, n+1) cout<<((ll)(n-1)) * arr[i]<<" ";
    cout<<endl;

    cout<<1<<" "<<n<<endl<<0<<" ";
    rep(i, 2, n+1) cout<<((ll)n) * arr[i] * ((ll)-1)<<" ";
    cout<<endl;

    return 0;
}