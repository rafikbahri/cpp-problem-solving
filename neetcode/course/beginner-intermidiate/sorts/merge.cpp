#include <iostream>

using namespace std;

class Solution {
public:
    // Divide the array in 2 subarrays
    // Recursively, keep dividing until size of arr = 1
    // Merge the subarrays to rebuild the original array 
    // This is a stable sorting algo
    void merge(vector<int>& arr, int s, int m, int e) {
        // Copy the sorted left & right halfs to temp arrays
        vector<int> L = {arr.begin() + s, arr.begin() + m + 1};
        vector<int> R = {arr.begin() + m + 1, arr.begin() + e + 1}; 

        int i = 0; // index for L
        int j = 0; // index for R
        int k = s; // index for arr

        while (i < L.size() && j < R.size()) {
            if (L[i] <= R[j]) {
                arr[k] = L[i++];
            } else {
                arr[k] = R[j++];
            }
            k++;
        }

        // One of the halfs will have elements remaining
        while (i < L.size()) {
            arr[k++] = L[i++];
        }
        while (j < R.size()) {
            arr[k++] = R[j++];
        }
    }

    vector<int> mergeSort(vector<int>& arr, int s, int e) {
        if (e - s + 1 <= 1) {
            return arr;
        }
        // The middle index of the array
        int m = (s + e)  / 2;

        // Sort the left half
        mergeSort(arr, s, m);

        // Sort the right half
        mergeSort(arr, m + 1, e);

        // Merge sorted halfs
        merge(arr, s, m, e);
        
        return arr;
    }
    void debug(vector<int>& arr, int s1, int e1, int s2, int e2){
        int i = s1, j = s2;
        while(i <= e1)
            cout<<arr[i++]<<" ";
        cout<<endl;
        while(j < e2)
            cout<<arr[j++]<<" ";   
    }

};

int main(){
    Solution* obj = new Solution();

    // Test Case 1: Basic unsorted array
    vector<int> nums1 = {3, 1, 4, 2};
    vector<int> res1 = obj->mergeSort(nums1, 0, nums1.size() - 1);
    cout << "Test 1: ";
    for(int v : res1) cout << v << " ";
    cout << endl;

    // Test Case 2: Already sorted array
    vector<int> nums2 = {1, 2, 3, 4, 5};
    vector<int> res2 = obj->mergeSort(nums2, 0, nums2.size() - 1);
    cout << "Test 2: ";
    for(int v : res2) cout << v << " ";
    cout << endl;

    // Test Case 3: Reverse sorted array
    vector<int> nums3 = {5, 4, 3, 2, 1};
    vector<int> res3 = obj->mergeSort(nums3, 0, nums3.size() - 1);
    cout << "Test 3: ";
    for(int v : res3) cout << v << " ";
    cout << endl;

    // Test Case 4: Single element
    vector<int> nums4 = {42};
    vector<int> res4 = obj->mergeSort(nums4, 0, nums4.size() - 1);
    cout << "Test 4: ";
    for(int v : res4) cout << v << " ";
    cout << endl;

    // Test Case 5: Two elements
    vector<int> nums5 = {2, 1};
    vector<int> res5 = obj->mergeSort(nums5, 0, nums5.size() - 1);
    cout << "Test 5: ";
    for(int v : res5) cout << v << " ";
    cout << endl;

    // Test Case 6: Duplicates
    vector<int> nums6 = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    vector<int> res6 = obj->mergeSort(nums6, 0, nums6.size() - 1);
    cout << "Test 6: ";
    for(int v : res6) cout << v << " ";
    cout << endl;

    // Test Case 7: All same elements
    vector<int> nums7 = {7, 7, 7, 7, 7};
    vector<int> res7 = obj->mergeSort(nums7, 0, nums7.size() - 1);
    cout << "Test 7: ";
    for(int v : res7) cout << v << " ";
    cout << endl;

    // Test Case 8: Negative numbers
    vector<int> nums8 = {-3, 1, -4, 2, 0, -1};
    vector<int> res8 = obj->mergeSort(nums8, 0, nums8.size() - 1);
    cout << "Test 8: ";
    for(int v : res8) cout << v << " ";
    cout << endl;

    // Test Case 9: Large array with random order
    vector<int> nums9 = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};
    vector<int> res9 = obj->mergeSort(nums9, 0, nums9.size() - 1);
    cout << "Test 9: ";
    for(int v : res9) cout << v << " ";
    cout << endl;

    // Test Case 10: Empty array (edge case)
    vector<int> nums10 = {};
    if(!nums10.empty()) {
        vector<int> res10 = obj->mergeSort(nums10, 0, nums10.size() - 1);
        cout << "Test 10: ";
        for(int v : res10) cout << v << " ";
        cout << endl;
    } else {
        cout << "Test 10: Empty array - skipped" << endl;
    }

    return 0;
}