#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int ans = 0;
        if(s[0] != 's'){
            s[0] = 's';
            ans++;
        }
        if(s[n-1] != 's'){
            s[n-1] = 's';
            ans++;
        }
        
        for(int i = 1; i < n-1; i++) {
            if(s[i] == 'u' && s[i-1] == 'u') {
                ans++;
                s[i] = 's';
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}