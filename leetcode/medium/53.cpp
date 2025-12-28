#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentMax = nums[0];
        int maxSum = nums[0];

        int start = 0;
        int currentSubArraySize = 1;
        int maxSubArraySize = 1;

        bool newMax = false;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > currentMax + nums[i]){
                currentMax = nums[i];
                newMax = true;
                currentSubArraySize = 1;
            }else{
                currentMax = currentMax + nums[i];
                currentSubArraySize++;
            }
            if(currentMax >= maxSum){
                if(newMax){
                    start = i;
                    newMax = false;
                    maxSubArraySize=1;
                }else{
                    maxSubArraySize++;
                    maxSubArraySize = max(maxSubArraySize, currentSubArraySize);
                }
                maxSum = currentMax;
            }
        }
        cout<<"input arrray size :: "<<nums.size()<<endl;
        cout<<"start :: "<<start<<endl;
        cout<<"max subarray size :: "<<maxSubArraySize<<endl;
        vector<int> subarray = vector<int>{nums.begin() + start, nums.begin() + start + maxSubArraySize};
        cout<<"result subarray :: {";
        for(int nb : subarray)
            cout<<nb<<", ";
        cout<<"}"<<endl;
        cout<<"max sum :: ";
        return maxSum;
    }
};

int main(){
    Solution sol;
    int t;
    cin>>t;
    int totalCases = t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            int elt;
            cin>>elt;
            a[i] = elt;
        }
        cout<<"Test "<<totalCases - t<<endl;
        cout<<sol.maxSubArray(a)<<endl;
        cout<<"================================================="<<endl;
    }
    return 0;
}