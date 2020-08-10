// 20200810 22:50 ~ 23:15
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

int n, t;
int arr[200001];
int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        rep(i, 1, n+1) {
            int a; cin>>a;
            arr[i] = a;
        }
        if(n==1) cout<<0<<endl;
        else {
            int curr = arr[n];
            int idx = n;

            while(idx>=1) {
                int next = arr[idx];
                if (next < curr) {
                    break;
                } else {
                    curr = next;
                    idx--;
                }
            }

            while(idx>=1) {
                int next = arr[idx];
                if (next > curr) {
                    break;
                } else {
                    curr = next;
                    idx--;
                }
            }

            cout<<idx<<endl;
        }
    }
    return 0;
}