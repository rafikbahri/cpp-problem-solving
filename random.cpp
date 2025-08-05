#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    // time(nullptr) returns the elapsed seconds since Jan 1 1970 
    srand(time(nullptr)); 
    int randNumber = rand() % 10;
    cout << randNumber << endl;
    return 0;
}