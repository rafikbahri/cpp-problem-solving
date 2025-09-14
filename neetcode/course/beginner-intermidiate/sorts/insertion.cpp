#include <iostream>

using namespace std;

class Solution {
public:
    // Compare elem to the next elem
    // if the next elem is less then elem, then swap
    // do it until the next elem is greater then elm
    // in other terms, as long as next elem is less then the current element, keep pushing it to the back of the list
    // make sure you don't go out of bound at the first elem
    // best = O(n)
    // worst = O(n^2)
    void insertionSort(vector<int>& arr){
        for(int i = 0; i < arr.size() - 1; i ++){
            int j = i + 1;
            while(j > 0 && arr[j - 1] > arr[j]){
                int tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
                j--;
            }
        }
    }

    void insertionSortV2(vector<int>& arr){
        for(int i = 1; i < arr.size(); i++){
            int j = i - 1;
            while(j >= 0 && arr[j + 1] < arr[j]){
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
                j--;
            }
        }
    }
};

int main(){
    Solution* obj = new Solution();
    vector<int> nums1 = {1,2,3,1};
    obj->insertionSortV2(nums1);
    for(int v : nums1){
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}