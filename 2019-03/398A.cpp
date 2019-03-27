// 20190326 22:55 ~ 23:05 +1,
// 20190327 10:20 ~ 11:05 +4
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

const int MAXINT = 9E8;
const int MININT = -9E8;
const long long MAXLL = 9E18;
const long long MINLL = -9E18;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;

ll a, b;
ll ret = MINLL;
int retNumOfSegB;

// start from accum(2)
bool accum(int numOfSegB) {
    if(numOfSegB-1 > a ) return false;
    ll currRet = powll(a-numOfSegB+2, 2)
        - (b%numOfSegB) * powll((b/numOfSegB) + 1, 2)
        - (numOfSegB - (b%numOfSegB)) * powll((b/numOfSegB), 2)
        + (numOfSegB - 2);
    // cout<<numOfSegB<<", "<<currRet<<endl;
    if(currRet > ret) {
        ret = currRet;
        retNumOfSegB = numOfSegB;
    }
    return true;
}

int main() {
    cin>>a>>b;
    if(!a) {
        cout<<powll(b, 2)*-1<<endl;
        rep(i, 0, b) cout<<"x";
    }
    else {
        int numOfSegB = 2;
        while(accum(numOfSegB++)) {}
        cout<<ret<<endl;
        rep(i, 0, b/retNumOfSegB + (b%retNumOfSegB != 0)) {
            cout<<"x";
        } b -= (b%retNumOfSegB != 0);
        rep(i, 0, a - (retNumOfSegB-2)) cout<<"o";
        for(int j=2; j<retNumOfSegB; j++) {
            rep(i, 0, b/retNumOfSegB + (b%retNumOfSegB != 0)) {
            cout<<"x";
            } b -= (b%retNumOfSegB != 0);
            cout<<"o";
        }
        rep(i, 0, b/retNumOfSegB + (b%retNumOfSegB != 0)) {
            cout<<"x";
        } b -= (b%retNumOfSegB != 0);
    }
    return 0;
}