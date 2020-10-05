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

int main() {
    cin>>n;
    vector<int> a(3, 0), b(3, 0);
    for(auto &i: a) cin>>i;
    for(auto &i: b) cin>>i;

    int maxAns = 0;
    int minAns = 1987654321;

    vector<P> order;
    order.pb({0, 0});
    order.pb({0, 2});
    order.pb({1, 1});
    order.pb({1, 0});
    order.pb({2, 2});
    order.pb({2, 1});
    sort(order.begin(), order.end());
    do {
        vector<int> currA = a, currB = b;
        for(int i=0; i<order.size(); i++) {
            int cnt = min(currA[order[i].xx], currB[order[i].yy]);
            currA[order[i].xx] -= cnt;
            currB[order[i].yy] -= cnt;
        }
        int currMinAns = min(currA[0], currB[1]) + min(currA[1], currB[2]) + min(currA[2], currB[0]);
        minAns = min(minAns, currMinAns);
    } while(next_permutation(order.begin(), order.end()));

    maxAns = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);

    cout<<minAns<<" "<<maxAns<<endl;

    return 0;
}