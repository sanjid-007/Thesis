#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve each test case
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    // Reading the array
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int acts_of_justice = 0; // Count of acts of justice performed

    // We will iterate from right to left to ensure non-decreasing order
    for (int i = n - 2; i >= 0; --i) {
        // If the current element is greater than the next, we need to perform acts of justice
        while (a[i] > a[i + 1]) {
            if (a[i] == 0) {  // If we reduce to 0, it means we can't make it non-decreasing
                cout << -1 << endl;
                return;
            }
            a[i] /= 2; // Perform act of justice (replace with integer division by 2)
            acts_of_justice++;
        }
    }
    cout << acts_of_justice << endl;  // Output the minimum acts of justice for this test case
}

int main() {
    int t;
    cin >> t; // Number of test cases

    // Solve each test case
    while (t--) {
        solve();
    }

    return 0;
}
