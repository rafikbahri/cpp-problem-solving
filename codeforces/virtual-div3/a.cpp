#include <iostream>
#include <vector>

using namespace std;

int solve(int l, int a, int b){
    return 0;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        int res = 0;
        for(int moo = 0; moo <= n / 4; moo++){
            int s = 4*moo;
            if((n - s) % 2 == 0)
                res++;
        }
        cout<<res<<endl;
    }
}
