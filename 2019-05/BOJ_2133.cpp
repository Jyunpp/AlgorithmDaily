#include <iostream>
using namespace std;

long long dp[100][1 << 6];

long long solve(int index, int state);
int n;
int main() {
	cin >> n;
    // 홀수 불가
	if (n % 2 == 1) { cout << 0 << endl; return 0; }
	long long ans = solve(1, 0);
	cout << ans << endl;
	//cin >> n;
	return 0;
}

long long solve(int index, int state) {
	//cout << "solve(" << index << ", " << state << ") 호출!" << endl;
	//메모제이션
	long long &ret = dp[index][state];
	if (ret) { return ret; }
	if (index == 3*n + 1) {
		//기저사례 : 꽉채웠을 경우
		if (state == 0) { return 1; }
		//기저사례 : over해서 꽉 채운 경우.
		return 0;
	}
	//이미 놓여진 경우
	if (state & 1) { return ret = solve(index + 1, state >> 1); }
	//두 가지 경우 모두 가능
	if ((index % 3) != 0) {
		//가로로 놓기, 세로로 놓기.
		//★ 가로는 무조건 놓을 수 있지만.. 세로는 밑에칸이 안놓여져 있는걸 확인 해야함..★
		if ((state & 2) == 0) {
			return ret = solve(index + 1, (state | 9) >> 1) + solve(index + 2, (state | 3) >> 2);
		}
		return ret = solve(index + 1, (state | 9) >> 1);
	}
	//한 가지 경우만 가능.
	else {
		//가로로 놓기
		return ret = solve(index + 1, (state | 9) >> 1);
	}
}