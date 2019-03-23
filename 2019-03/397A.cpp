// 20190324 01:35 ~ 
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

int n, l, r, cl,cr;

int arr[101];
int main() {
    cin>>n;
    cin>>l>>r;
    rep(i, 2, n+1){
        cin>>cl>>cr;
        rep(j, cl+1, cr+1) arr[j]++;
    }
    int ret = 0;
    rep(i, l+1, r+1) {
        ret += !arr[i];
    }
    cout<<ret<<endl;
}