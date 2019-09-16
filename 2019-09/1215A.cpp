// 20190916 19:20 ~ 19:38
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

int a, b, c, d, n;
int mini, maxi;
int main() {
    cin>>a>>b>>c>>d>>n;
    
    mini = n - (a*(c-1) + b*(d-1));
    mini = mini < 0 ? 0 : mini;
    
    if (c>d) {
        int temp = c;
        c = d;
        d = temp;
        temp = a;
        a = b;
        b = temp;
    }

    if (n < a*c) {
        maxi = n/c;
    } else {
        maxi = a;
        n-= (a*c);
        maxi += n/d;
    }

    cout<<mini<<" "<<maxi<<endl;
    return 0;
}