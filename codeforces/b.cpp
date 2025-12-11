#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <random>
#include <map>
#include <fstream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int n;
        cin >> n >> s;
        // s+=s;
        int res = 0;
        int last1 = -1;
        int leading0=0;
        while (leading0 < s.size() and s[leading0] == '0') {
            leading0++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                // last0 = i;
            }
            else {
                last1 = i;
            }
            if (s[i] == '0' and last1 != -1) {
                // cout << "At " << i << " and last1 is " << last1 << endl;
                res = max(res, i - last1);
            }
        }
        // cout << "leading0 is " << leading0 << " and last1 is " << last1 << endl;
        // cout << "n-last1-1 is " << n-last1-1 << endl;
        // cout << "res is " << res << endl;
        if (leading0){
            if(last1 + res>=n) {
                //circular
                int x = (last1 + res)%n;
                // cout << "x is " << x << endl;
                // cout << "leading0 is " << leading0 << endl;
                // cout << "leading0-x is " << leading0-x << endl;
                res+=max(0, leading0-x-1);
            }
            else res+=leading0;
        }
        cout << res << endl;
    }
}
