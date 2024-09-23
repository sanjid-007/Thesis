#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Case where there are only two sections
    if (n == 2) {
        cout << max((a[0] + 1) / 2, (a[1] + 1) / 2) << endl;
        return 0;
    }
    
    // Initialize minimum shots with a large number
    int min_shots = 1e9;
    
    // Strategy 1: Break two adjacent sections
    for (int i = 0; i < n - 1; ++i) {
        // Break two adjacent sections directly
        int case1 = max((a[i] + 1) / 2, (a[i+1] + 1) / 2);
        // Considering shooting both sections equally
        int case2 = (a[i] + a[i+1] + 2) / 3;
        min_shots = min(min_shots, min(case1, case2));
    }
    
    // Strategy 2: Consider shooting a middle section that spreads damage
    for (int i = 1; i < n - 1; ++i) {
        int case3 = (a[i-1] + a[i+1] + 1) / 2;
        min_shots = min(min_shots, case3);
    }
    
    // Output the minimum number of shots calculated
    cout << min_shots << endl;

    return 0;
}
