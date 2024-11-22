#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    // Total number of elements across all test cases should not exceed 3e5
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a)
            cin >> x;
        unordered_set<long long> sums;
        sums.insert(0);
        long long sum = 0;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            if (sums.find(sum) != sums.end()) {
                // Found a zero-sum segment
                count++;
                // Reset for the next segment
                sums.clear();
                sums.insert(0);
                sum = 0;
            } else {
                sums.insert(sum);
            }
        }
        cout << count << '\n';
    }
    return 0;
}
