// 20190501 09:55 ~ 10:15 , 23:15 ~ 23:28
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

int n;
string s, ret;

int main() {
    cin>>n>>s;
    ret = s;
    int i = 0, idx = (n>>1) + (n&1);
    bool left = (n&1);
    while(i < n) {
        ret[idx-1] = s[i];
        i++;
        idx += i * ((left) ? -1 : 1);
        left = !left;
    }
    cout<<ret<<endl;
    return 0;
}