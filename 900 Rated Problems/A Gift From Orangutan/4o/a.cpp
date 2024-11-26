#include <iostream>
#include <vector>
#include <algorithm>
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

        // Observations:
        // Sorting the array in non-increasing order maximizes the score.
        sort(a.begin(), a.end(), greater<int>());

        int b_min = a[0]; // b array starts with the largest element
        int c_max = a[0]; // c array starts with the largest element
        long long score = 0;

        for (int i = 1; i < n; i++) {
            b_min = min(b_min, a[i]);
            c_max = max(c_max, a[i]);
            score += (c_max - b_min);
        }

        cout << score << endl;
    }
    return 0;
}
