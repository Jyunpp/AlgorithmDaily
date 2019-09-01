// 20190901 20:25 ~ 20:31 ~ 20:40
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

int n, N, ans;
int arr[17];

int main() {
    cin>> n;
    N = n;
    rep(i, 1, n+1) cin>>arr[i];
    
    ans = 1;
    while(n>1) {
        int l = 1; 
        while(l<N) {
            int prev = -1;
            bool sorted = true;
            rep(i, l, l+n) {
                if(prev > arr[i]) {
                    sorted = false;
                    break;
                }
                prev = arr[i];
            }
            if(sorted) {
                ans = n;
                break;
            }
            l+=n;
        }
        if(ans == n) break;
        n/=2;
    }

    cout<<ans<<endl;
    return 0;
}