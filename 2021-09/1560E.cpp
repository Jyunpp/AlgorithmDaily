// 20210914 00:50 ~ 01:17
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
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

int t;
string s;

string solve() {
    map<int, int> mp;
    vector<int> cnt((int)('z'-'a'+1));
    vector<char> v;

    for(int i=s.size()-1; i>=0; i--) {
        if (!mp[s[i]]) {
            mp[(int)s[i]] = 1;
            v.pb(s[i]);
        }
        cnt[s[i]-'a']++;
    }

    int sz = v.size();    
    bool can = true;
    int len = 0;
    for(char ch: v) {
        can &= cnt[ch-'a']%sz == 0;
        len += cnt[ch-'a']/sz;
        sz--;
    }
    if (!can) return "-1";

    string tempRet = s.substr(0, len);
    string curr = tempRet;
    string order = "";
    for(int i=v.size()-1; i>=0; i--) {
        s = s.substr(len);
        string next = "";
        for(char ch: curr) {
            if(ch!=v[i]) next += ch;
        }
        if (s.substr(0, next.size()) != next) return "-1";
        len = next.size();
        curr = next;
        order += v[i];
    }
    
    return tempRet + " " + order;
}

int main() {
    cin>>t;
    while(t--) {
        cin>>s;
        cout<<solve()<<endl;
    }
    return 0;
}