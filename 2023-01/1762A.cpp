// 20230121 01:32 ~ 01:47
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

int t, n, sum, curr;
int cnt[51];

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        sum = 0;
        for(int i=1; i<=n; i++) {
            cin>>curr;
            sum += curr;
            cnt[i] = 0;
            while(curr) {
                cnt[i]++;
                if ((curr/2)%2 != curr%2) {
                    break;
                }
                curr/=2;
            }
        }
        int ret = 987654321;
        if (sum%2 == 0) {
            ret = 0;
        } else {
            for(int i=1; i<=n; i++) {
                ret = min(ret, cnt[i]);
            }
        }
        cout<<ret<<endl;
    }
}