// 20200921 06:16 ~ 06:25
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
    while(t--) {
        cin>>n>>a>>b;
        string temp = "";
        for(int i=0; i<a; i++) {
            temp += ((char)('a' + (i%b)));
        }

        string ans = "";
        while(ans.size() < n) {
            ans += temp;
        }

        cout<<ans.substr(0, n)<<endl;
    }
    
    return 0;
}