// 20200820 23:15 ~ 23:25
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
#include <set>
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
string str;

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        cin>>str;
        
        int regularCnt = 0;
        int openCnt = 0;
        for(char ch : str) {
            if(ch=='(') {
                openCnt++;
            } else {
                if(openCnt) {
                    regularCnt+=2;
                    openCnt--;
                }
            }
        }
        
        cout<<(n-regularCnt)/2<<endl;
    }
    return 0;
}