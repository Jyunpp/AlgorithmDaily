// 20200518 23:00 ~ 
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
vector<int> arr;
map<int, int> mp;

void checkDivisor(int x) {
    for(int i=1; i<=int(pow(x, 0.5)); i++) {
        if(x%i==0) {
            mp[i]++;
            mp[x/i]++;
        }
    }
}

int main() {
    cin>>n;
    rep(i, 0, n) {
        int curr;
        cin>>curr;
        arr.pb(curr);
    }
    sort(arr.begin(), arr.end());

    for(int i=0; i<n-1; i++) {
        checkDivisor(arr[i+1] - arr[i]);
    }

    for(auto &i : mp) {
        if(i.xx==1) continue;
        bool isAnswer = true;
        for(int j=1; j<n; j++) {
            isAnswer &= (arr[0]%i.xx == arr[j]%i.xx);
        }
        
        if(isAnswer) cout<<i.xx<<" ";
    }
    return 0;
}