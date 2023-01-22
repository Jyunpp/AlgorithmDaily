// 20230122 23:40 ~ 23:
#include <iostream>
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

int t, a, b, h, q, w, e, r;

int main() {
    cin>>t;
    while(t--) {
        cin>>a>>b>>h>>q>>w>>e>>r;
        cout<<(abs(q-e)+abs(w-r)+h+min(min(min(q, w), e), r)*2, abs(q-e)+abs(w-r)+h+min(min(min(min(min(min(min(q, w), e), r), abs(a-q)), abs(a-e)), abs(b-w)), abs(b-r))*2)<<endl;
    }
}