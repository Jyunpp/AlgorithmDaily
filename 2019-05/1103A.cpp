// 20190514 19:09 ~ 19:24
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

int arr[2];
string s;

int main() {
    cin>>s;
    for(char ch : s) {
        if(ch=='0') {
            cout<<3<<" "<<1+(arr[0]%4)<<endl;
            arr[0]++;
        } else {
            cout<<1<<" "<<1+2*(arr[1]%2)<<endl;
            arr[1]++;
        }
    }
    return 0;
}