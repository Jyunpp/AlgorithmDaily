// 20200905 00:10 ~ 00:56
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

typedef unsigned long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;

int t, s;
string n;

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>s;
        int currSum = 0;
        int i=0;
        string ret = "-1";
        ll ansRet = -1;
        for(char ch :n) {
            int nextSum = currSum + int(ch-'0');
            if(nextSum==s) {
                bool can = true;
                for(int j=i+1; j<n.size(); j++) {
                    if(n[j] != '0')can = false;
                }
                if(can) {
                    break;
                }
            }
            if(nextSum+1<s) {
                currSum = nextSum;
                i++;
            } else if(nextSum+1==s){
                int cnt_1 = 0;
                bool onlyOneOrZero = true;
                for(int j=i+1; j<n.size(); j++) {
                    if(n[j] == '1') cnt_1++;
                    else if (n[j] != '0') onlyOneOrZero = false;
                }
                if(onlyOneOrZero && cnt_1 == 1) {
                    break;
                }

                i++;
                while(i<n.size()-1 && n[i]=='0') i++;
                if(i>n.size()-1) break;
                if(n[i]=='0') {
                    ret = "0";
                    break;
                } else {
                    ll ansNum = 1;
                    ll temp = 0;
                    for(int j=i; j<n. size(); j++) {
                        if(n[j]!='0') temp += int(n[j]-'0');
                        if(j!=n.size()-1)temp*=10;
                        ansNum*=10;
                    }
                    ansNum -=temp;
                    ansRet = ansNum;
                    break;
                }
            } else {
                ll ansNum = 1;
                ll temp = 0;
                for(int j=i; j<n.size(); j++) {
                    if(n[j]!='0') temp += int(n[j]-'0');
                    if(j!=n.size()-1)temp*=10;
                    ansNum*=10;
                }
                ansNum -=temp;
                ansRet = ansNum;
                break;
            }
        }
        if(ret == "-1" && ansRet == -1) {
            cout<<0<<endl;
        } else if(ret != "-1"){
            cout<<ret<<endl;
        } else {
            cout<<ansRet<<endl;
        }
    }
    return 0;
}