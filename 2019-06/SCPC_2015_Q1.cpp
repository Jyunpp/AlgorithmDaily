// 20190617 22:56 ~ 23:05
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

int Answer;

int main(int argc, char** argv) {
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++) {
		Answer = 0;
        int n, k;
        cin>>n;
        vector<int> v;
        v.pb(0);
        rep(i, 0, n) {
            int c; cin>>c;
            v.pb(c);
        }
        cin>>k;
        int curr = v[0];
        rep(i, 1, n+1) {
            if(v[i] - v[i-1] > k) {
                Answer = -1;
                break;
            }
            if(v[i] - curr > k) {
                Answer++;
                curr = v[i-1];
            }
        }
        if(curr != v[n] && Answer != -1) Answer++;
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}
	return 0;
}