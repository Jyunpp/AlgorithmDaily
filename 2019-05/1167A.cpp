// 20190516 23:51 ~ 
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
string s;

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>s;
        if(n<=10) cout<<"NO"<<endl;
        else {
            int r = n-11;
            bool can = false;
            if(s[0] == '8') can = true;
            else {
                rep(i, 0, r) {
                    if(s[i+1] == '8') can = true;
                }
            }
            if(can) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}