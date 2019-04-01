// 20190401 11:42 ~ 11:47
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

int n, v1, v2, t1, t2;
int main() {
    cin>>n>>v1>>v2>>t1>>t2;
    int ret = v1*n+t1*2 - v2*n-t2*2;
    if(ret==0){
        cout<<"Friendship"<<endl;
    } else if (ret<0) {
        cout<<"First"<<endl;
    } else {
        cout<<"Second"<<endl;
    }
    return 0;
}