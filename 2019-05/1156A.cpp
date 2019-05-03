// 20190504 01:43 ~ 01:53
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

int n, ret;
int ppre, pre, curr;
int arr[4][4];

int main() {
    arr[1][2] = arr[2][1] = 3;
    arr[1][3] = arr[3][1] = 4;
    arr[2][3] = arr[3][2] = 10000;
    cin>>n;
    cin>>pre; 
    rep(i, 1, n) {
        cin>>curr;
        ret -= (ppre==3 && pre==1 && curr==2);
        ret += arr[pre][curr];
        ppre = pre;
        pre = curr;
    }
    if(ret >= 10000) {
        cout<<"Infinite"<<endl;
    } else {
        cout<<"Finite"<<endl<<ret<<endl;
    }
    return 0;
}