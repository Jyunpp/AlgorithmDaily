// 20191217 22:24 ~ 22:43
// 20191218 21:58 ~ 22:05
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

string s, t;
int n;
int arr[27][27];

int ctoi(char x) {
    return x-'a'+1;
}

int main() {
    cin>>s>>t>>n;
    rep(i, 1, 27) rep(j, 1, 27) arr[i][j] = 987654321;
    rep(i, 1, n+1) {
        char A, B; 
        int w, a, b;
        cin>>A>>B>>w;
        a = ctoi(A); 
        b = ctoi(B);
        arr[a][b] = min(w, arr[a][b]);
    }
    rep(i, 1, 27) arr[i][i] = 0;
    rep(k, 1, 27) {
        rep(i, 1, 27) {
            if (i==k) continue;
            rep(j, 1, 27) {
                if (i==j || k==j) continue;
                if(arr[i][k] <= 50000 && arr[k][j] <= 50000) {
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                }
            }
        }
    }
    int len = s.size();
    if(len != t.size()) {
        cout<<-1<<endl;
        return 0;
    }
    int ans = 0;
    string ansStr = "";
    rep(i, 0, len) {
        if(s[i] == t[i]) {
            ansStr += s[i];
            continue;
        }
        int a = ctoi(s[i]);
        int b = ctoi(t[i]);
        int u = -1;
        int mini = 987654321;
        rep(j, 1, 27) {
            if(arr[a][j] > 50000 || arr[b][j] > 50000) continue;
            if(arr[a][j] + arr[b][j] < mini) {
                u = j;
                mini = arr[a][j] + arr[b][j];
            }
        }
        if(u == -1) {
            cout<<-1<<endl;
            return 0;
        }
        ans += mini;
        ansStr += ((char)('a' + u - 1));
    }
    cout<<ans<<endl;
    cout<<ansStr<<endl;
    return 0;
}
