// 20191201 22:00 ~ 22:58
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

int n,m,a,b,c;
int arr[101][101];

int getNextInt(vector<int> &v) {
    int t = (int)('z' - 'a' + 1);
    int temp = (1<<t)-1; // 1로 채움
    int input = 0; // 1을 1에, 2를 10에, 3을 100에 ... 매칭하여 킨 것들을 반환 후 모음
    for(int i : v) {
        int j = 1<<(i-1);
        input |= j;
    }
    temp ^= input; // 둘을 xor 연산하여, 반대로 빈자리를 1로 켜서 남김
    int ttemp = temp & (temp-1); // 빈자리중 마지막 칸을 (우측부터 봤을 때 처음으로 나타나는 1을) 끔
    int result =  temp ^ ttemp; // 둘을 xor 하여 마지막 반지리를 색출 (우측부터 봤을 때 첫 빈자리)
    return log2(result)+1; // 그 자리에 해당하는 숫자를 리턴 (반대로 1을 1로, 10이면 2로, 100이면 3으로..)
}


int main() {
    cin>>n>>m>>a>>b>>c;
    int ii = 1;
    int jj = 1;
    if (n*m & 1) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    if (n & 1) {
        ii = 2;
        int temp = 0;
        for(int i=1; i<=m-1; i+=2) {
            arr[1][i] = arr[1][i+1] = temp+1;
            temp = (temp+1)%2;
            a--;
        }
    }
    if (m & 1) {
        jj = 2;
        int temp = 0;
        for(int i=1; i<=n-1; i+=2) {
            arr[i][1] = arr[i+1][1] = temp+1;
            temp = (temp+1)%2;
            b--;
        }
    }
    if (a<0 || b<0) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int i=ii; i<=n-1; i+=2) {
        for(int j=jj; j<=m-1; j+=2) {
            vector<int> prev;
            if (a>=2) {
                if (i-1 >=1) {
                    prev.pb(arr[i-1][j]);
                    if (j+1 <=m) prev.pb(arr[i-1][j+1]);
                }
                if (j-1 >=1) prev.pb(arr[i][j-1]);
                
                int next = getNextInt(prev);
                arr[i][j] = arr[i][j+1] = next;
                
                prev.pb(next);
                if (j-1 >=1) prev.pb(arr[i+1][j-1]);
                arr[i+1][j] = arr[i+1][j+1] = getNextInt(prev);
                a-=2;
            } else if (b>=2) {
                if (i-1 >=1) prev.pb(arr[i-1][j]);
                if (j-1 >=1) {
                    prev.pb(arr[i][j-1]);
                    if (i+1 <= n) {
                        prev.pb(arr[i+1][j-1]);
                    }
                }

                int next = getNextInt(prev);
                arr[i][j] = arr[i+1][j] = next;
                
                prev.pb(next);
                if (i-1 >= 1) prev.pb(arr[i-1][j+1]);
                arr[i][j+1] = arr[i+1][j+1] = getNextInt(prev);
                b-=2;
            } else if (c>=1) {
                if (i-1 >=1) {
                    prev.pb(arr[i-1][j]);
                    if (j+1 <=m) prev.pb(arr[i-1][j+1]);
                }
                if (j-1 >=1) {
                    prev.pb(arr[i][j-1]);
                    if (i+1 <= n) {
                        prev.pb(arr[i+1][j-1]);
                    }
                }
                
                int next = getNextInt(prev);
                arr[i][j] = arr[i][j+1] = arr[i+1][j] = arr[i+1][j+1] = getNextInt(prev);
                c--;
            } else {
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cout<<(char)('a' - 1 + arr[i][j]);
        }
        cout<<endl;
    }
    return 0;
}