// 20190614
// problem : https://www.welcomekakao.com/learn/courses/30/lessons/42894
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define pb push_back
#define xx first
#define yy second
#define rep(i, l, r) for(int i=l; i<r; i++)

typedef pair<int, int> P;

int n;
int arr[51][51];
bool finished = false;
int answer = 0;

void removeBlock(P board1, P board2, P board3, P board4) {
    arr[board1.xx][board1.yy] = 0;
    arr[board2.xx][board2.yy] = 0;
    arr[board3.xx][board3.yy] = 0;
    arr[board4.xx][board4.yy] = 0;
    return ;
}

bool sameCheckAndSet(int board1, int board2, int board3, int board4) {
    if(board1 == 0) return false;
    if(board1 == board2 && board1 == board3 && board1 == board4) {
        finished = false;
        answer++;
        return true;
    }
    return false;
}

void proceed(P p1, P p2, P p3, P p4) {
    if(sameCheckAndSet(arr[p1.xx][p1.yy], arr[p2.xx][p2.yy], arr[p3.xx][p3.yy], arr[p4.xx][p4.yy])) {
        removeBlock(p1, p2, p3, p4);
    }
}

int solution(vector<vector<int>> board) {
    n = board.size();
    rep(i, 0, n) rep (j, 0, n) arr[i+1][j+1] = board[i][j];

    while(!finished) {
        finished = true;
        // ㅁ
        // ㅁ
        rep(i, 1, n+1) {
            int y = 0;
            while( (!arr[y+1][i]) && (y<n)) y++;
            if(y<=1 || y==n) continue;
            
            proceed({y+1, i}, {y+1, i+1}, {y, i+1}, {y-1, i+1});
            proceed({y+1, i}, {y+1, i-1}, {y, i-1}, {y-1, i-1});
        }
        // ㅁㅁ
        rep(i, 1, n) {
            int y = 0;
            while( (!arr[y+1][i]) && (!arr[y+1][i+1]) && (y<n)) y++;
            if(y==0 || y==n) continue;

            proceed({y+1, i}, {y+1, i+1}, {y+1, i-1}, {y, i-1});
            proceed({y+1, i}, {y+1, i+1}, {y+1, i+2}, {y, i+2});
        }
        // ㅁ ㅁ
        rep(i, 1, n-1) {
            int y = 0;
            while( (!arr[y+1][i]) && (!arr[y+1][i+2]) && (y<n)) y++;
            if(y==0 || y==n) continue;

            proceed({y, i+1}, {y+1, i}, {y+1, i+1}, {y+1, i+2});
        }
    }
    return answer;
}

// for test
int main() {
    vector<vector<int>> board;
    board.pb(vector<int>{0,0,0,0,0,0,0,0,0,0});
    board.pb(vector<int>{0,0,0,0,0,0,0,0,0,0});
    board.pb(vector<int>{0,0,0,0,0,0,0,0,0,0});
    board.pb(vector<int>{0,0,0,0,0,0,0,0,0,0});
    board.pb(vector<int>{0,0,0,0,0,0,4,0,0,0});
    board.pb(vector<int>{0,0,0,0,0,4,4,0,0,0});
    board.pb(vector<int>{0,0,0,0,3,0,4,0,0,0});
    board.pb(vector<int>{0,0,0,2,3,0,0,0,5,5});
    board.pb(vector<int>{1,2,2,2,3,3,0,0,0,5});
    board.pb(vector<int>{1,1,1,0,0,0,0,0,0,5});
    cout<<"result : "<<solution(board);
    return 0;
}