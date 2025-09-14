#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> in(n+1, 0); // size, value to init -> always size n+1
        for(vector<int> edge : edges){
            in[edge[1]]++;
        }
        vector<int> res;
        for(int v : in){
            res.push_back(v);
        }
        return res;
    }
};

int main(){
    vector<vector<int>> test = {{0,1},{0,2},{2,5},{3,4},{4,2}};
    Solution* obj = new Solution();
    vector<int> res = obj->findSmallestSetOfVertices(6, test);
    return 0;
}