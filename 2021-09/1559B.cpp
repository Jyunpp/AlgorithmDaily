// 20210915 23:06 ~ 23:45
#include <iostream>
#include <vector>
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

int t, n;
string s;
char ch[2] = {'B', 'R'};

void fill(int l, int r) {
    if (l>0) {
        int chIdx = s[l-1] == 'B' ? 1 : 0;
        for(int i=l; i<=r; i++) {
            s[i] = ch[chIdx];
            chIdx++;
            chIdx%=2;
        }
    } else {
        int chIdx = 1;
        if(r<n-1) {
            chIdx = s[r+1] == 'B' ? 1 : 0;
        }
        
        for(int i=r; i>=l; i--) {
            s[i] = ch[chIdx];
            chIdx++;
            chIdx%=2;
        }
    }
}

string solve() {
    int l = 0;
    while(l < n) {
        if(s[l] == '?') {
            int r = l;
            while(r+1<n && s[r+1] == '?') r++;
            fill(l, r);
            l = r+1;
        } else {
            l++;
        }
    }
    return s;
}

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        cin>>s;
        cout<<solve()<<endl;
    }
    return 0;
}