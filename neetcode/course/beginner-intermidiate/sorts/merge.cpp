#include <iostream>

using namespace std;

class Solution {
public:

vector<int> mergeSort(vector<int> arr, int s, int e){

    // arr size is 1, we stop and callback
    if(e - s + 1 <= 1)
        return arr;

    // split array on 2
    int m = (s + e) / 2;

    // sort first half
    mergeSort(arr, s, m);
    // sort second half
    mergeSort(arr, m + 1, e);

    merge(arr, s, m, e);

    return arr;
}

// needs to pass addr because we change the arr in place
void merge(vector<int>& arr, int s, int m, int e){

    // build left vector -> create left with elmts from arr {iterator fromIdx, iterator + nbElmts}
    vector<int> left = {arr.begin() + s, arr.begin() + m + 1};

    // build right vector
    vector<int> right = {arr.begin() + m +1, arr.begin() + e + 1};

    int i = 0;
    int j = 0;
    int k = s;
    while(i < left.size() && j < right.size()){
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while(i < left.size())
        arr[k++] = left[i++];
    
    while(j < right.size())
        arr[k++] = right[j++];
}
};

void show(vector<int> v){
    for(int i : v)
        cout<<i<<" ";
    cout<<endl;
}

int main(){
    Solution* obj = new Solution();

    vector<int> test = {3, 2, 4, 1, 6};
    show(test);
    // show(test);
    // vector<int> subTest = {test.begin(), test.begin() + 2};
    // show(subTest);
    // vector<int> allTest = {test.begin(), test.end()};
    // show(allTest);
    vector<int> res = obj-> mergeSort(test, 0, test.size() - 1);

    show(res);
    return 0;
}