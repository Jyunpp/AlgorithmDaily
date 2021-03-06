// 20200307 20:00 ~
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

int t, n, m;
int a[101], p[101];

int main() {
    cin>>t;
    rep(T, 0, t) {
        cin>>n>>m;
        rep(i, 1, n+1) cin>>a[i];
        rep(i, 1, m+1) cin>>p[i];
        
        string ans = "YES";
        int N = n;
        while(N--) {
            rep(i, 1, n) {
                if (a[i] > a[i+1]) {
                    bool canNext = false;
                    rep(j, 1, m+1) {
                        if (p[j] == i) {
                            canNext = true;
                            break;
                        }
                    }
                    if (canNext) {
                        int temp = a[i];
                        a[i] = a[i+1];
                        a[i+1] = temp;
                    } else {
                        ans = "NO";
                        N = 0;
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}