// 20191209 00:29 ~ 00:35
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
int arr[1001];

int main() {
    cin>>n;
    rep(i, 1, n+1) cin>>arr[i];

    rep(i, 1, n+1) {
        rep(j, i+1, n+1) {
            rep(k, 1, n+1) {
                if(arr[i]+arr[j] == arr[k]) {
                    cout<<k<<" "<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}