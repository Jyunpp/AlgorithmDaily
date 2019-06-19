// 20190619 02:17 ~ 02:44
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
int arr[1001][1001];
int cnt[1001][1001];
int dy[5] = {9, 0, -1, 0, 1};
int dx[5] = {9, 1, 0, -1, 0};
int reflect_1[5] = {9, 4, 3, 2, 1};
int reflect_2[5] = {9, 2, 1, 4, 3};

bool isOut(int y, int x) {
    return (y*x == 0 || x > n || y > n);
}

int main(int argc, char** argv) {
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++) {
		Answer = 0;
        
        cin>>n;
        for(int i=n; i>=1; i--) {
            rep(j, 1, n+1) {
                char ch; cin>>ch;
                arr[i][j] = (int)(ch - '0');
                cnt[i][j] = 0;
            }
        }
        
        int direction = 1;
        int y = n, x = 1;
        while(true) {
            Answer += (cnt[y][x]++ == 0 && arr[y][x]);

            if(arr[y][x] == 1) direction = reflect_1[direction];
            if(arr[y][x] == 2) direction = reflect_2[direction];
            y += dy[direction];
            x += dx[direction];
            
            if(isOut(y, x)) break;
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}
	return 0;
}