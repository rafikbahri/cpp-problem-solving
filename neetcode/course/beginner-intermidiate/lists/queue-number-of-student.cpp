#include <iostream>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int swap = 0;
        bool took = false;
        int i = 0;
        while(swap<students.size() && students.size()>0){
            if(students[0] == sandwiches[0]){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                swap = 0;
                cout<<"students"<<endl;
                print(students);
                cout<<"sandwichs"<<endl;
                print(sandwiches);
            } else { 
                students.push_back(students[i]);
                students.erase(students.begin());
                swap++;
            }
        }
        return students.size();
    }

    void print(vector<int> arr){
        for(int a : arr){
            cout<<a<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Solution* obj = new Solution();
    // vector<int> students  = {1,1,0,0};
    // vector<int> sandwichs = {0,1,0,1};
    vector<int> students  = {1,1,1,1};
    vector<int> sandwichs = {1,1,1,0};
    // vector<int> students  = {1,1,1,0,0,1};
    // vector<int> sandwichs = {1,0,0,0,1,1};
    cout<<obj->countStudents(students, sandwichs)<<endl;
    // obj->print(students);
    // students.erase(students.begin());
    return 0;
}