#include <iostream>

using namespace std;

class Solution {
public:
    int sqrt(int x){
        if(x <= 0)
            return 0;
        if(x <= 3)
            return 1;
        int end = x/2;
        int start = 1;
        int mid = (start + end) / 2;
        while(start<=end){
            if((long) mid * mid < (long) x)
                start = mid + 1;
            else if((long) mid * mid == (long) x)
                return mid;
            else
                end = mid - 1;
            mid = (start + end) / 2;
        }
        return mid;
    }
};

int main(){
    Solution* obj = new Solution();
    cout<<"res: "<<obj->sqrt(9)<<endl;
    cout<<"res: "<<obj->sqrt(4)<<endl;
    cout<<"res: "<<obj->sqrt(3)<<endl;
    cout<<"res: "<<obj->sqrt(6)<<endl;
    cout<<"res: "<<obj->sqrt(10)<<endl;
    cout<<"res: "<<obj->sqrt(8)<<endl;
    cout<<"res: "<<obj->sqrt(2147395599)<<endl;

    return 0;
}