#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int m0 = 1001, M = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            m0 = min(m0, a[i]);
            M = max(M, a[i]);
        }
        int S = (n - 1) * (M - m0);
        cout << S << endl;
    }
    return 0;
}
