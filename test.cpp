#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 1;
    int m = 2;
    cout << "n = " << n << " m = " << m << endl;
    n = n + m;
    m = n - m;
    n = n - m;
    cout << "n = " << n << " m = " << m << endl;
    return 0;
}