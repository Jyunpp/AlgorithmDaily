// 20200916 22:55 ~ 23:11
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

int t, p, f, cnts, cntw, s, w;

int main() {
    cin>>t;
    while(t--) {
        cin>>p>>f>>cnts>>cntw>>s>>w;
        if(s>w) {
            int temp = s;
            s = w;
            w = temp;
            temp = cnts;
            cnts = cntw;
            cntw = temp;
        }

        int ans = 0;
        for(int i=0; i<=cnts; i++) {
            if (i*s > p) break;
            int cntSByP, cntWByP, cntSByF, cntWByF;
            cntSByP = i;
            cntWByP = min((p-cntSByP*s)/w, cntw);
            cntSByF = min(f/s, cnts-cntSByP);
            cntWByF = min((f-cntSByF*s)/w, cntw-cntWByP);

            ans = max(ans, cntSByP+cntWByP+cntSByF+cntWByF);
        }
        
        cout<<ans<<endl;
    }

    return 0;
}