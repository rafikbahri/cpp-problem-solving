#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int maxLength = 0;
        for(int i = s.size() - 1; i > 0; i--){
            if(s[i] == ' '){
                if(maxLength > 0){
                    break;
                }
                else{
                    continue;
                }
            }
            maxLength++;
        },
        return maxLength;
    }
};

int main() {
    Solution sol;
    cout<<sol.lengthOfLastWord("   fly me   to   the moon  ")<<endl;
    cout<<sol.lengthOfLastWord("Hello World")<<endl;
    cout<<sol.lengthOfLastWord("luffy is still joyboy")<<endl;
    cout<<sol.lengthOfLastWord("Today is a nice day")<<endl;
    
    // string str = "   fly me   to   the moon  ";
    // cout<<str.substr(3, str.size() - 3)<<endl;
    // cout<<str.substr(3, 6)<<endl;
    // cout<<str.substr(12, str.size() - 12)<<endl;
    return 0;
}