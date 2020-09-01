// 20200901 22:30 ~ 23:30
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
        cin>>s>>n;
        
        vector<int> b(n);
        rep(i, 0, n) cin>>b[i];
        
        vector<vector<int>> groups;
        while (true) {
            vector<int> pos;
            rep(i, 0, n)
                if (b[i] == 0)
                    pos.push_back(i);
            if (pos.empty())
                break;
            groups.push_back(pos);
            rep(i, 0, n)
                if (b[i] == 0)
                    b[i] = INT_MAX;
                else
                    for (int pp: pos)
                        b[i] -= abs(i - pp);
        }

        map<char, int> mp;
        rep(i, 0, s.size())
            mp[s[i]]++;
        
        auto j = mp.rbegin();
        string ans(n, '?');
        for (auto g: groups) {
            while (j->yy < g.size())
                j++;
            for (int pp: g)
                ans[pp] = j->xx;
            j++;
        }
        cout<<ans<<endl;
    }

    return 0;
}