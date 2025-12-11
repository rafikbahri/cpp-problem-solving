#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <random>
#include <map>
#include <fstream>

using namespace std;

int solve(vector<int> odds, vector<int> evens, vector<int> prefix_odds, vector<int> prefix_evens, int k) {
    if (odds.empty()) return 0;
    int sum = odds[0];
    k--;
    // take the first odd and keep stacking evens
    if(evens.size()>=k) {
        for (int i = 0; i < k; i++) {
            sum += evens[i];
        }
        return sum;
    }
    else {
        int extraOdds = k - evens.size(); // operations to spare before stacking evens 
        // if((extraOdds + 1) % 2 == 0)
        //     return 0;
        if(extraOdds + 1 > odds.size())
            return 0;
        int evensCount = 0;
        
        return ;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), odds, evens;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) {
                evens.push_back(a[i]);
            }
            else {
                odds.push_back(a[i]);
            }
        }

        sort(odds.begin(), odds.end());
        sort(evens.begin(), evens.end());
        reverse(odds.begin(), odds.end());
        reverse(evens.begin(), evens.end());
        vector<int> prefix_odds(odds.size()), prefix_evens(evens.size());
        if (odds.size()) {
            prefix_odds[0] = odds[0];
            for (int i = 1; i < odds.size(); i++) {
                prefix_odds[i] = prefix_odds[i-1] + odds[i];
            }
        }
        if (evens.size()) {
            prefix_evens[0] = evens[0];
            for (int i = 1; i < evens.size(); i++) {
                prefix_evens[i] = prefix_evens[i-1] + evens[i];
            }
        }
        for (int i = 1; i <=n ; i++) {
            cout << solve(odds, evens, prefix_odds, prefix_evens, i) << " ";
        }
        cout << endl;
    }
}