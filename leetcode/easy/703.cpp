#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <string>

using namespace std;

class KthLargest {
public:
    int k;
    vector<int> nums;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
        // sort the initial vector
        sort(this->nums.begin(), this->nums.end());
    }

  
    int add(int val) {
        // add the new elt in the sorted array -> binary search
        int left = 0, right = this->nums.size() - 1;
        int mid = (left + right) / 2;
        // cout<<"mid :: "<<mid<<endl;
        // cout<<"left :: "<<left<<endl;
        // cout<<"right :: "<<right<<endl;
        while(left < right){
            if(val > this->nums[mid])
                left = mid + 1;
            else if (val < this->nums[mid])
                right = mid - 1;
            else
                break;
            mid = (left + right) / 2;
        }
        // cout<<"insert position :: "<<mid<<endl;
        // cout<<"left :: "<<left<<endl;
        // cout<<"right :: "<<right<<endl;
        this->nums.push_back(val);
        // cout<<"array sorted and before insert val :: ";
        // for(int num : nums)
        //     cout<<num<<" ";
        // cout<<endl;
        int i = this->nums.size() - 1;
        while(i > mid && nums[i] < nums[i - 1]){
            // swap
            int tmp = this->nums[i];
            this->nums[i] = this->nums[i - 1];
            this->nums[i - 1] = tmp;
            i--;
        }
        // cout<<"array sorted and inserted val :: ";
        // for(int num : nums)
        //     cout<<num<<" ";
        // cout<<endl;
        return this->nums[this->nums.size() - this->k];
    }
};
    

int main() {
    // vector<int> arr2 = {5,-1};
    // KthLargest* kthLargest = new KthLargest(3, arr2);
    // cout<<kthLargest->add(2)<<endl;
    vector<int> arr = {4, 5, 8, 2};
    KthLargest* kthLargest = new KthLargest(3, arr);
    cout<<kthLargest->add(3)<<endl; // return 4
    cout<<kthLargest->add(5)<<endl; // return 5
    cout<<kthLargest->add(10)<<endl; // return 5
    cout<<kthLargest->add(9)<<endl; // return 8
    cout<<kthLargest->add(4)<<endl; // return 8
    // kthLargest->show();
    priority_queue<int> testHeap;
    cout<<"empty heap size :: "<<testHeap.size()<<endl;
    testHeap.push(1);
    cout<<"heap size :: "<<testHeap.size()<<endl;
    delete kthLargest;
    return 0;
}