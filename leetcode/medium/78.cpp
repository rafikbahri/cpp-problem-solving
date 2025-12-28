#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
    private:
        vector<int> nums;
        vector<vector<int>> res;

        void solve(int idx, vector<int>& curr){
            if(idx >= this->nums.size())
                return;

            curr.push_back(this->nums[idx]);
            solve(idx + 1, curr);
            this->res.push_back(curr);
            curr.pop_back();
            solve(idx + 1, curr);
        }

    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            this->nums = nums;
            this->res.push_back({});
            vector<int> curr = {};
            solve(0, curr);
            return this->res;
        }
};

int main() {
    vector<int> sub1 = {1, 2, 3};
    Solution sol;
    vector<vector<int>> res = sol.subsets(sub1);

    for(vector<int> s : res){
        for(int v : s)
            cout<<v<<" ";
        cout<<endl;
    }
    return 0;
}