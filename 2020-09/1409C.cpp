// 20200904 23:55 ~ 00:09
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
ll n, x, y;

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>x>>y;
        if(n==2) {
            cout<<x<<" "<<y<<endl;
        } else {
            ll ans = -1;
            ll diff = y-x;
            ll currDis = y-x;
            for(int i=n-1; i>=1; i--) {
                if(diff%i == 0) {
                    int rest = n-1-i;
                    if(rest==0) {
                        if (ans ==-1) {
                            ans = y;
                            currDis = diff/i;
                        } else {
                            if (y<ans) {
                                ans = y;
                                currDis = diff/i;
                            }
                        }
                    } else {
                        ll X = x;
                        ll dis = diff/i;
                        while(rest) {
                            if(X-dis >=1) {
                                X-=dis;
                                rest--;
                            } else break;
                        }
                        ll Y = y;
                        if (ans ==-1) {
                            ans = Y + rest*dis;
                            currDis = dis;
                        } else {
                            if (Y + rest*dis<ans) {
                                ans = Y + rest*dis;
                                currDis = dis;
                            }
                        }
                    }
                }
            }
            for(int i=0; i<n; i++) {
                cout<<ans-currDis*i<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}