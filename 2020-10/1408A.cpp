//20201009 23:36 ~ 23:50
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

int t, n;

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        vector<vector<int>> arr(3, vector<int>(n, 0));
        for(auto &i: arr) {
            for(auto &j: i) {
                cin>>j;
            }
        }
        vector<int> ans(n, 0);
        ans[0] = arr[0][0];
        for(int i=1; i<n-1; i++) {
            int j=0;
            while(arr[j][i]==ans[i-1]) j++;
            ans[i] = arr[j][i];
        }
        int j=0;
        while(arr[j][n-1]==ans[n-2] || arr[j][n-1] == ans[0]) j++;
        ans[n-1] = arr[j][n-1];

        cout<<ans[0];
        for(int i=1; i<n; i++) cout<<" "<<ans[i];
        cout<<endl;
    }
    return 0;
}