// 20191207 23:35 ~ 23:48
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

double A, B, n;

int main() {
    cin>>A>>B>>n;
    if (A==0 && B == 0) {
        cout<<1<<endl;
        return 0;
    } else if (B==0) {
        cout<<0<<endl;
        return 0;
    }
    rep(i, 1, 1001) {
        if (pow(i, n) == abs(B/A)) {
            if (B/A > 0) {
                cout<<i<<endl;
                return 0;
            } else if (((int)n)%2) {
                cout<<i * (-1)<<endl;
                return 0;
            }
        }
    }
    cout<<"No solution"<<endl;
    return 0;
}