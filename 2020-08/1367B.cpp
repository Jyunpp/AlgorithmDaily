// 20200831 13:20 ~ 13:25
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
int arr[40];

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        int odds = 0;
        int evens = 0;
        int wrong = 0;
        for(int i=0; i<n; i++) {
            cin>>arr[i];
            if (arr[i]%2) evens++;
            else odds++;
            if (arr[i]%2 != i%2) wrong++;
        }

        bool can = (n%2==0 && odds==evens) || (n%2==1 && odds==evens+1);
        if (!can) {
            cout<<-1<<endl;
        } else {
            cout<<wrong/2<<endl;
        }
    }

    return 0;
}