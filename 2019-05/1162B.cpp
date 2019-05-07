// 20190507 22:57 ~ 23:10
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

int n, m;
int arr[3][51][51];

int main() {
    cin>>n>>m;
    rep(k, 1, 3) {
        rep(i, 1, n+1) {
            rep(j, 1, m+1) {
                cin>>arr[k][i][j];
            }
        }
    }
    rep(i, 1, n+1){
        rep(j, 1, m+1) {
            if(arr[1][i][j]>arr[2][i][j]) {
                int temp = arr[1][i][j];
                arr[1][i][j] = arr[2][i][j];
                arr[2][i][j] = temp;
            }
        }
    }
    int can = true;
    rep(i, 1, n+1) {
        rep(j, 1, m+1) {
            if(i!=1) {
                if(arr[1][i-1][j] >= arr[1][i][j] ||
                arr[2][i-1][j] >= arr[2][i][j]) {
                    can = false;
                }
            }
            if(j!=1) {
                if(arr[1][i][j-1] >= arr[1][i][j] ||
                arr[2][i][j-1] >= arr[2][i][j]) {
                    can = false;
                }
            }
        }
    }
    if(can) cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;

}