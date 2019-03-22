// 20190322 23:04 ~ 23:11
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

int nums[3];

int main() {
    string s;
    cin>>s;
    int iter = 0;
    int curr = 0;
    rep(i, 0, s.size()) {
        if(s[i]=='+'||s[i]=='=') {
            nums[iter] = curr;
            iter++;
            curr = 0;
        } else {
            curr++;
        }
    }
    nums[iter] = curr;
    if(nums[0] + nums[1] == nums[2]) {
        cout<<s<<endl;
        return 0;
    }
    if(nums[0]+nums[1] +2 == nums[2]) {
        nums[2]--;
        nums[0]++;
    }
    else if (nums[0]+nums[1] -2 == nums[2]
    && (nums[0]>1 || nums[1]>1)){
        if(nums[0]>1) {
            nums[0]--;
        }else {
            nums[1]--;
        }
        nums[2]++;
    } else {
        cout<<"Impossible"<<endl;
        return 0;
    }
    rep(i, 0, nums[0]) {
        cout<<"|";
    }
    cout<<"+";
    rep(i, 0, nums[1]) {
        cout<<"|";
    }
    cout<<"=";
    rep(i, 0, nums[2]) {
        cout<<"|";
    }
    return 0;
}