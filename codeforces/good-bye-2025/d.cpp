#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        if(m > n/2){
            cout << -1 << endl;
            continue;
        }
        sort(a.begin(), a.end());
        int survivors = n;
        int deaths = n - m;
        vector<pair<int, int>> ans;
        int idx = 0;    
        for(int i = 0 ; i < (n - 2*m); i++){
            ans.push_back({i + 1, i});
            // cout<< "attack phase 1 :: "<< idx + 1 << " " << idx << endl;
        }
        // 
        for(int i = n - 1; i >= (n - m); i--){
            // cout<< "attack phase 2 :: "<< i << " " << i - m << endl;
            ans.push_back({i, i - m});
        }
        if(m==0){
            cout << ans.size()-2 << endl;
            cout << a[ans[0].second].second + 1 << " " << a[ans[0].first].second + 1 << endl;
            for(int i = 1; i < ans.size()-2; i++){
                auto p = ans[i];
                cout << a[p.first].second + 1 << " " << a[p.second].second + 1 << endl;
            }
            continue;
        }
        cout << ans.size() << endl;
        for(auto p : ans){
            cout << a[p.first].second + 1 << " " << a[p.second].second + 1 << endl;
        }
    }
    return 0;
}