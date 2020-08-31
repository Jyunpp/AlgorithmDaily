// 20200831 13:12 ~ 13:16
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
string s;

int main() {
    cin>>t;
    while(t--) {
        cin>>s;
        string temp = s.substr(1, s.size()-2);
        string ans = "";
        ans += s[0];

        for(int i=0; i<temp.size(); i+=2) {
            ans += temp[i];
        }
        ans += s[s.size()-1];

        cout<<ans<<endl;
    }
}