// 20210911 23:03 ~ 23:22
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

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        
        int ret = v[0];
        for(int i=1; i<n; i++) {
            ret &= v[i];
        }
        cout<<ret<<endl;
    }
    return 0;
}