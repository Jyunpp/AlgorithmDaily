// 20200111
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
 
string s[1501];
map<string, int> cnt;
int n, k;
char ss[3] = {'S', 'E', 'T'};

int main() {
    cin>>n>>k;
    rep(i, 1, n+1) cin>>s[i];
    
    int ans = 0;
    rep(i, 1, n+1) {
        rep(j, i+1, n+1) {
            string curr = "";
            rep(kk, 0, k) {
                if(s[i][kk] == s[j][kk]) curr += s[i][kk];
                else {
                    for(char ch : ss){
                        if (s[i][kk] != ch && s[j][kk] != ch) {
                            curr += ch;
                            break;
                        }
                    }
                }
            }
            if(cnt.count(curr)) ans += cnt[curr];
        }
        cnt[s[i]]++;
    }
    cout<<ans<<endl;
    return 0;
}