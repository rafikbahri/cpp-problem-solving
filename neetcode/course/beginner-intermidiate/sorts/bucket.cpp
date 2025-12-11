#include<iostream>

using namespace std;

class Solution{
    public:
        void bucketSort(vector<int>& arr){
            // calculate range
            int max = *max_element(arr.begin(), arr.end());
            int min = *min_element(arr.begin(), arr.end());
            int rangeSize = max - min + 1;

            cout<<"max: "<<max<<endl;
            cout<<"min: "<<min<<endl;
            cout<<"range size: "<<rangeSize<<endl;
            vector<int> buckets(rangeSize, 0);

            // create buckets
            for(int i = 0; i < arr.size(); i++)
                buckets[arr[i]]++;

            int idx = 0;
            for(int n = 0; n<buckets.size(); n++){
                for(int i=0; i < buckets[n]; i++){
                    arr[idx] = n;
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
    vector<int> in1 = {3, 0, 2, 0, 0, 1, 7, 1000000, 1};
    cout<<"Input: "<<endl;
    obj->show(in1);
    obj->bucketSort(in1);
    cout<<"Output: "<<endl;
    obj->show(in1);
}