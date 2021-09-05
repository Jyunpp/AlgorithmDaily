// 20210905 22:10 ~ 22:20
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

int t, a, b, c;

int main() {
    cin>>t;
    while(t--) {
        cin>>a>>b>>c;

        if (a>b) {
            int temp = a;
            a = b;
            b = temp;
        }
        int cnt = 2 + 2*(b-1-a);
        // cout<<"cnt : "<<cnt<<" ";
        int ans = (c + cnt/2)%cnt;
        if (ans == 0) ans = cnt;
        if (a>cnt || b>cnt || c>cnt) ans = -1;
        cout<<ans<<endl;
    }
    return 0;
}