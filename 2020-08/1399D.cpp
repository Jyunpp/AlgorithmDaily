// 20200816 23:00 ~ 23:14
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
int main() {
    cin>>t;
    while(t--) {
        queue<int> binary[2];
        string ans = "";
        string arr;
        cin>>n;
        cin>>arr;

        int subsequence = 0;
        for(char ch : arr) {
            int curr = ch - '0';
            if (binary[!curr].empty())  {
                binary[curr].push(++subsequence);
                ans += (" " + to_string(subsequence));
            } else {
                int currSubsequence = binary[!curr].front();
                binary[!curr].pop();
                binary[curr].push(currSubsequence);
                ans += (" " + to_string(currSubsequence));
            }
        }

        cout<<subsequence<<endl<<ans.substr(1)<<endl;
    }
    
    return 0;
}