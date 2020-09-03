// 20200904 01:36 ~ 01:44
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

int t, n, m;

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>m;
        vector<string> v(n);
        rep(i, 0, n) cin>>v[i];

        queue<string> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<26; j++) {
                string temp = v[0];
                temp[i] = char('a' + j);
                q.push(temp);
            }
        }
        
        for(int i=1; i<n; i++) {
            int sz = q.size();
            while(sz--) {
                string curr = q.front();
                q.pop();

                int cnt = 0;
                rep(j, 0, m) {
                    if (v[i][j] != curr[j]) cnt++;
                }

                if(cnt<=1) q.push(curr);
            }
        }

        if (q.empty()) cout<<-1<<endl;
        else cout<<q.front()<<endl;
    }
    return 0;
}