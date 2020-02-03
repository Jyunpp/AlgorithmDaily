// 20200203 23:27 ~ 23:31
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

int n, a, b;

int main() {
    cin>>n;
    rep(i, 0, n) {
        cin>>a>>b;
        b++;
        int cnt = 0;
        while(b/10) {
            cnt++;
            b/=10;
        }
        cout<<((ll)a)*cnt<<endl;
    }
    return 0;
}