// 20190623
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
int n;

int main(int argc, char** argv) {
	int T, test_case;
	cin >> T;

	for(test_case = 0; test_case  < T; test_case++) {
        cin>>n;
        Answer = n+1;

        // 제곱인자 이상 존재할 때
        for(int i=2; i*i<n; i++) {
            int r = n%i;
            int currN = n/i;
            bool can = true;
            while(i < currN) {
                if(r != currN%i) {
                    can = false;
                    break;
                }
                currN /= i;
            }
            if(currN != r) can = false;
            if(can) {
                Answer = i;
                break;
            }
        }

        // 제곱인자 이상 없을 때
        for(int i=1; i*i <=n; i++) {
            if(n%i!=0) continue;
            int num = n/i -1;
            if(num > i && Answer > num)  Answer = num;
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}
	return 0;
}