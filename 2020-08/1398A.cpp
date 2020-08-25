// 20200825 23:03 ~ 23:07
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
#include <set>
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
        int a;
        int miniSum = 0;
        rep(i, 1, n+1) {
            cin>>a;
            if(i<=2) miniSum += a;
        }
        if (miniSum <= a) {
            cout<<"1 2 "<<n<<endl;
        } else {
            cout<<"-1"<<endl;
        }
    }

    return 0;
}