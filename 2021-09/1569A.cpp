// 20210916 23:27 ~ 
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

int t, n;
string s;

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>s;
        if(n>=2) {
            int ended = 0;
            for(int i=1; i<n; i++) {
                if (s[i] != s[i-1]) {
                    cout<<i<<" "<<i+1<<endl;
                    ended = 1;
                    break;
                }
            }
            if (ended) continue;
        }
        cout<<-1<<" "<<-1<<endl;
    }
    return 0;
}