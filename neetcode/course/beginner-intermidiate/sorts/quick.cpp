#include <iostream>

using namespace std;

class Solution {
    public:
        vector<int> quickSort(vector<int>& arr, int start, int end){
            if(end - start + 1 <= 1)
                return arr;
            
            int pivot = arr[end];
            int j = start; 
            for(int i = start; i < end; i++)
                if(arr[i] <= pivot){
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                    j++;
                }


            arr[end] = arr[j];
            arr[j] = pivot;
            quickSort(arr, start, j - 1);
            quickSort(arr, j + 1, end);

            return arr;
        }
        
        void show(vector<int> arr){
            for(int i = 0; i < arr.size(); i++)
                printf("[%d] = %d | ", i, arr[i]);
            cout<<endl;
        }
};

int main(){
    Solution* obj = new Solution();
    vector<int> in1 = {6, 2, 4 , 1, 3};
    obj->show(in1);
    obj->quickSort(in1, 0, in1.size() - 1);
    obj->show(in1);

    vector<int> in2 = {1, 2, 3, 4 , 5};
    obj->show(in2);
    obj->quickSort(in2, 0, in2.size() - 1);
    obj->show(in2);

    return 0;
}