// 20200906 18: 20 ~ 19:00 ~ 20:16 ~ 20:30 
// 1) dp 정의는 좌표기준으로 하고, ans 갱신 루프에서는 원소 index 기준으로 나누어서 실패
// -> dp 정의에 좌표기준 + index 기준도 추가
// 2) ans 갱신 시 우측 끝을 lower_bound로 찾아서 실패
// -> ans 갱신 시 우측 끝을 upper_bound-1로 찾음
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

int t, n, k;

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>k;
        vector<int> v;
        rep(i, 1, n+1) {
            int a; cin>>a;
            v.pb(a);
        }
        rep(i, 1, n+1) {int a; cin>>a;}

        sort(v.begin(), v.end());

        vector<int> dp(n, 0); //dp[i] : max covering count among i~n-1 point when left of x coordinate >=v[i]
        // fill dp
        int lIdx = n-1;
        int rIdx = n-1;
        for(int i=n-1; i>=0; i--) {
            int lCoord = v[i];
            int rCoord = v[i] + k;
            while(lIdx-1>=i && v[lIdx-1] >=lCoord) lIdx--;
            while(v[rIdx]>rCoord && rIdx-1>=0) rIdx--;
            int prevDp = i!=n-1 ? dp[i+1] : 0;
            dp[i] = max(prevDp, rIdx-lIdx+1);
        }

        ll ans = 0;
        for(int i=0; i<=n-1; i++) {
            int lbIdx = upper_bound(v.begin(), v.end(), v[i] + k) - v.begin();
            if(lbIdx>n-1) lbIdx--;
            if(v[lbIdx]>v[i]+k) lbIdx--;
            ll cnt = lbIdx-i+1;
            ll j = lbIdx;

            if(j+1 <=n-1) cnt += dp[j+1];
            ans = max(ans, cnt);
        }

        cout<<ans<<endl;
    }
    return 0;
}