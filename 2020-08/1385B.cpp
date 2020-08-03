// 20200803 12:07 ~ 12:12
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
int arr[51];
int main() {
    cin>>t;
    while(t--) {
        int n; cin>>n;
        rep(i, 0, 51) arr[i] = 0;
        
        vector<int> v;
        rep(i, 1, n*2+1) {
            int a; cin>>a;
            if (!arr[a]) {
                v.pb(a);
                arr[a] = 1;
            } else {
                arr[a] = 0;
            }
        }
        rep(i, 0, n-1) {
            cout<<v[i]<<" ";
        }
        cout<<v[n-1]<<endl;
    }
    return 0;
}