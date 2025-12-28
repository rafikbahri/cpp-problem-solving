#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <string>
#define max(a,b) (a>b?a:b)
#define ll long long
using namespace std;

    int main() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vector<ll> a(n+2);
            vector<ll> suffix_sum(n+2,0);
            vector<ll> prefix_sum(n+2,0);
            for(int i = 1; i <= n; i++) {
                cin >> a[i];
                if(i == 1) prefix_sum[i] = a[i];
                else prefix_sum[i] = prefix_sum[i-1] + abs(a[i]);
            }
            
            suffix_sum[n+1] = 0;
            for(int i=n; i>=1; i--) {
                if(i == n) suffix_sum[i] = a[i];
                else suffix_sum[i] = suffix_sum[i+1] + a[i];
            }
            // cout << "prefix_sum: ";
            // for(int i = 1; i <= n; i++) {
            //     cout << prefix_sum[i] << " ";
            // }
            // cout << endl;
            // cout << "suffix_sum: ";
            // for(int i = 1; i <= n; i++) {
            //     cout << suffix_sum[i] << " ";
            // }
            // cout << endl;
            long long ans = -1e18;
            for(int i = 1; i <= n; i++) {
                // cout << i << " " << prefix_sum[i-1] << " " << suffix_sum[i+1] << " => " << prefix_sum[i-1] - suffix_sum[i+1] << endl;
                ans = max(ans, prefix_sum[i-1] - suffix_sum[i+1]);
            }
            cout << ans << endl;
        }
    
    return 0;
}