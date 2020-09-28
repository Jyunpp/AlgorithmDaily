// 20200928 17:15 ~ 17:28
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
        if(n==1) cout<<0<<endl;
        else {
            ll a = 1;
            ll b = n;
            ll answer = 98765432123;
            while(a<=50000) {
                if(answer > a-1+b) answer = a-1+b;
                a++;
                b = ((n/a)-1 + ((n%a)>0));
            }
            cout<<answer<<endl;
        }
    }

    return 0;
}