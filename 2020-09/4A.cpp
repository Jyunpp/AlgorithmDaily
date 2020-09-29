// 20200928 17:05 ~ 17:08
#include <iostream>
using namespace std;

int w;

int main() {
    cin>>w;
    if(w>=4) {
        w-=2;
        if(w%2 == 0) {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;

    return 0;
}