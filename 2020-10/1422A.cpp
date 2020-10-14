#include <iostream>
#include <vector>
using namespace std;

int t;

int main() {
    cin>>t;
    while(t--) {
        vector<int> v(3);
        for(auto &i: v) cin>>i;
        sort(v.begin(), v. end());
        cout<<max(v[2]-v[1]-v[0]+1, 1)<<endl;
    }
    return 0;
}