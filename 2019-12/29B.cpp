// 20191206 00:54 ~ 01:15
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

double l, d, v, g, r;

int main() {
    cin>>l>>d>>v>>g>>r;
    
    if (g*v > d) {
        printf("%.8f\n", l/v);
    } else {
        double ans = g;

        while(true) {
            if ((ans+r)*v >= d) {
                printf("%.8f\n", ans + r + (l-d)/v);
                break;
            } else if((ans+r+g)*v > d) {
                printf("%.8f\n", ans + (l-(ans*v))/v);
                break;
            }
            ans+=(g+r);
        }
    }
    return 0;
}