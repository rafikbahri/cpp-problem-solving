#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include<string>

using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> c(n);
        for(int i = 0; i < n; i++){
            int elt;
            cin>>elt;
            a[i] = elt;
        }
        for(int i = 0; i < n; i++){
            int elt;
            cin>>elt;
            c[i] = elt;
        }
        // for(int i = 0; i < n; i++){
        //     cout<<"a("<<i<<") :: "<<a[i]<<endl;
        //     cout<<"c("<<i<<") :: "<<c[i]<<endl;
        // }
        // find the most costly elt and delete it
        int minimumCost = 0;
        int lessCostly = a[0] * c[0];
        // int lessCostlyIdx = 0;
        int maxC = c[0];
        int lessCostlyIdx = 0;
        while(a.size() > 0){
            // lessCostly = a[0] * c[0];
            // lessCostlyIdx = 0;
            // for(int i = 1; i < a.size(); i++){
            //     if((a[i] * c[i]) <= lessCostly || a[i] >= a[i - 1]){
            //         lessCostly = a[i] * c[i];
            //         lessCostlyIdx = i;
            //     }
            // }
            int lessCostly = a[0] * c[0];
            // int lessCostlyIdx = 0;
            int minC = c[0];
            int lessCostlyIdx = 0;
            for(int i = 1; i < a.size(); i++){
                if(minC > c[i]){
                    minC = c[i];
                    lessCostlyIdx = i;
                    lessCostly = a[i] * c[i];
                }
            }
            // cout<<"minC :: "<<minC<<endl;
            minimumCost += lessCostly;
            a.erase(a.begin() + lessCostlyIdx);
        }
        cout<<minimumCost<<endl;
    }
    return 0;
}
