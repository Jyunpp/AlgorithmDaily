// 20190410 23:30 ~ 23:42
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

int n, x, y;
P arr[10001];

int main() {
    cin>>n;
    rep(i, 1, n+1) {
        int a, b; cin>>a>>b;
        arr[i] = {a, b};
    }
    int ans = 1;
    rep(i, 1, n+1) {
        while(x<arr[i].xx || y<arr[i].yy) {
            if(x<y && x<arr[i].xx) {
                x++;
            } else if(x>=y && y<arr[i].yy) {
                y++;
            } else if(x<arr[i].xx) {
                x++;
            } else {
                y++;
            }
            if(x==y) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}