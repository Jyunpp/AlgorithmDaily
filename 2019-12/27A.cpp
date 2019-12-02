// 20191202 23:09 ~ 23:11
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

int n, a;
int arr[3001];

int main() {
    cin>>n;
    rep(i, 1, n+1) {
        cin>>a;
        arr[a]++;
    }
    rep(i, 1, 3001) {
        if(!arr[i]) {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<3001<<endl;
    return 0;
}