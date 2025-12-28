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
        vector<int> a(n), b(n);
        int sa = 0, sb = 0;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            sa += a[i];
        }
        for(int i = 0; i < n; i++){
            cin>>b[i];
            sb += b[i];
        }
        if((sb + sa)%2 == 0){
            cout<<"Tie"<<endl;
            continue;
        }
        int ctlajsi = 0, ctlmai = 0;
        int last = -1;
        for(int i = 1; i <=n; i++){
            if(a[i - 1] == b[i - 1])
                continue;
            if(i % 2){
                last = 0;
            }else{
                last = 1;
            }
        }
        if(last == 0){
            cout<<"Ajisai"<<endl;
        }else if(last == 1){
            cout<<"Mai"<<endl;
        }
    }
}
