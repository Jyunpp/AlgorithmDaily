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

string names[4];
map<string, int> nameToIdx;
double iWinJ[4][4];
double iDrawJ[4][4];
double iLoseJ[4][4];
double ret[4];

int getIndexOfName(string str) {
	return nameToIdx[str];
}

typedef struct _Status {
	int win[4] = {0,};
	double probability = 1.0;
} Status;

//iVsJResult 0 iWin, 1 draw, 2 iLose
void recur(Status status, int i, int j, int iVsJResult) {
	// iVsJResult 따라 승리포인트 및 확률 누적
	if(iVsJResult == 0) {
		status.win[i] +=3;
		status.probability *= iWinJ[i][j];
	} else if(iVsJResult == 1) {
		status.win[i] ++;
		status.win[j] ++;
		status.probability *= iDrawJ[i][j];
	} else {
		status.win[j] +=3;
		status.probability *= iLoseJ[i][j];
	}

	// 상태저장 및 종료 or 다음 재귀
	int nextI, nextJ;
	if(j==3) {
		if(i==2) {
			// 상태저장 
			vector<P> v;
			rep(k, 0, 4) v.pb({status.win[k], k});
			sort(v.begin(), v.end(), [](P a, P b){return a.xx > b.xx;});
			if(v[0].xx == v[1].xx && v[0].xx == v[2].xx && v[0].xx == v[3].xx) {
				rep(k, 0, 4) ret[v[k].yy] += (status.probability/2.0);
			}
			else if(v[0].xx == v[1].xx && v[0].xx == v[2].xx) {
				rep(k, 0, 3) ret[v[k].yy] += (status.probability*2.0/3.0);
			}
			else if(v[1].xx == v[2].xx && v[1].xx == v[3].xx) {
				ret[v[0].yy] += (status.probability);
				rep(k, 1, 4) ret[v[k].yy] += (status.probability/3.0);
			} 
			else if(v[1].xx == v[2].xx) {
				ret[v[0].yy] += (status.probability);
				rep(k, 1, 3) ret[v[k].yy] += (status.probability/2.0);
			}
			else {
				rep(k, 0, 2) ret[v[k].yy] += (status.probability);
			}
			// 종료
			return ;
		}
		// 재귀
		else {
			nextI = i+1;
			nextJ = nextI+1;
		}
	}
	//재귀
	else {
		nextI = i;
		nextJ = j+1;
	}
	recur(status, nextI, nextJ, 0);
	recur(status, nextI, nextJ, 1);
	recur(status, nextI, nextJ, 2);
}

int main() {
	rep(i, 0, 4) {
		cin>>names[i];
		nameToIdx[names[i]] = i;
	}
	rep(k, 0, 6) {
		string a, b;
		double w, d, l;
		cin>>a>>b>>w>>d>>l;
		int i = getIndexOfName(a);
		int j = getIndexOfName(b);
		iWinJ[i][j] = iLoseJ[j][i] = w;
		iDrawJ[i][j] = iDrawJ[j][i] = d;
		iLoseJ[i][j] = iWinJ[j][i] = l;
	}
	Status status;
	status.probability = 1.0;
	recur(status, 0, 1, 0);
	recur(status, 0, 1, 1);
	recur(status, 0, 1, 2);
	rep(i, 0, 4) {
		cout<<ret[i]<<endl;
	}
	return 0;
}