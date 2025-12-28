#include <iostream>
#include <vector>

using namespace std;

int getMSB(long long n) {
    if (n == 0) return -1;
    int pos = 0;
    while (n >>= 1) {
        pos++;
    }
    return pos;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int> a(n), b(n);
        int sa = 0, sb = 0;
        int maxMsb = -1;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            sa ^= a[i];
            maxMsb = max(maxMsb, getMSB(a[i]));
        }
        for(int i = 0; i < n; i++){
            cin>>b[i];
            sb ^= b[i];
            maxMsb = max(maxMsb, getMSB(b[i]));
        }
        if((sb^sa) == 0){
            cout<<"Tie"<<endl;
            continue;
        }
        cout<<"sb^sa :: "<<(sb^sa)<<endl;

        int ctlajsi = 0, ctlmai = 0;
        int last = -1;
        for(int i = 1; i <=n; i++){
            cout<<i-1<<" - msb ai :: "<<getMSB(a[i - 1])<<" - ai :: "<<a[i - 1]<<endl;
            cout<<i-1<<" - msb bi :: "<<getMSB(b[i -1])<<" - bi :: "<<b[i -1]<<endl;
            if(a[i - 1] == b[i - 1])
                continue;
            if(getMSB(a[i - 1]) != maxMsb && getMSB(b[i - 1]) != maxMsb)
                continue;
            if(getMSB(a[i - 1]) == getMSB(b[i - 1]))
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
