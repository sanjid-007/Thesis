#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        unordered_set<long long> prefix_sums;
        long long current_sum = 0;
        int beautiful_segments = 0;
        prefix_sums.insert(0);

        for (int i = 0; i < n; i++) {
            current_sum += a[i];
            if (prefix_sums.count(current_sum)) {
                beautiful_segments++;
                prefix_sums.clear();
                prefix_sums.insert(0);
                current_sum = a[i];
            }
            prefix_sums.insert(current_sum);
        }

        cout << beautiful_segments << endl;
    }
    return 0;
}
