// 20200128 20:45 ~ 21:00
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

int t, n, a, b;

int main() {
    cin>>t;
    rep(i, 0, t) {
        cin>>n;
        vector<P> arr;
        rep(j, 0, n) {
            cin>>a>>b;
            arr.pb({a, b});
        }
        sort(arr.begin(), arr.end(), [](P x, P y){ return x.xx+x.yy <= y.xx+y.yy; });
        
        bool can = true;
        rep(j, 0, n-1) {
            P prev = arr[j];
            P next = arr[j+1];
            if(prev.xx + prev.yy == next.xx + next.yy 
                || prev.xx > next.xx
                || prev.yy > next.yy) {
                 can = false;
                 break;
            }
        }
        if(!can) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
            P prev = {0, 0};
            for(P next: arr) {
                cout<<string(next.xx-prev.xx, 'R')<<string(next.yy-prev.yy, 'U');
                prev = next;
            }
            cout<<endl;
        }
    }
    
}