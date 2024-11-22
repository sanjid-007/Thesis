#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ai(n + 2); // extra space to avoid index out of bounds
        for (int i = 1; i <= n; ++i) {
            cin >> ai[i];
        }
        ai[0] = -1;       // Sentinel values for boundaries
        ai[n + 1] = -2;

        // Compute initial disturbance
        int D = 0;
        for (int j = 1; j < n; ++j) {
            if (ai[j] == ai[j + 1]) {
                D += 1;
            }
        }

        // Process symmetric pairs
        for (int k = 1; k <= n / 2; ++k) {
            int i = k;
            int j = n - k + 1;

            int D1 = (ai[i] == ai[i - 1]) ? 1 : 0;
            int D2 = (ai[i] == ai[i + 1]) ? 1 : 0;
            int D3 = (ai[j] == ai[j - 1]) ? 1 : 0;
            int D4 = (ai[j] == ai[j + 1]) ? 1 : 0;
            int dist_curr = D1 + D2 + D3 + D4;

            // Temporarily swap ai[i] and ai[j]
            swap(ai[i], ai[j]);

            int D1_prime = (ai[i] == ai[i - 1]) ? 1 : 0;
            int D2_prime = (ai[i] == ai[i + 1]) ? 1 : 0;
            int D3_prime = (ai[j] == ai[j - 1]) ? 1 : 0;
            int D4_prime = (ai[j] == ai[j + 1]) ? 1 : 0;
            int dist_swap = D1_prime + D2_prime + D3_prime + D4_prime;

            int delta = dist_swap - dist_curr;

            if (delta < 0) {
                D += delta; // Keep the swap
            } else {
                swap(ai[i], ai[j]); // Revert the swap
            }
        }

        cout << D << endl;
    }
    return 0;
}
