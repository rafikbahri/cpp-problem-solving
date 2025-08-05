#include <iostream>

using namespace std;

class DynamicArray {
public:
    int capacity = 2;
    int size = 0;
    int *val = new int[capacity];

    DynamicArray(int capacity) {
        val = new int[capacity];
    }

    int get(int i) {
        return val[i];
    }

    void set(int i, int n) {
        
    }

    void pushback(int n) {
        val[size] = n;
    }

    int popback() {
        int res = val[size-1];
    }

    void resize() {

    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};

int main(){

    return 0;
}