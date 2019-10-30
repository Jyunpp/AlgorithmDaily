// 20191025 19:25 ~ 22:57
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
 
int n, k, a, b, c;
int arr[301][301];
ll ans[301];
 
int main() {
    cin>>n;
    rep(i, 1, n+1) {
        rep(j, 1, n+1) {
            cin>>arr[i][j];
        }
    }
    rep(k, 1, n+1) {
        rep(i, 1, n+1) {
            rep(j, 1, n+1) {
                if(arr[i][k] + arr[k][j] < arr[i][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    cin>>k;
    rep(t, 1, k+1) {
        cin>>a>>b>>c;
        if (c < arr[a][b]) {
            arr[a][b] = arr[b][a] = c;

            vector<int> v; v.pb(a); v.pb(b);
            for(int k : v) {
                rep(i, 1, n+1) {
                    rep(j, 1, n+1) {
                        if(arr[i][k] + arr[k][j] < arr[i][j]){
                            arr[i][j] = arr[i][k] + arr[k][j];
                        }
                    }
                }
            }
        }
        rep(i, 1, n+1) {
            rep(j, i+1, n+1) {
                ans[t] += arr[i][j];
            }
        }
    }
    rep(i, 1, k+1) {
        cout<<ans[i];
        if(i!=k) cout<<" ";
    }
    cout<<endl;
    return 0;
}