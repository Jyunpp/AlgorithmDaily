// 20200925 23:15 ~ 23:17
#include <iostream>
using namespace std;

typedef long long ll;

int n, m, a;

int main() {
    cin>>n>>m>>a;
    cout<<((ll)(n/a + ((n%a)>0))) * ((ll)(m/a + ((m%a)>0))) <<endl;
    
    return 0;
}