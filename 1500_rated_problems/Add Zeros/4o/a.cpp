#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int maxLength = n;
        int currentSize = n;

        // Traverse the array from the end and check the condition
        for (int i = n - 1; i > 0; --i) {
            if (a[i] == currentSize - i) {
                maxLength += i;
                currentSize += i;
            }
        }

        cout << maxLength << "\n";
    }

    return 0;
}
