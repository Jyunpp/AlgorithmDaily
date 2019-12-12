// 20191212 12:59 ~ 13:12
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

string s;
string ans;

int main() {
    cin>>s;
    if(s[0] == '@' || s[s.size()-1]=='@') {
        cout<<"No solution"<<endl;
        return 0;
    }
    bool isFirst = false;

    char pprev = '.';
    char prev = '.';
    for(char ch : s) {
        if(ch=='@') {
            if(!isFirst) {
                isFirst = true;
            } else {
                ans = ans.substr(0, ans.size()-1);
                ans += ',';
                ans += prev;
            }
        }
        ans += ch;

        if(ch=='@' && (prev=='@' || pprev=='@')) {
            cout<<"No solution"<<endl;
            return 0;
        }

        pprev = prev;
        prev = ch;
    }
    if(!isFirst) cout<<"No solution"<<endl;
    else cout<<ans<<endl;
    return 0;
}