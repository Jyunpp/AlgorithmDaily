// 20191225 15:20 ~ 15:40
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

int T, a, b, c, r;
int cl, cr;
int main() {
    cin>>T;
    rep(t, 1, T+1) {
        cin>>a>>b>>c>>r;
        if(a==b) {cout<<0<<endl; continue;}
        if(b<a) {
            int temp = a;
            a = b;
            b = temp;
        }
        int ans = 0;
        cl = c-r;
        cr = c+r;
        if(r==0) {cout<<b-a<<endl; continue;}
        if(cl <= a) {
            if(cr<=a) ans = b-a;
            else if(cr>a && cr <=b) ans = b-cr;
        } else if(cl>a && cl <=b){
            ans += cl-a;
            if(cr<b) ans += b-cr;
        } else {
            ans = b-a;
        }
        cout<<ans<<endl;
    }
}