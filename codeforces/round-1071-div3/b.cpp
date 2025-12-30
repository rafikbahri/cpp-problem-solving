#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <random>
#include <map>

using namespace std;

int solve(vector<int> a){
    int res = 0;
    int n = a.size() - 1;
    vector<int> contributions(n, 0);
    contributions[0] = abs(a[0] - a[1]);
    contributions[n - 1] = abs(a[0] - a[1]);
    for(int i = 1; i < n - 1; i++){
        int contribution = abs(a[i + 1] - a[i]) + abs(a[i] - a[i - 1]);
        contributions[i] = contribution;
    }
    // find max index
    int max = 0;
    int maxIdx = 0;
    for(int i = 0; i < contributions.size(); i++){
        if(max < contributions[i]){
            max = contributions[i];
            maxIdx = i;
        }
    }
    // cout<<"max idx "<<maxIdx<<endl;
    a.erase(a.begin() + maxIdx);

    for(int i = 1; i < n; i++){
        res += abs(a[i - 1] - a[i]);
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    vector<int> a;
    while (t--) {
        int n;
        cin>>n;
        vector<int> a;
        while(n--){
            int elt;
            cin >> elt;
            a.push_back(elt);
        }
        cout<<solve(a)<<endl;
    }
}
