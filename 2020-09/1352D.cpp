// 20200910 20:50 ~ 21:15
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

int t, n;

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        vector<int> arr;
        rep(i, 0, n) {
            int a; cin>>a;
            arr.pb(a);
        }

        vector<int> ans(3, 0);
        int l = 0;
        int r = n-1;
        
        ans[0]++;
        l++;
        int d = 1;
        ans[1] += arr[0];
        int prev = arr[0];
        while(true) {
            if(l>r) break;
            if(d==1) d=2;
            else d=1;

            if(d==1) {
                int curr = 0;
                bool can = true;
                int tempL=l;
                for(int i=l; i<n; i++) {
                    tempL = i;
                    if(i>r) {can = false;break;}
                    curr += arr[i];
                    if(curr>prev) break;
                }
                l = tempL+1;
                ans[d] += curr;
                prev = curr;
                ans[0]++;
                if(!can)break;
            } else {
                int curr = 0;
                bool can = true;
                int tempR = r;
                for(int i=r; i>=0; i--) {
                    tempR = i;
                    if(i<l) {can = false;break;}
                    curr += arr[i];
                    if(curr>prev) break;
                }
                r =tempR-1;
                ans[d] += curr;
                prev = curr;
                ans[0]++;
                if(!can)break;
            }
        }
        for(int i=0; i<=2; i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}