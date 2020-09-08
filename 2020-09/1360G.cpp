// 20200908 21:50 ~ 22:00 ~ 20:15
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

int t, n, m, a, b;
int arr[51][51];

void fillAndPrintAns() {
    int currY = 1;
    int currX = 1;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=b; j++) {
            arr[currY][currX] = 1;
            currY++;
            if (currY>n) currY-=n;
        }
        currX++;
    }

    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>m>>a>>b;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                arr[i][j] = 0;
            }
        }

        if (n*a!=m*b) cout<<"NO"<<endl;
        else fillAndPrintAns();
    }
    return 0;
}