#include <iostream>

using namespace std;

class MinStack {
public:
    vector<int> arr;
    vector<int> mins;
    MinStack() {
        
    }
    
    void push(int val) {
        if(arr.size() == 0){
            mins.push_back(val);
        }else if (val <= mins[mins.size()-1]){
            mins.push_back(val);
        }
        arr.push_back(val);
    }
    
    void pop() {
        if(mins[mins.size()-1] == top()){
            mins.pop_back();
        }
        arr.pop_back();
    }
    
    int top() {
        return arr[arr.size()-1];
    }
    
    int getMin() {
        return mins[mins.size()-1];
    }

    void print(){
        for(int v: arr){
            cout << v << endl;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 int main(){
    MinStack *minStack = new MinStack();
    // TC 2
    // minStack->push(-2);
    // minStack->push(0);
    // minStack->push(-1);
    // minStack->print();
    // cout<< "Min: " << minStack->getMin()<<endl; 
    // cout << "Top: " << minStack->top() << endl; 
    // minStack->pop();
    // cout<< "Min: " << minStack->getMin()<<endl;
    minStack->push(0);
    minStack->push(1);
    minStack->push(0);
    cout<< "Min: " << minStack->getMin()<<endl; // 0
    minStack->pop(); // 0 1
    cout<< "Min: " << minStack->getMin()<<endl; // 0
    minStack->pop(); // 0 
    cout<< "Min: " << minStack->getMin()<<endl; // 0
    minStack->pop(); // null
    minStack->push(-2); // -2 
    minStack->push(-1); // -2 -1
    minStack->push(-2); // -2 -1 -2
    cout<< "Min: " << minStack->getMin()<<endl; // -2
    minStack->pop(); // -2 -1
    cout << "Top: " << minStack->top() << endl; // -1
    cout<< "Min: " << minStack->getMin()<<endl; // -2
    minStack->pop(); // -2
    cout<< "Min: " << minStack->getMin()<<endl; // -2
    minStack->pop();
    return 0;
}