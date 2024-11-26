#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate minimum operations to make the heights non-decreasing
int minimum_operations(vector<int>& h) {
    int n = h.size();
    int operations = 0;
    vector<int> prefixMax(n, 0);

    // Prefix maximum array to track the required height at each position
    prefixMax[0] = h[0];
    for (int i = 1; i < n; ++i) {
        prefixMax[i] = max(prefixMax[i - 1], h[i]);
    }

    // Count the operations needed
    for (int i = 0; i < n; ++i) {
        operations += (prefixMax[i] - h[i]);
    }

    return operations;
}

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Number of pillars
        vector<int> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }

        // Output the minimum operations for each test case
        cout << minimum_operations(h) << endl;
    }
    return 0;
}
