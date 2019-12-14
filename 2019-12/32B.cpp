// 20191214 22:52 ~ 22:57
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

string s;
int i;

int main() {
    cin>>s;
    while(i < s.size()) {
        if (s[i] == '.') {
            cout<<0;
            i++;
        } else {
            if (s[i+1] == '.') cout<<1;
            else cout<<2;
            i+=2;
        }
    }
    return 0;
}