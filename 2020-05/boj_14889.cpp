// 20200517 21:38 ~ 21:50
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

int n, arr[21][21];
vector<int> team[3];
int ans = 987654321;

void recur(int cnt) {
    if (cnt == n+1) {
        if(team[1].size() == n/2) {
            int team1 = 0, team2 = 0;
            for(int i=0; i<=n/2-2; i++) {
                for(int j=i+1; j<=n/2-1; j++) {
                    team1 += (arr[team[1][i]][team[1][j]] + arr[team[1][j]][team[1][i]]);
                    team2 += (arr[team[2][i]][team[2][j]] + arr[team[2][j]][team[2][i]]);
                }
            }
            ans = min(ans, abs(team1-team2));
        }
        return;
    }

    team[1].push_back(cnt);
    recur(cnt+1);
    team[1].pop_back();

    team[2].push_back(cnt);
    recur(cnt+1);
    team[2].pop_back();
}

int main() {
    cin>>n;
    rep(i, 1, n+1) {
        rep(j, 1, n+1) {
            cin>>arr[i][j];
        }
    }
    recur(1);
    cout<<ans<<endl;
    return 0;
}