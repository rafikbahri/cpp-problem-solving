#include <iostream>
#include <cstdlib>

using namespace std;

vector<int> getConcatenation(vector<int>& nums) {
    vector<int> ans;
    for(int i=0; i < 2 * nums.size(); i++){
        ans.push_back(nums[i%nums.size()]);
    }
    return ans;
}

int main(){
    vector<int> nums = {1,4,1,2};
    vector<int> res = getConcatenation(nums);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<endl;
    }
    return 0;  
}