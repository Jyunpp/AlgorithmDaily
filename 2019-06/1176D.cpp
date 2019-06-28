// 20190617
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

int arr[2750132];
int pIdx[2750132];
int p[200001];
int n;
vector<int> v, ret;
int nums[2750132];

int main() {
    for(int i=2; i<=pow(2750131, 0.5); i++) {
        for(int j=2; i*j<=2750131; j++) {
            arr[i*j] = 1;
        }
    }
    int iter = 1;
    for(int i=2; i<=2750131; i++) {
        if(arr[i] == 0) {
            p[iter] = i;
            pIdx[i] = iter;
            iter++;
        }
    }

    cin>>n;
    rep(i, 0, 2*n) {
        int a; cin>>a;
        v.pb(a);
        nums[a]++;
    }
    sort(v.begin(), v.end());

    for(int i=2*n-1; i>=0; i--) {
        if(!nums[v[i]]) continue;
        if(arr[v[i]] == 0) {
            ret.pb(pIdx[v[i]]);
            nums[pIdx[v[i]]]--;
        } else {
            iter = 1;
            while(v[i] % p[iter]) iter++;
            ret.pb(v[i]);
            nums[v[i]/p[iter]]--;
        }
        nums[v[i]]--;
    }

    for(auto i : ret) cout<<i<<" ";
    return 0;
}