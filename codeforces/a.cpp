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
    int ops = 0;
    for(int i = 0; i< a.size() - 1; i++)
        for(int j = i + 1; j<a.size(); j++){
            if(a[i] > a[j] && a[j]*a[i] != 0){
                a[j] = 0;
                ops++;
            }
                
        }
    return ops;
}

int main(){
//    ifstream cin("in.txt");
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
