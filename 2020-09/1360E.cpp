// 20200903 21:07 ~ 21:34 ~ 21:38
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

int t, n;
int arr[51][51];
int dy[2] = {1, 0};
int dx[2] = {0, 1};

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        rep(i, 1, n+1) {
            rep(j, 1, n+1) {
                char ch; cin>>ch;
                arr[i][j] = ch=='1';
            }
        }
        bool ans = true;
        rep(i, 1, n){
            rep(j, 1, n) {
                if(arr[i][j] == 1) {
                    bool can = false;
                    queue<P> q;
                    q.push({i, j});
                    vector<vector<int>> v(n+1, vector<int>(n+1, 0));
                    v[i][j]=1;
                    while(!q.empty()) {
                        P curr = q.front();
                        int y = curr.xx;
                        int x = curr.yy;
                        q.pop();
                        int ny, nx;
                        for(int k=0; k<=1; k++) {
                            ny = y+dy[k];
                            nx = x+dx[k];

                            if(ny>n || nx>n) continue;
                            if(arr[ny][nx]) {
                                if(ny==n || nx ==n) {
                                    can = true;
                                    break;
                                }
                                if(!v[ny][nx]) q.push({ny, nx});
                                v[ny][nx]=1;
                            }
                        }
                        if (can) break;
                    }

                    if(!can) {
                        ans = false;
                        break;
                    }
                }
            }
            if (!ans) break;
        }

        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}