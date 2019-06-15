// 20190616 12:06 ~ 12:27
// problem : https://www.welcomekakao.com/learn/courses/30/lessons/1832
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define pb push_back
#define xx first
#define yy second
#define rep(i, l, r) for(int i=l; i<r; i++)

typedef pair<int, int> P;

int MOD = 20170805;

int dp[500][500];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;

    rep(i, 0, m) rep(j, 0, n) dp[i][j] = 0;
    dp[0][0] = 1;
    rep(i, 0, m) {
        rep(j, 0, n) {
            if(city_map[i][j] == 0) {
               dp[i][j] += (i-1>=0) ? dp[i-1][j] : 0;
               dp[i][j] %= MOD;
               dp[i][j] += (j-1>=0) ? dp[i][j-1] : 0;
               dp[i][j] %= MOD;
            }
            if(city_map[i][j] == 2) {
                if(i-1 >= 0 && city_map[i-1][j] == 0 && i != m-1) {
                    int iter = i;
                    while(iter+1 <= m-1 && city_map[iter][j] == 2) iter++;
                    if(city_map[iter][j] == 0) {
                        dp[iter][j] += dp[i-1][j];
                        dp[iter][j] %= MOD;
                    }
                }
                if(j-1 >= 0 && city_map[i][j-1] == 0 && j != n-1) {
                    int iter = j;
                    while(iter+1 <= n-1 && city_map[i][iter] == 2) iter++;
                    if(city_map[i][iter] == 0) {
                        dp[i][iter] += dp[i][j-1];
                        dp[i][iter] %= MOD;
                    }
                }
            }
        }
    }

    return dp[m-1][n-1];
}

// for test
int main() {
    vector<vector<int>> map_1;
    map_1.pb({0, 0, 0});
    map_1.pb({0, 0, 0});
    map_1.pb({0, 0, 0});
    cout<<"result_1 : "<<solution(3, 3, map_1)<<endl;

    vector<vector<int>> map_2;
    map_2.pb({0, 2, 0, 0, 0, 2});
    map_2.pb({0, 0, 2, 0, 1, 0});
    map_2.pb({1, 0, 0, 2, 2, 0});
    cout<<"result_2 : "<<solution(3, 6, map_2)<<endl;
    return 0;
}