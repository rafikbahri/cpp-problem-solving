#include<iostream>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int close = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i : nums)
            cout<<" "<<i<<" ";
        cout<<endl;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                
                auto lb = lower_bound(nums.begin() + j, nums.end(), target - nums[i] - nums[j]);
                cout<<" target "<<target<<" nums(i) "<<nums[i]<<" nums(j) "<<nums[j]<<" lb "<<*lb<<" close "<<close<<endl;
                if(abs(target - *lb - nums[i] - nums[j]) < close){
                    close = abs(target - *lb - nums[i] - nums[j]);
                    cout<<" close became "<<close<<endl;
                }

                auto ub = upper_bound(nums.begin() + j, nums.end(), target - nums[i] - nums[j]);
                cout<<" target "<<target<<" nums(i) "<<nums[i]<<" nums(j) "<<nums[j]<<" ub "<<*ub<<" close "<<close<<endl;
                if(abs(target - *ub - nums[i] - nums[j]) <= close){
                    close = abs(target - *ub - nums[i] - nums[j]);
                    cout<<" close became "<<close<<endl;
                }
            }
        }
        return close;
    }
};

int main(){
    Solution *obj = new Solution();
    vector<int> test1 = {-1,2,1,-4};
    int target = 1;

    cout<<obj->threeSumClosest(test1, target);
    delete obj;
    return 0;
}
