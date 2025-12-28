#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[3] = {1, 2, 3};
    int idx =  0;
    cout<<"sizeof(arr) in bytes == number of elements * size of one element :: "<<sizeof(arr)<<endl;
    cout<<"sizeof(arr)/sizeof(arr[0]) :: "<<sizeof(arr)/sizeof(arr[0])<<endl;
    if(idx < (sizeof(arr)/sizeof(arr[0]))&& arr[idx] != 0)
        cout<<"ok :: "<<arr[idx]<<endl;
    else 
        cout<<"nok :: "<<arr[idx]<<endl;
    return 0;
}