#include<iostream>

using namespace std;

class Solution{
    public:
        void bucketSort(vector<int>& nums) {
            int max = *max_element(nums.begin(), nums.end());
            int min = *min_element(nums.begin(), nums.end());
            int rangeSize = max - min + 1;
            vector<int> buckets(rangeSize, 0);
        
            // Map value to bucket index: value - min
            for(int i = 0; i < nums.size(); i++){
                buckets[nums[i] - min]++;
            }
        
            int idx = 0;
            for(int n = 0; n < buckets.size(); n++){
                for(int i = 0; i < buckets[n]; i++){
                    nums[idx] = n + min;  // Map bucket index back to value
                    idx++;
                }
            }    
        }

        void show(vector<int> arr){
            for(int i = 0; i < arr.size(); i++)
                printf("[%d] %d | ", i, arr[i]);
            cout<<endl;
        }
};

int main(){
    Solution* obj = new Solution();
    // vector<int> in1 = {1, 0, 2, 0, 0, 1, 2, 0, 1};
    // cout<<"Input: "<<endl;
    // obj->show(in1);
    // obj->bucketSort(in1);
    // cout<<"Output: "<<endl;
    // obj->show(in1);
    // vector<int> in1 = {3, 0, 2, 0, 0, 1, 7, 1000000, 1};
    vector<int> in1 = {1, 1};
    cout<<"Input: "<<endl;
    obj->show(in1);
    obj->bucketSort(in1);
    cout<<"Output: "<<endl;
    obj->show(in1);
}