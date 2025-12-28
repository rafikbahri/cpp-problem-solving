#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>

using namespace std;

class Solution {
    public:
        void solve(int n) {
            vector<vector<int>> ans(n,vector<int>(n, 1));
            if(n % 2 == 0) {
                for(int i = 0; i < n / 2 ; i++){
                    for(int j = 0; j < n; j++)
                        ans[i][j] = 0;
                }
            }
            else {
                for(int i = 0; i < n; i++){
                    if(i % 2 == 0){
                        ans[i][n - i - 1] = 0;
                    }else{
                        ans[i][n - i - 1] = 1;
                    }
                }
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n - i - 1; j++){
                        ans[i][j] = 0;
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++)
                    cout<<ans[i][j];
                cout<<endl;
            }
        }
};

int main() {
    int n;
    cin>>n;
    Solution sol;
    sol.solve(n);
    return 0;
}