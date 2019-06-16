// 20190616 18:09 ~ 18:14
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

int t, n, a;
int arr[3];

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        rep(i, 0, 3) arr[i] = 0;
        while(n--) {
            cin>>a; 
            arr[a%3]++;
        }
        int mini = min(arr[1], arr[2]);
        int maxi = max(arr[1], arr[2]);
        cout<< arr[0] + mini + (maxi-mini)/3<<endl;
    }
    return 0;
}