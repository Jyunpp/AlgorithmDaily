// 20200904 23:38 ~ 23:54
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
ll a, b, x, y, n;

int main() {
    cin>>t;
    while(t--) {
        cin>>a>>b>>x>>y>>n;
        ll A = a;
        ll B = b;
        ll X = x;
        ll Y = y;
        ll N = n;

        if (a>b) {
            ll temp = a;
            a = b;
            b = temp;
            
            temp = x;
            x = y;
            y = temp;
        }
        if (a==b) {
            if(x>y) {
                ll temp = x;
                x = y;
                y = temp;
            }
        }
        if(a>x) {
            ll diff = a-x;
            if(diff>=n) {
                a-=n;
                n-=n;
            } else {
                a-=diff;
                n-=diff;
            }
        }
        if(b>y && n>=1) {
            ll diff = b-y;
            if(diff>=n) {
                b-=n;
                n-=n;
            } else {
                b-=diff;
                n-=diff;
            }
        }
        ll ans = a*b;

        ll diff1 = A-X;
        ll diff2 = B-Y;
        if(diff1>diff2) {
            if(diff1>=N) {
                A-=N;
                ans = min(ans, A*B);
            } else {
                A-=diff1;
                N-=diff1;
                if(diff2>=N) {
                    B-=N;
                } else {
                    B-=diff2;
                }
                ans = min(ans, A*B);
            }
        } else {
            if(diff2>=N) {
                B-=N;
                ans = min(ans, A*B);
            } else {
                B-=diff2;
                N-=diff2;
                if(diff1>=N) {
                    A-=N;
                } else {
                    A-=diff1;
                }
                ans = min(ans, A*B);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}