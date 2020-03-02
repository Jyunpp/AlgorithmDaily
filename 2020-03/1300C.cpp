// 20200302 22:02 ~ 22:32
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

int n;
vector<int> v;
map<int, int> mp;
int maxi = -1;
int maxIdx = -1;

vector<int> get(int x) {
    vector<int> ret;
    int i=1;
    while(x) {
        ret.pb((x%2)*i);
        i*=2;
        x/=2;
    }

    return ret;
}

int main() {
    cin>>n;
    rep(i, 1, n+1) {
        int a;
        cin>>a;
        
        vector<int> bi = get(a);
        for(int j : bi) mp[j]++;

        v.pb(a);
    }

    for(int i=0; i<n; i++) {
        int curr = 0;
        vector<int> bi = get(v[i]);
        for(int j : bi) {
            if (mp[j] == 1) curr += j;
        }

        if (curr > maxi) {
            maxi = curr;
            maxIdx = i;
        }
    }

    cout<<v[maxIdx];
    for(int i=0; i<n; i++) {
        if(i==maxIdx) continue;
        cout<<" "<<v[i];
    }
    cout<<endl;
    return 0;
}