#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // For memset
using namespace std;

// Define the maximum size based on constraints
const int MAX_N = 200005;

int BIT[MAX_N]; // Binary Indexed Tree

// Function to update the BIT
void update(int index, int value, int n) {
    while (index <= n) {
        BIT[index] += value;
        index += index & (-index);
    }
}

// Function to query the prefix sum up to index
int query(int index) {
    int sum = 0;
    while (index > 0) {
        sum += BIT[index];
        index -= index & (-index);
    }
    return sum;
}

void solve() {
    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1); // 1-based indexing
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }

        // Initialize BIT with zeros
        memset(BIT, 0, sizeof(int) * (n + 2));

        long long total_inversions = 0;
        long long resolvable_inversions = 0;

        // Compute total inversions
        for (int i = n; i >= 1; --i) {
            total_inversions += query(p[i] - 1);
            update(p[i], 1, n);
        }

        // Compute resolvable inversions
        for (int i = 1; i < n; ++i) {
            if (p[i] > p[i + 1] && p[i] - p[i + 1] == 1) {
                resolvable_inversions++;
            }
        }

        if (total_inversions == resolvable_inversions) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
