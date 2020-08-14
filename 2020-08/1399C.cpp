// 20200814 23:29 ~ 23:42
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

int n, t;
int main() {
    cin>>t;
    while(t--) {
        vector<int> v;
        cin>>n;
        rep(i, 1, n+1) {
            int a; cin>>a;
            v.pb(a);
        }
        sort(v.begin(), v.end());

        // map<int, int> mp;
        int ans = 0;
        rep(i, 0, n) {
            rep(j, i+1, n) {
                // mp[v[i]+v[j]]++;
                int sum = v[i] + v[j];
                int currAns = 1;
                
                int s = i+1;
                int e = j-1;
                while(s<e) {
                    int currSum = v[s] + v[e];
                    if(currSum == sum) {
                        currAns++;
                        s++;
                        e--;
                    } else if (currSum > sum) {
                        e--;
                    } else {
                        s++;
                    }
                }

                s = i-1;
                e = j+1;
                while(s>=0 && e<n) {
                    int currSum = v[s] + v[e];
                    if(currSum == sum) {
                        currAns++;
                        s--;
                        e++;
                    } else if (currSum > sum) {
                        s--;
                    } else {
                        e++;
                    }
                }
                
                ans = max(ans, currAns);
            }
        }

        cout<<ans<<endl;
    }
    
    return 0;
}