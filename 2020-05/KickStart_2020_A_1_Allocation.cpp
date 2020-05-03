// 20200503 18:28 ~ 18:35
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

int N, B;

int main() {
    cin>>N;
    
    rep(T, 1, N+1) {
        int n, ans = 0;
        cin>>n>>B;
        vector<int> v(n);
        rep(i, 0, n) cin>>v[i];

        sort(v.begin(), v.end());
        ll ps = 0;
        while(ans < n && ps+v[ans] <= B) {
            ps += v[ans++];
        }

        cout<<"Case #"<<T<<": "<<ans<<endl;
    }

    return 0;
}