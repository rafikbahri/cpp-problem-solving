#include <iostream>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            for(int j=i+1;j<nums.size();j++)
                if(nums[i] == nums[j])
                    return true;
       return false;
    }
};

int main(){
    // Solution* obj = new Solution();
    // vector<int> nums1 = {1,2,3,1};
    // string output = obj->containsDuplicate(nums1) ? "true" : "false";
    // cout<<output<<endl;
    int x = 1, y = 2;
    swap(x, y);
    cout<<x<<endl;
    cout<<y<<endl;
    return 0;
}