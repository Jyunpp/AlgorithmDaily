// 20190409 10:32 ~ 10:37
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

string s1, s2;
int sz1, sz2;

int main() {
    cin>>s1>>s2;
    sz1 = s1.size();
    sz2 = s2.size();
    int i = sz1-1, j = sz2-1;
    while(i>=0 && j>=0 && s1[i] == s2[j]) {
        i--;
        j--;
    }
    cout<<i+j+2<<endl;
    return 0;
}