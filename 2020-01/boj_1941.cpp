// 20200123 17:00 ~ 17:50
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

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int arr[6][6];
set<int> ans;
map<int, int> visited;

int getKey(vector<P> &pv) {
	int key = 0;
	for (P p: pv) {
		int shiftCnt = 5 * (p.xx-1) + p.yy - 1;
		key += (1<<shiftCnt);
	}

	return key;
}

void recur(vector<P> &path) {
	visited[getKey(path)]++;
	if(path.size() == 7) {
		int sCnt = 0;
		for (P p: path) sCnt += arr[p.xx][p.yy];

		if (sCnt >= 4) {
			ans.insert(getKey(path));
		}
		return ;
	}
	for(P p : path) {
		rep(i, 0, 4) {
			int ny = p.xx + dy[i];
			int nx = p.yy + dx[i];
			if(ny <= 5 && nx <= 5 && nx*ny) {
				bool isInPath = false;
				for(P pIn: path) {
					if (pIn.xx == ny && pIn.yy == nx) {
						isInPath = true;
						break;
					}
				}
				if (!isInPath) {
					vector<P> nextPath(path);
					nextPath.pb({ny, nx});
					if (visited[getKey(nextPath)] == 0){
						recur(nextPath);
					}
				}
			}
		}
	}
}

int main() {
	rep(i, 1, 6) {
		rep(j, 1, 6) {
			char ch; 
			scanf(" %c", &ch);
			arr[i][j] = (ch=='S');
		}
	}
	
	rep(i, 1, 6) {
		rep(j, 1, 6) {
			vector<P> v;
			v.pb({i, j});
			recur(v);
		}
	}

	cout<<ans.size()<<endl;
	return 0;
}