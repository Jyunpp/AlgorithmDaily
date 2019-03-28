// 20190328 22:39 ~ 22:42
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

int main() {
    string s;
    cin>>s;
    int ret = 0;
    int curr = 1; 
    char ch = s[0];
    rep(i, 1, s.size()) {
        if(s[i]!=ch) {
            if(curr%2==0) {
                ret++;
            }
            curr = 1;
            ch = s[i];
        } else {
            curr++;
        }
    }
    if(curr%2 == 0) ret++;
    cout<<ret<<endl;
    return 0;
}