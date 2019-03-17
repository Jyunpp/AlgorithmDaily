// 20190318 00:33 ~ 01:11
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
    int sz = s.size()/20 + (s.size()%20 != 0);
    int len = s.size()/sz + (s.size()%sz!=0);
    int rest = len*sz-s.size();
    cout<<sz<<" "<<len<<endl;
    while(sz--){
        cout<<s.substr(0, len-(rest!=0));
        if(rest) cout<<"*";
        cout<<endl;
        s = s.substr(len-(rest!=0));
        if(rest) rest--;
    }
    return 0;
}