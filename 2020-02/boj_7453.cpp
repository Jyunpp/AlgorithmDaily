// 20200217 23:10 ~ 23:17 ~ 23:33
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
ll ans;
int arr[4001][5];

int main() {
    cin>>n;
    rep(i, 1, n+1) {
        rep(j, 1, 5) {
            cin>>arr[i][j];
        }
    }

    vector<int> v1;
    vector<int> v2;
    rep(i, 1, n+1){
        rep(j, 1, n+1) {
            v1.pb(arr[i][1] + arr[j][2]);
            v2.pb(arr[i][3] + arr[j][4]);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<P> comp1;
    vector<P> comp2;
    int prev = v1[0];
    comp1.pb({v1[0], 1});
    int sz = v1.size();
    for(int i=1; i<sz; i++) {
        int curr = v1[i];
        if (curr != prev) {
            comp1.pb({curr, 1});
        } else {
            comp1[comp1.size()-1] = {curr, comp1[comp1.size()-1].yy+1};
        }
        prev = curr;
    }
    prev = v2[0];
    comp2.pb({v2[0], 1});
    sz = v2.size();
    for(int i=1; i<sz; i++) {
        int curr = v2[i];
        if (curr != prev) {
            comp2.pb({curr, 1});
        } else {
            comp2[comp2.size()-1] = {curr, comp2[comp2.size()-1].yy+1};
        }
        prev = curr;
    }
    vector<P> inverseComp2;
    sz = comp2.size();
    for(int i = sz-1; i>=0; i--) {
        inverseComp2.pb({comp2[i].xx*(-1), comp2[i].yy});
    }

    int i=0; 
    int j=0;
    while(i<comp1.size() && j<inverseComp2.size()) {
        if (comp1[i].xx == inverseComp2[j].xx) {
            ans += comp1[i].yy * inverseComp2[j].yy;
            i++;
            j++;
        } else {
            if (comp1[i].xx < inverseComp2[j].xx) {
                i++;
            } else {
                j++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}