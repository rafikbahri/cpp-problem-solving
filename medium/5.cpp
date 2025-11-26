#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrom(int start, int end, string& s, vector<vector<int>>& cache){
        if(s[start] != s[end])
            return false;
        if(start >= end)
            return true;
        if(cache[start][end] != -1) return cache[start][end];
        return cache[start][end] = isPalindrom(start + 1, end - 1, s, cache);
    }

    pair<int,int> solve(string& s){
        pair<int, int> longest = {0, 0};
        vector<vector<int>> cache(s.size(), vector<int>(s.size(), -1));
        for(int i = 0; i < s.size(); i++)
            for(int j = i; j < s.size(); j++)
                if(isPalindrom(i, j, s, cache))
                    if((j - i) > (longest.second - longest.first))
                        longest = {i, j};
        return longest;
    }

    string longestPalindrome(string s) {
        pair<int, int> res = solve(s); 
        return s.substr(res.first, res.second - res.first + 1);
    }
};

int main(){
    Solution *obj = new Solution();
    cout<<obj->longestPalindrome("babad")<<endl;
    cout<<obj->longestPalindrome("bbc")<<endl;
    delete obj;
    return 0;
}
