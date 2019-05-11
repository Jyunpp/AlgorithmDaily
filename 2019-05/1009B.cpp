// 20190511 19:03 ~ 19:28
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

string s, inputS;
int num[3];

void cutPrint() {
    rep(i, 0, 3) {
        rep(j, 0, num[i]) {
            cout<<i;
        }
        num[i] = 0;
    }
}

int main() {
    cin>>inputS;
    for(char ch : inputS) {
        if(ch=='1') num[1]++;
    }
    rep(i, 0, num[1]) s+="1";
    num[1] = 0;
    for(char ch: inputS) {
        if(ch=='0') s+="0";
        else if(ch=='2') s+="2";
    }
    bool cut = false;
    for(char ch : s) {
        if(ch=='0' && cut) {
            cutPrint();
            cut = false;
        } else if (ch=='2' && !cut) {
            cut = true;
        }
        num[ch-'0']++;
    }
    cutPrint();
    cout<<endl;
    return 0;
}