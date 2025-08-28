#include <iostream>

using namespace std;

int dp[46];

int f(int n){
    if(n <= 3){
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] =  f(n-1) + f(n-2);
}

int climbStairs(int n){
    memset(dp, -1, sizeof dp);
    return f(n);
}

int main(){
    cout<<climbStairs(2)<<endl;
    cout<<climbStairs(3)<<endl;
    cout<<climbStairs(4)<<endl;
    cout<<climbStairs(45)<<endl;
    return 0;
}