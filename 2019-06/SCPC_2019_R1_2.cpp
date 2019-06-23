// 20190621 18:33 ~ 19:03
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

int R, S, E, n;
int l[1001], r[1001], h[1001];
double ans;

int main(int argc, char** argv) {
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++) {
		cin>>R>>S>>E>>n;
		ans = (E-S);
		rep(i, 1, n+1) {
			cin>>l[i]>>r[i]>>h[i];
			double arcLen;
			if(h[i] >= R) {
				ans += (2*(h[i]-R));
				ans -= (2*R);
				arcLen = M_PI*R;
			} else {
				double doubleR = R;
				ans -= 2 * sqrt((doubleR*doubleR) - ((doubleR - h[i])*((doubleR - h[i]))));
				double theta = acos((doubleR - h[i])/doubleR);
				arcLen = 2*doubleR*theta;
			}
			ans += arcLen;
		}
		printf("Case #%d\n%.12f\n", test_case+1, ans);
	}
	return 0;
}