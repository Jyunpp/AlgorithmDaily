// 20210905 22:07 ~ 22:10
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
int arr[1001];

int main() {
    cin>>t;
    int a = 1;
    for(int i=1; i<=1000; i++) {
        while(a%3==0 || a%10==3) a++;
        arr[i] = a;
        a++;
    }
    while(t--) {
        cin>>k;
        cout<<arr[k]<<endl;
    }
    return 0;
}