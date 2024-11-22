#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n, k;
        cin >> n >> k;
        long long median_medians = (n + 1) / 2;
        if(k != median_medians) {
            cout << -1 << endl;
            continue;
        }
        cout << n << endl;
        for(int i = 1; i <= n; ++i) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
