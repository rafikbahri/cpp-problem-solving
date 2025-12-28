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
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        for(int i = 1; i < n-1; i++)
            if(arr[i] == -1)
                arr[i] = 0;
        if(arr[0] == -1){
            if(arr[n-1] == -1)
                arr[0] = arr[n-1] = 0;
            else
                arr[0] = arr[n - 1];
        }else if(arr[n-1] == -1){
            if(arr[0] == -1)
                arr[0] = arr[n-1] = 0;
            else
                arr[n-1] = arr[0];
        }
        cout<<abs(arr[n-1] - arr[0])<<endl;
        for(int a : arr){
            cout<<a<<" ";
        }
        cout<<endl;
    }
}
