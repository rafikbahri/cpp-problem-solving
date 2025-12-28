#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>

using namespace std;

class Solution {
    private:
        vector<vector<int>> res;
        vector<int> candidates;
        int target;
        
        void solve(int idx, vector<int> curr, int total) {
            if(total == target){
                res.push_back(curr);
                return;
            }
    
            if(idx >= candidates.size() || total > target)
                return;
    
            curr.push_back(candidates[idx]);
            // reuse ith element
            solve(idx, curr, total + candidates[idx]);
            // backtrack
            curr.pop_back();
            // move the idx so we don't move ith element anymore -> avoid redundant sets
            solve(idx + 1, curr, total);

        }
    
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            this->candidates = candidates;
            this->target = target;
            this->res.clear();
            solve(0, {}, 0);
            return res;
        }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    // vector<int> candidates = {2,3,5};
    // int target = 8;


    vector<vector<int>> res = sol.combinationSum(candidates, target);

    for(vector<int> v : res){
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
