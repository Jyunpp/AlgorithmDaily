// 20200216 03:53 ~ 04:20
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
map<char, P> moves;

int main() {
    moves['L'] = {-1, 0};
    moves['R'] = {1, 0};
    moves['U'] = {0, 1};
    moves['D'] = {0, -1};
    
    cin>>t;
    rep(T, 0, t) {
        string str;
        map<P, int> mp;
        cin>>n;
        cin>>str;

        P curr = {0, 0};
        mp[curr] = -1;
        int ans = 987654321;
        P ansP;
        rep(i, 0, n) {
            P next = {curr.xx + moves[str[i]].xx, curr.yy + moves[str[i]].yy};
            if (mp.find(next) != mp.end() && ans > i-mp[next]) {
                ans = i-mp[next];
                ansP = {i+1, mp[next]+2};
            }
            mp[next] = i;
            curr = next;
        }
        if (ans != 987654321) cout<<ansP.yy<<" "<<ansP.xx<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}