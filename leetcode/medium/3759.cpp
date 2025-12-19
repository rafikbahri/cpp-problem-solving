#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
    public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int occ = 1;
        for(int i = 1; i < nums.size(); i++){
            int curr = nums[i];
            if(curr == nums[i - 1])
                occ++;
            else{
                occ = 1;
                if((i - 1 + k) < n)
                    res++;
            }
        }
        return res;
    }
};

int main() {



    return 0;
}