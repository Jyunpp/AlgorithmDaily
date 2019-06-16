// 20190616 18:15 ~ 18:45
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

int n, a, sets;
vector<int> arr[7];
int numToIdx[50];
int nums[7] = {-1, 4, 8, 15, 16, 23, 42};
int iters[7] = {-1, 0, 0, 0, 0, 0, 0};

int main() {
    rep(i, 1, 7) numToIdx[nums[i]] = i;

    cin>>n;
    rep(i, 0, n) {
        cin>>a;
        arr[numToIdx[a]].pb(i);
    }

    bool finished = false;
    rep(i, 1, 7) if(arr[i].size()==0) finished = true;

    while(!finished) {
        rep(i, 2, 7) {
            if(finished) break;
            int currIter = iters[i];
            while(arr[i-1][iters[i-1]] > arr[i][currIter]) {
                if(currIter == arr[i].size()-1) {
                    finished = true;
                    break;
                }
                currIter++;
            }
            iters[i] = currIter;
        }
        if(finished) break;
        sets++;
        rep(i, 1, 7) {
            iters[i]++;
            if(iters[i] == arr[i].size()) finished = true;
        }
    }

    cout<<n - sets*6<<endl;
    return 0;
}