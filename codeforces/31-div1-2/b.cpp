#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <iomanip>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<string> a;
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            a.push_back(s);
        }

        string ans = a[0];
        for(int i = 1; i < n; i++) {
            if(ans+a[i]<a[i]+ans) {
                ans = ans+a[i];
            }
            else {
                ans = a[i]+ans;
            }
        }
        cout << ans << endl;

    }
}