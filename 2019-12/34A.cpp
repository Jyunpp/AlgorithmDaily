// 20191223 22:45 ~ 22:48
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

int n, ans;
int arr[102];

int main() {
    cin>>n;
    rep(i, 1, n+1) cin>>arr[i];
    arr[n+1] = arr[1];
    
    int curr = 987654321;
    rep(i, 1, n+1) {
        int currDiff = abs(arr[i+1] - arr[i]);
        if(currDiff < curr) {
            ans = i;
            curr = currDiff;
        }
    }

    cout<<ans<<" "<<(ans+1>n?1:ans+1)<<endl;
    return 0;
}