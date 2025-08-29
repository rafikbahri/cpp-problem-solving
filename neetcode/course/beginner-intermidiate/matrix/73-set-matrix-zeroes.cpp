#include <iostream>

using namespace std;

class Solution {
public:
       int getRandomInt32() {
        // static std::random_device rd;
        // static std::mt19937 gen(rd());  // reuse same generator
        // static std::uniform_int_distribution<int> dist(
        //     std::numeric_limits<int>::min(),
        //     std::numeric_limits<int>::max()
        // );
        // return dist(gen);
        return 9;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        bool flagCol = false, flagLine = false;
        int flag = getRandomInt32();
        for(int i=0; i<matrix.size();i++)
            for(int j=0; j<matrix[0].size(); j++)
                if(!matrix[i][j]){
                    if(!i)
                        flagLine = true;
                    if(!j)
                        flagCol = true;
                    matrix[0][j] = flag, matrix[i][0] = flag;
                }
        for(int i=1; i<matrix.size();i++)
            for(int j=1; j<matrix[0].size(); j++)
                if(matrix[0][j] == flag || matrix[i][0] == flag)
                    matrix[i][j] = 0;
        if(flagCol)
            for(int i=0; i<matrix.size();i++)
                matrix[i][0] = 0;
        else
            for(int i=0; i<matrix.size();i++)
                if(matrix[i][0]==flag)
                    matrix[i][0] = 0;
        if(flagLine)
            for(int j=0; j<matrix[0].size(); j++)
                matrix[0][j] = 0;
        else
            for(int j=0; j<matrix[0].size(); j++)
                if(matrix[0][j]==flag)
                    matrix[0][j] = 0;

    }
};

int main(){
    // vector<vector<int>> m = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> m = {
        {1,1,1,1,1},
        {1,1,0,1,1}, // 0s
        {1,1,1,1,1},
        {0,1,1,1,1}, // 0s if(mij=0 && (i=0 || j=0)) mij = flag
        {1,1,1,1,1}};
    Solution* obj = new Solution();
    obj->setZeroes(m);
    for (int i = 0; i < m.size(); i++){
        for(int j = 0;j <m[0].size(); j++)
            cout<<m[i][j]<<", ";
        cout<<endl;
    }
    return 0;
}