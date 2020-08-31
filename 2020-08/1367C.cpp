// 20200831 13:26 ~ 13:42 ~ 13:48 ~ 13:52 ~ 13:54
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
string s;

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>k>>s;
        
        int ans = 0;
        int ones = 0;
        for(char ch : s) if(ch == '1') ones++;
        if (!ones) {
            ans += (n)/(k+1);
            if (n%(k+1)) ans++;
        } else {
            vector<int> v;
            int i = 0;
            for(char ch : s) {
                if (ch == '1') {
                    if(i) {
                        v.pb(i);
                        i = 0;
                    }
                } else {
                    i++;
                }
            }
            if (i>0) v.pb(i);

            if (ones==1) {
                if(v.size()==1) {
                    ans += v[0]/(k+1);
                } else if(v.size()==2){
                    ans += v[0]/(k+1);
                    ans += v[1]/(k+1);
                }
            } else {
                int j = 0;
                int ii = v.size()-1;
                if(s[0] != '1') {
                    ans += v[0]/(k+1);
                    j++;
                }
                if (s[s.size()-1] != '1') {
                    ans += v[ii]/(k+1);
                    ii--;
                }
                for(int i=j; i<=ii; i++) {
                    ans += (v[i]-k)/(k+1);
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}