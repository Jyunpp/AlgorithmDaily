// 20190615 09:44 ~ 09:52
// problem : https://www.welcomekakao.com/learn/courses/30/lessons/1829
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

bool visited[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0 ,-1, 1};

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    queue<P> q;
    int currSize;
    rep(i, 0, m) rep(j, 0, n) visited[i][j] = false;
    
    rep(i, 0, m) {
        rep(j, 0, n) {
            if(!visited[i][j] && picture[i][j]) {
                q.push({i, j});
                visited[i][j] = true;
                number_of_area++;
                currSize = 1;
                
                while(!q.empty()) {
                    int y = q.front().xx;
                    int x = q.front().yy;
                    q.pop();
                    rep(k, 0, 4) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if(ny>=0 && nx>=0 && ny<m && nx<n && !visited[ny][nx] && picture[ny][nx] == picture[i][j]) {
                            q.push({ny, nx});
                            visited[ny][nx] = true;
                            currSize++;
                        }
                    }
                }
                max_size_of_one_area = max(max_size_of_one_area, currSize);
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

// for test
int main() {
    vector<vector<int>> arr;
    arr.pb(vector<int>{1,1,1,0});
    arr.pb(vector<int>{1,2,2,0});
    arr.pb(vector<int>{1,0,0,1});
    arr.pb(vector<int>{0,0,0,1});
    arr.pb(vector<int>{0,0,0,3});
    arr.pb(vector<int>{0,0,0,3});
    vector<int> result = solution(6, 4, arr);
    cout<<"result : "<<result[0]<<", "<<result[1]<<endl;
    return 0;
}