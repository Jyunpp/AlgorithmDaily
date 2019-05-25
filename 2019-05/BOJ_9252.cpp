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

#define LU 1
#define L 2
#define U 3

string str[2];
int len[2];
int dp[1001][1001];
int back[1001][1001];

void printLCS(int i, int j) {
    if(i==0 || j==0) return;
    switch (back[i][j]) {
        case LU:
            printLCS(i-1, j-1);
            cout<<str[0][i-1];
            break;
        case L:
            printLCS(i, j-1);
            break;
        case U:
            printLCS(i-1, j);
            break;
        default:
            break;
    }
    return ;
}

int main() {
    rep(i, 0, 2) cin>>str[i], len[i] = str[i].size();

    rep(i, 1, len[0]+1) {
        rep(j, 1, len[1]+1) {
            if(str[0][i-1] == str[1][j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                back[i][j] = LU;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(dp[i-1][j] >= dp[i][j-1]) {
                    back[i][j] = U;
                } else {
                    back[i][j] = L;
                }
            }
        }
    }
    cout<<dp[len[0]][len[1]]<<endl;
    printLCS(len[0], len[1]);

    string st = "asd";
    cout<<st.substr(0, 2);
    return 0;
}