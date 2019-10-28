// union find
// 20191028 19:11 ~ 19:32
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
int parent[1001];
vector<P> close;
vector<P> connect;

void init(int x) {
    rep(i, 1, x+1) parent[i] = i;
}

int find(int x) {
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void merge(int x, int y) {
    parent[find(y)] = find(x);
}

int main() {
    cin>>n;
    init(n);

    rep(i, 1, n) {
        cin>>a>>b;
        if(find(a) != find(b)) {
            merge(a, b);
        } else {
            close.pb({a, b});
        }
    }
    rep(i, 2, n+1) {
        int p1 = find(1);
        int pi = find(i);
        if(p1 != pi) {
            connect.pb({p1, pi});
            merge(1, i);
        }
    }
    
    int sz = close.size();
    cout<<sz<<endl;
    rep(i, 0, sz) {
        cout<<close[i].xx<<" "<<close[i].yy<<" "<<connect[i].xx<<" "<<connect[i].yy<<endl;
    }
    return 0;
}