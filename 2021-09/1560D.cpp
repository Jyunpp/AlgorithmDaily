// 20210912
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
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


vector<string> ts;
int t;
string n;

int solve(string s, string t) {
    int tp = 0;
    int sp = 0;
    int selected = 0;

    while(sp < s.length() && tp < t.length()) {
        if (s[sp] == t[tp]) {
            selected++;
            tp++;
        }
        sp++;
    }

    return s.length() + t.length() - 2 * selected;
}

int main() {
    for (ll i = 1; i <= (ll)2e18; i *= 2) {
        ts.pb(to_string(i));
    }

    cin>>t;
    while(t--) {
        cin>>n;

        int ans = n.length()+1;
        for (auto t: ts) ans = min(ans, solve(n, t));
        
        cout<<ans<<endl;
    }

    return 0;
}