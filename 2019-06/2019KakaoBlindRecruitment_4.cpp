// 20190611
// problem : https://www.welcomekakao.com/learn/courses/30/lessons/42891
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define pb push_back
#define xx first
#define yy second
#define rep(i, l, r) for(int i=l; i<r; i++)

typedef long long ll;

int solution(vector<int> food_times, long long k) {
    vector<pair<int, ll>> v;
    rep(i, 0, food_times.size()) v.pb({i, food_times[i]});
    sort(v.begin(), v.end(), [](pair<int, ll> a, pair<int, ll> b) {
        return a.yy != b.yy ? a.yy < b.yy : a.xx < b.xx;
    });

    ll sz = food_times.size();
    int iter = 0;
    ll loopCnt = 0;
    while(true) {
        if(iter == sz) {
            return -1;
        }
        ll needTimeForNext = (v[iter].yy-loopCnt) * (sz - iter);
        if(needTimeForNext <= k) {
            loopCnt = v[iter].yy;
            food_times[v[iter].xx] = 0;
            iter++;
            k-= needTimeForNext;
        } else {
            ll q = k / needTimeForNext;
            k %= needTimeForNext;
            for(int i = iter; i < sz; i++) {
                food_times[v[i].xx] -= (q + loopCnt);
            }
            vector<int> idxs;
            for(int i = iter; i< sz; i++) {
                if(food_times[v[i].xx]) idxs.pb(v[i].xx + 1);
            }
            sort(idxs.begin(), idxs.end()) ;
            return idxs[k%idxs.size()];
        }
    }
}

// for test
int main() {
    vector<int> food_times{3, 1, 2};
    for(int i=1; i<=10; i++) {
        cout<<i<<" : "<<solution(food_times, i)<<endl;
    }
    return 0;
}