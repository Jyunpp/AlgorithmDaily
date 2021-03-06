// 20190524 01:55 ~ 02:06
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

int n, m, h;
int leftView[101], frontView[101];
int arr[101][101];

int main() {
    cin>>n>>m>>h;
    rep(i, 1, m+1) cin>>frontView[i];
    rep(i, 1, n+1) cin>>leftView[i];
    rep(i, 1, n+1) {
        rep(j, 1, m+1) {
            cin>>arr[i][j];
            arr[i][j] *= min(frontView[j], leftView[i]);
        }
    }
    rep(i, 1, n+1) {
        rep(j, 1, m+1) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}