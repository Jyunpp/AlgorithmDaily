// 20190508 21:02 ~ 21:22
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

int n, ret;
int arr[100001];

int main() {
    cin>>n;
    rep(i, 1, n+1) {
        char ch;cin>>ch;
        arr[i] = ch=='G';
    }
    vector<P> v;
    for(int i=1; i<=n; i++) {
        int s = i;
        while(i+1<=n && arr[s] == arr[i+1]) i++;
        v.pb({i-s+1, arr[s]});
    }
    int numOfGSeg = 0;
    for(auto i : v) {
        if(i.yy) {
            ret = max(ret, i.xx);
            numOfGSeg++;
        }
    }
    ret+=(numOfGSeg>=2);
    for(int i=1; i<v.size()-1; i++) {
        if(!v[i].yy && v[i].xx == 1 && v[i-1].yy && v[i+1].yy) {
            ret = max(ret, v[i-1].xx + v[i+1].xx + (numOfGSeg>=3));
        }
    }
    cout<<ret<<endl;
    return 0;
}