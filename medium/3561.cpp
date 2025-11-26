#include <iostream>
#include <utility>
#include <stack>

using namespace std;

class Solution {
public:
string resultingString(string s) {
    stack<char> stck;
    for(int i = 0; i < s.size(); i++){
        if(stck.size() == 0){
            stck.push(s[i]);
            continue;
        }
        if(abs(stck.top() - s[i]) == 1 || (abs(stck.top() - s[i]) == 25 && (s[i] == 'a' || s[i] == 'z'))){
            stck.pop();
        } else{
            stck.push(s[i]);
        }
    }
    string res = "";
    while(!stck.empty())
        res += stck.top(), stck.pop();
    
    reverse(res.begin(), res.end());
    return res;
}
};



int main(){
    Solution *obj = new Solution();
    string s = "wcabababababababab";
    // string s = "tz";
    // string s = "adcb";
    cout<<obj->resultingString(s)<<endl;
    return 0;
}