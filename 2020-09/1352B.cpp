// 20200910 20:34 ~ 20:45
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
int n, k;

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>k;
        vector<int> ans;
        
        if(n%2) {
            if(k%2) {
                //n홀 k홀
                if(n>=k) {
                    for(int i=1; i<k; i++) ans.pb(1);
                    ans.pb(n-(k-1));
                }
            } 
        } else {
            if(k%2) {
                //n짝 k홀
                if(k==1) {
                    ans.pb(n);
                } else {
                    if(n-((k-1)*2) >=2) {
                        for(int i=1; i<k; i++) ans.pb(2);
                        ans.pb(n-((k-1)*2));
                    }
                }
            } else {
                //n짝 k짝
                if(n>=k) {
                    for(int i=1; i<k; i++) ans.pb(1);
                    ans.pb(n-(k-1));
                }
            }
        }

        if(ans.empty()) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
            for(auto i : ans) cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}