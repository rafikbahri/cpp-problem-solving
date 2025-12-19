#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <iomanip>
using namespace std;
 
// int main() {
//     int t;
//     cin >> t;
//     while (t--){
//         int n, k;
//         cin >> n >> k;
//         if(k%2==1) {
//             for(int i = 0; i < k; i++) {
//                 cout << n << " ";
//             }
//         }
//         else {
//             cout << 0 << " ";
//             for(int i = 1; i < k; i++) {
//                 cout << n << " ";
//             }
//         }
//         cout << endl;
//     }
// }



// int main()
// {
//     std::string binary = std::bitset<8>(6).to_string(); //to binary
//     std::cout<<binary<<"\n";
    
//     unsigned long decimal = std::bitset<8>(binary).to_ulong();
//     std::cout<<decimal<<"\n";
    
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            long long n;
            int k;
            cin >> n >> k;

            if (k % 2 == 1) {
                for (int i = 0; i < k; ++i) {
                    cout << n << (i == k - 1 ? "" : " ");
                }
                cout << "\n";
            } else {
                for (int i = 0; i < k - 2; ++i) {
                    cout << n << " ";
                }

                long long biggest_bit = 1;
                while ((biggest_bit << 1) <= n) biggest_bit <<= 1;

                long long x = biggest_bit;
                long long y = n ^ x;

                for (long long b = biggest_bit >> 1; b > 0; b >>= 1) {
                    if ((n & b) == 0) {
                        if (x + b <= n) {
                            x += b;
                            y += b;
                        }
                    }
                }
                cout << x << " " << y << "\n";
            }
        }
    }
    return 0;
}