// 20190319 10:35 ~ 10:43 +1
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

int arr[50];

int main() {
    string s;
    cin>>s;
    rep(i, 0, s.size()) {
        arr[s[i]-'a']++;
    }
    arr['n'-'a']=arr['n'-'a'] < 3 ? 0: 1 + (arr['n'-'a']-3)/2;
    arr['e'-'a']/=3;
    int ret = min(min(min(arr['n'-'a'], arr['e'-'a']),arr['i'-'a']),arr['t'-'a']);
    cout<<ret<<endl;
    return 0;
}