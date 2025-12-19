#include <iostream>
#include <vector>

using namespace std;

int solve(int l, int a, int b){
    int s = a;
    int max = s;
    bool passed = false;
    while(s != a || !passed){
        passed = true;
        s = (s + b) % l;
        if(max < s)
            max = s;
    }
    return max;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int l, a, b;
        cin>>l>>a>>b;
        cout<<solve(l, a, b)<<endl;
    }
}
