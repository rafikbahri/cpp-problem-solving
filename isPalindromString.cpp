#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include<string>

using namespace std;

class Solution {
    private:
        string prepare(string str){
            std::transform(str.begin(), str.end(), str.begin(),
                [](unsigned char c){ return std::tolower(c); });
            str.erase(remove_if(str.begin(), str.end(), [](char c) {
                return !isalnum(c);
            }), str.end());

            return str;
        }
    public:
        bool isPalindrome(string s) {
            string str = prepare(s);
            cout<<"prepare :: "<<str<<endl;
            int left = 0, right = str.size() - 1;
            while(left <= right){
                if(str[left] == str[right]){
                    left++;
                    right--;
                    continue;
                }
                return false;
            }
            return true;
        }
};

int main() {
    Solution sol;
    string str;

    cout<<sol.isPalindrome("A man, a plan, a canal: Panama")<<endl;
    cout<<sol.isPalindrome(".,")<<endl;
    cout<<sol.isPalindrome("0P")<<endl;

    return 0;
}