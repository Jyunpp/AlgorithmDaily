// 20200201 23:30 ~ 23:44
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

int n;
int primes[1000001];
vector<int> pv;

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
        vector<int> v;
        int curr = n;
        int i=0;
        while(pv[i] <= curr && i <= pv.size()-1) {
            if (curr % pv[i] == 0) {
                int cnt = 1;
                while(curr % ll(pow(pv[i], cnt)) == 0) {
                    v.pb(int(pow(pv[i], cnt)));
                    curr /= int(pow(pv[i], cnt));
                    cnt++;
                    if (v.size() == 2 && curr != v[0] && curr != v[1] && curr != 1) {
                        v.pb(curr);
                        break;
                    }
                }
            }
            i++;
            if (v.size() == 3) break;
            
        }
        if(v.size() == 3) {
            cout<<"YES"<<endl<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
        } else {
            cout<<"NO"<<endl;
        }
	}
	return 0;
}