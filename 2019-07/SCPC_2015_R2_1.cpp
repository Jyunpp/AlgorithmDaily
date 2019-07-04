// 20190705 12:21 ~ 13:40
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

ll Answer;
int n;
ll curr;
int primes[1000001];
vector<int> pv;

ll gcd(ll a, ll b) {
    if(a > b) {
        ll temp = a;
        a = b;
        b = temp;
    }
    return a? gcd(b%a, a) :b;
}

ll getDivisiorsCnt(ll num) {
    if(num==0) return 1;
    ll ret = 1;
    for(auto i : pv) {
        int currCnt = 0;
        while(num % i == 0) {
            currCnt++;
            num /= i;
        }
        if(currCnt) {
            ret *= (currCnt+1);
        }
    }
    return ret;
}

int main(int argc, char** argv) {
    for(int i=2; i<=1000; i++) {
        for(int j=2; j*i <= 1000000; j++) {
            primes[j*i] = 1;
        }
    }
    rep(i, 2, 1000001) {
        if(!primes[i]) pv.pb(i);
    }

	int T, test_case;
	cin >> T;

	for(test_case = 0; test_case  < T; test_case++) {
        cin>>n;
        vector<ll> v;
        rep(i, 0, n) cin>>curr, v.pb(curr);
        
        ll currGCD = v[1] - v[0];
        rep(i, 2, n) currGCD = gcd(currGCD, v[i] - v[i-1]);
        Answer = getDivisiorsCnt(currGCD);

		cout << "Case #" << test_case+1 << endl << Answer << endl;
	}
	return 0;
}