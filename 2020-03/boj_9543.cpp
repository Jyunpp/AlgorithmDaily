// 20200301 15:55 ~ 16:35 ~ 17:01
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
int arr[10001];

int main() {
    cin>>t;
    rep(T, 1, t+1) {
        cin>>n;
        rep(i, 1, n+1) {
            sd(arr[i]);
        }

        int ans = 0;
        vector<P> ansV;
        int target = n;
        while(target) {
            int targetIdx = target;
            while(arr[targetIdx] != target) targetIdx--;
            // cout<<"targetIdx, target : "<<targetIdx<<", "<<target<<endl;
            
            while(targetIdx != target) {
                int currChangeRightIdx = target;
                int currChangeLeftIdx = 2*targetIdx - currChangeRightIdx + 1;
                while(currChangeLeftIdx<1) currChangeLeftIdx++;
                
                int changeLen = currChangeRightIdx - currChangeLeftIdx + 1;
                if (changeLen%2) currChangeRightIdx--;

                // cout<<"currR : "<<currChangeRightIdx<<", currL : "<<currChangeLeftIdx<<endl;
                for(int i=0; i<(changeLen/2); i++) {
                    int temp = arr[currChangeLeftIdx+i];
                    arr[currChangeLeftIdx+i] = arr[currChangeLeftIdx + changeLen/2+i];
                    arr[currChangeLeftIdx + changeLen/2+i] = temp;
                }
                // for(int i=1; i<=n; i++) {
                //     cout<<arr[i]<<" ";
                // }
                // cout<<endl;
                ans++;
                // cout<<"currAns : "<<ans<<", "<<"["<<targetIdx<<", "<<currChangeRightIdx<<"]"<<endl;
                ansV.pb({currChangeLeftIdx, currChangeRightIdx});
                targetIdx += changeLen/2;
            // int tt;
            // cin>>tt;
            }
            target--;
        }
        
        cout<<ans<<endl;
        for(P p : ansV) {
            cout<<p.xx<<" "<<p.yy<<endl;
        }
    }
    return 0;
}