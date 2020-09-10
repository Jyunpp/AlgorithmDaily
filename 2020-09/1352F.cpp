// 20200910 21:57 ~ 22:08
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

typedef pair<int, int> P;

int t, oo, ol, ll;

int main() {
    cin>>t;
    while(t--) {
        cin>>oo>>ol>>ll;

        string ans = "";
        if(ol==0) {
            string temp;
            if(oo) temp = "0";
            else temp = "1";
            for(int i=1; i<=oo+ll+1; i++) ans += temp;
        } else {
            ol--;
            while(oo--) ans += "0";
            ans += "01";
            while(ll--) ans += "1";
            vector<string> temp;
            temp.pb("0");
            temp.pb("1");
            int i=0;
            while(ol--) {
                ans+=temp[i];
                i++;
                if(i==2) i=0;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}