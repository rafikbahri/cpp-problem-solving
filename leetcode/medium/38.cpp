#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        
        return countAndSay(n - 1) + "1";
    }
};

int main() {
    Solution sol;
    cout<<sol.countAndSay(3)<<endl;
    return 0;
}