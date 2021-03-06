// 20190402 23:06 ~ 23:09
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

int arr[11][11];
int main() {
    int n; cin>>n;
    arr[1][0] = 1;
    rep(i, 1, n+1) {
        rep(j, 1, n+1) {
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }
    cout<<arr[n][n]<<endl;
    return 0;
}