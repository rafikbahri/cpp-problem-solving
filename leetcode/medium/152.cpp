#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>

using namespace std;

class Solution {
public:
    int calcProduct(vector<int> nums, int idx, vector<int> products){
        if(idx == nums.size() - 1)
            return nums[nums.size() - 1];

        if(products[idx] != -11)
            return products[idx];

        return products[idx] = nums[idx] * calcProduct(nums, idx + 1, products);
    }

    int maxProduct(vector<int> nums) {
        int n = nums.size();
        vector<int> products(n - 1, -11);
        int currentMaxProduct = calcProduct(nums, 0, products);
        int maxProduct = nums[0];
        for(int i = 0; i < n; i ++){
            currentMaxProduct = max(nums[i], calcProduct(nums, i, products));
            maxProduct = max(maxProduct, currentMaxProduct);
        }
        return maxProduct;
    }
};

int main() {
    Solution sol;
    cout<<sol.maxProduct({-2,3,-4})<<endl;
    cout<<sol.maxProduct({3,-1,4})<<endl;
    cout<<sol.maxProduct({-3,0,1,-2})<<endl;
    cout<<sol.maxProduct({1,0,-1,2,3,-5,-2})<<endl;
    cout<<sol.maxProduct({2,-5,-2,-4,3})<<endl;
    return 0;
}