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
map<P, int> visited;
int debugArr[6][6];

int getKey(vector<P> &pv) {
	int key = 0;
	for (P p: pv) {
		int shiftCnt = 5 * (p.xx-1) + p.yy - 1;
		key += (1<<shiftCnt);
	}

	return key;
}

void recur(vector<P> &path, int y, int x) {
	visited[{getKey(path), y*100+x}]++;
	if(path.size() == 7) {
		int sCnt = 0;
		for (P p: path) sCnt += arr[p.xx][p.yy];

		if (sCnt >= 4) {
			// for DEBUG
			// int prevSz = ans.size();
			ans.insert(getKey(path));
			// int nextSz = ans.size();
			// if(prevSz != nextSz) {
			// 	rep(i, 1, 6) rep(j, 1, 6) debugArr[i][j] = 0;
			// 	for(P p : path) {
			// 		debugArr[p.xx][p.yy] = 1;
			// 		// cout<<"("<<p.xx<<", "<<p.yy<<"), ";
			// 	}
			// 	cout<<endl<<"answer.."<<getKey(path)<<endl;
			// 	rep(i, 1, 6) {
			// 		rep(j, 1, 6) cout<<debugArr[i][j];
			// 		cout<<endl;
			// 	}
			// }
		}
		return ;
	}

	rep(i, 0, 4) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny <= 5 && nx <= 5 && nx*ny) {
			bool isInPath = false;
			for (P p: path) {
				if (p.xx == ny && p.yy == nx) {
					isInPath = true;
					break;
				}
			}
			if (!isInPath) {
				vector<P> nextPath(path);
				nextPath.pb({ny, nx});
				for(P p : nextPath) {
					if (visited[{getKey(nextPath), p.xx*100+p.yy}] == 0){
						recur(nextPath, p.xx, p.yy);
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
			recur(v, i, j);
		}
	}

	cout<<ans.size()<<endl;
	return 0;
}