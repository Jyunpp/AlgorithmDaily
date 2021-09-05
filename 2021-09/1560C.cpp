// 20210905 22:23 ~ 22:34
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

int t, k;

int main() {
    cin>>t;
    while(t--) {
        cin>>k;
        int i = 1;
        while(k>i*i) i++;
        i--;
        int sq = i*i;
        int r = k-sq;
        
        if (r==i+1) {
            cout<<i+1<<" "<<i+1<<endl;
        } else if(r<i+1) {
            cout<<r<<" "<<i+1<<endl;
        } else {
            cout<<i+1<<" "<<i+1-(r-i-1)<<endl;
        }
    }
    return 0;
}